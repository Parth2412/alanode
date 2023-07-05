#include <alaio/chain/webassembly/ala-vm-oc.hpp>
#include <alaio/chain/wasm_alaio_constraints.hpp>
#include <alaio/chain/wasm_alaio_injection.hpp>
#include <alaio/chain/apply_context.hpp>
#include <alaio/chain/exceptions.hpp>
#include <alaio/chain/global_property_object.hpp>

#include <vector>
#include <iterator>

namespace alaio { namespace chain { namespace webassembly { namespace alavmoc {

class alavmoc_instantiated_module : public wasm_instantiated_module_interface {
   public:
      alavmoc_instantiated_module(const digest_type& code_hash, const uint8_t& vm_version, alavmoc_runtime& wr) :
         _code_hash(code_hash),
         _vm_version(vm_version),
         _alavmoc_runtime(wr)
      {

      }

      ~alavmoc_instantiated_module() {
         _alavmoc_runtime.cc.free_code(_code_hash, _vm_version);
      }

      void apply(apply_context& context) override {
         const code_descriptor* const cd = _alavmoc_runtime.cc.get_descriptor_for_code_sync(_code_hash, _vm_version);
         ALA_ASSERT(cd, wasm_execution_error, "ALA VM OC instantiation failed");

         _alavmoc_runtime.exec.execute(*cd, _alavmoc_runtime.mem, context);
      }

      const digest_type              _code_hash;
      const uint8_t                  _vm_version;
      alavmoc_runtime&               _alavmoc_runtime;
};

alavmoc_runtime::alavmoc_runtime(const boost::filesystem::path data_dir, const alavmoc::config& alavmoc_config, const chainbase::database& db)
   : cc(data_dir, alavmoc_config, db), exec(cc), mem(wasm_constraints::maximum_linear_memory/wasm_constraints::wasm_page_size) {
}

alavmoc_runtime::~alavmoc_runtime() {
}

std::unique_ptr<wasm_instantiated_module_interface> alavmoc_runtime::instantiate_module(const char* code_bytes, size_t code_size, std::vector<uint8_t> initial_memory,
                                                                                        const digest_type& code_hash, const uint8_t& vm_type, const uint8_t& vm_version) {

   return std::make_unique<alavmoc_instantiated_module>(code_hash, vm_type, *this);
}

//never called. ALA VM OC overrides alaio_exit to its own implementation
void alavmoc_runtime::immediately_exit_currently_running_module() {}

}}}}
