#pragma once

#include <alaio/chain/webassembly/common.hpp>
#include <alaio/chain/webassembly/runtime_interface.hpp>
#include <alaio/chain/exceptions.hpp>
#include <alaio/chain/apply_context.hpp>
#include <alaio/chain/wasm_config.hpp>
#include <alaio/chain/whitelisted_intrinsics.hpp>
#include <softfloat_types.h>

//ala-vm includes
#include <alaio/vm/backend.hpp>
#include <alaio/vm/profile.hpp>

namespace alaio { namespace chain { namespace webassembly { namespace ala_vm_runtime {

struct apply_options;

}}

template <typename Impl>
using ala_vm_backend_t = alaio::vm::backend<ala_vm_host_functions_t, Impl, webassembly::ala_vm_runtime::apply_options, vm::profile_instr_map>;

template <typename Options>
using ala_vm_null_backend_t = alaio::vm::backend<ala_vm_host_functions_t, alaio::vm::null_backend, Options>;

namespace webassembly { namespace ala_vm_runtime {

using namespace fc;
using namespace alaio::vm;

void validate(const bytes& code, const whitelisted_intrinsics_type& intrinsics );

void validate(const bytes& code, const wasm_config& cfg, const whitelisted_intrinsics_type& intrinsics );

struct apply_options;

struct profile_config {
   boost::container::flat_set<name> accounts_to_profile;
};

template<typename Backend>
class ala_vm_runtime : public alaio::chain::wasm_runtime_interface {
   public:
      ala_vm_runtime();
      std::unique_ptr<wasm_instantiated_module_interface> instantiate_module(const char* code_bytes, size_t code_size, std::vector<uint8_t>,
                                                                             const digest_type& code_hash, const uint8_t& vm_type, const uint8_t& vm_version) override;

      void immediately_exit_currently_running_module() override;

   private:
      // todo: managing this will get more complicated with sync calls;
      //       immediately_exit_currently_running_module() should probably
      //       move from wasm_runtime_interface to wasm_instantiated_module_interface.
      ala_vm_backend_t<Backend>* _bkend = nullptr;  // non owning pointer to allow for immediate exit

   template<typename Impl>
   friend class ala_vm_instantiated_module;
};

class ala_vm_profile_runtime : public alaio::chain::wasm_runtime_interface {
   public:
      ala_vm_profile_runtime();
      std::unique_ptr<wasm_instantiated_module_interface> instantiate_module(const char* code_bytes, size_t code_size, std::vector<uint8_t>,
                                                                             const digest_type& code_hash, const uint8_t& vm_type, const uint8_t& vm_version) override;

      void immediately_exit_currently_running_module() override;
};

}}}}// alaio::chain::webassembly::ala_vm_runtime
