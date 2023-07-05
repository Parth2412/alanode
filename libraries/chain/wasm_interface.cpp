#include <alaio/chain/webassembly/interface.hpp>
#include <alaio/chain/webassembly/ala-vm.hpp>
#include <alaio/chain/wasm_interface.hpp>
#include <alaio/chain/apply_context.hpp>
#include <alaio/chain/controller.hpp>
#include <alaio/chain/transaction_context.hpp>
#include <alaio/chain/producer_schedule.hpp>
#include <alaio/chain/exceptions.hpp>
#include <boost/core/ignore_unused.hpp>
#include <alaio/chain/authorization_manager.hpp>
#include <alaio/chain/resource_limits.hpp>
#include <alaio/chain/wasm_interface_private.hpp>
#include <alaio/chain/wasm_alaio_validation.hpp>
#include <alaio/chain/wasm_alaio_injection.hpp>
#include <alaio/chain/global_property_object.hpp>
#include <alaio/chain/protocol_state_object.hpp>
#include <alaio/chain/account_object.hpp>
#include <fc/exception/exception.hpp>
#include <fc/crypto/sha256.hpp>
#include <fc/crypto/sha1.hpp>
#include <fc/io/raw.hpp>

#include <softfloat.hpp>
#include <compiler_builtins.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <fstream>
#include <string.h>

#if defined(ALAIO_ALA_VM_RUNTIME_ENABLED) || defined(ALAIO_ALA_VM_JIT_RUNTIME_ENABLED)
#include <alaio/vm/allocator.hpp>
#endif

namespace alaio { namespace chain {

   wasm_interface::wasm_interface(vm_type vm, bool alavmoc_tierup, const chainbase::database& d, const boost::filesystem::path data_dir, const alavmoc::config& alavmoc_config, bool profile)
     : my( new wasm_interface_impl(vm, alavmoc_tierup, d, data_dir, alavmoc_config, profile) ) {}

   wasm_interface::~wasm_interface() {}

   void wasm_interface::validate(const controller& control, const bytes& code) {
      const auto& pso = control.db().get<protocol_state_object>();

      if (control.is_builtin_activated(builtin_protocol_feature_t::configurable_wasm_limits)) {
         const auto& gpo = control.get_global_properties();
         webassembly::ala_vm_runtime::validate( code, gpo.wasm_configuration, pso.whitelisted_intrinsics );
         return;
      }
      Module module;
      try {
         Serialization::MemoryInputStream stream((U8*)code.data(), code.size());
         WASM::serialize(stream, module);
      } catch(const Serialization::FatalSerializationException& e) {
         ALA_ASSERT(false, wasm_serialization_error, e.message.c_str());
      } catch(const IR::ValidationException& e) {
         ALA_ASSERT(false, wasm_serialization_error, e.message.c_str());
      }

      wasm_validations::wasm_binary_validation validator(control, module);
      validator.validate();

      webassembly::ala_vm_runtime::validate( code, pso.whitelisted_intrinsics );

      //there are a couple opportunties for improvement here--
      //Easy: Cache the Module created here so it can be reused for instantiaion
      //Hard: Kick off instantiation in a separate thread at this location
	 }

   void wasm_interface::indicate_shutting_down() {
      my->is_shutting_down = true;
   }

   void wasm_interface::code_block_num_last_used(const digest_type& code_hash, const uint8_t& vm_type, const uint8_t& vm_version, const uint32_t& block_num) {
      my->code_block_num_last_used(code_hash, vm_type, vm_version, block_num);
   }

   void wasm_interface::current_lib(const uint32_t lib) {
      my->current_lib(lib);
   }

   void wasm_interface::apply( const digest_type& code_hash, const uint8_t& vm_type, const uint8_t& vm_version, apply_context& context ) {
      if(substitute_apply && substitute_apply(code_hash, vm_type, vm_version, context))
         return;
#ifdef ALAIO_ALA_VM_OC_RUNTIME_ENABLED
      if(my->alavmoc) {
         const chain::alavmoc::code_descriptor* cd = nullptr;
         try {
            cd = my->alavmoc->cc.get_descriptor_for_code(code_hash, vm_version);
         }
         catch(...) {
            //swallow errors here, if ALA VM OC has gone in to the weeds we shouldn't bail: continue to try and run baseline
            //In the future, consider moving bits of ALA VM that can fire exceptions and such out of this call path
            static bool once_is_enough;
            if(!once_is_enough)
               elog("ALA VM OC has encountered an unexpected failure");
            once_is_enough = true;
         }
         if(cd) {
            my->alavmoc->exec.execute(*cd, my->alavmoc->mem, context);
            return;
         }
      }
#endif
      my->get_instantiated_module(code_hash, vm_type, vm_version, context.trx_context)->apply(context);
   }

   void wasm_interface::exit() {
      my->runtime_interface->immediately_exit_currently_running_module();
   }

   wasm_instantiated_module_interface::~wasm_instantiated_module_interface() {}
   wasm_runtime_interface::~wasm_runtime_interface() {}

std::istream& operator>>(std::istream& in, wasm_interface::vm_type& runtime) {
   std::string s;
   in >> s;
   if (s == "ala-vm")
      runtime = alaio::chain::wasm_interface::vm_type::ala_vm;
   else if (s == "ala-vm-jit")
      runtime = alaio::chain::wasm_interface::vm_type::ala_vm_jit;
   else if (s == "ala-vm-oc")
      runtime = alaio::chain::wasm_interface::vm_type::ala_vm_oc;
   else
      in.setstate(std::ios_base::failbit);
   return in;
}

} } /// alaio::chain
