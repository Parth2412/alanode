#include <alaio/chain/webassembly/interface.hpp>
#include <alaio/chain/apply_context.hpp>

namespace alaio { namespace chain { namespace webassembly {
   inline static constexpr size_t max_assert_message = 1024;
   void interface::abort() const {
      ALA_ASSERT( false, abort_called, "abort() called" );
   }

   void interface::alaio_assert( bool condition, null_terminated_ptr msg ) const {
      if( BOOST_UNLIKELY( !condition ) ) {
         const size_t sz = strnlen( msg.data(), max_assert_message );
         std::string message( msg.data(), sz );
         ALA_THROW( alaio_assert_message_exception, "assertion failure with message: ${s}", ("s",message) );
      }
   }

   void interface::alaio_assert_message( bool condition, legacy_span<const char> msg ) const {
      if( BOOST_UNLIKELY( !condition ) ) {
         const size_t sz = msg.size() > max_assert_message ? max_assert_message : msg.size();
         std::string message( msg.data(), sz );
         ALA_THROW( alaio_assert_message_exception, "assertion failure with message: ${s}", ("s",message) );
      }
   }

   void interface::alaio_assert_code( bool condition, uint64_t error_code ) const {
      if( BOOST_UNLIKELY( !condition ) ) {
         if( error_code >= static_cast<uint64_t>(system_error_code::generic_system_error) ) {
            restricted_error_code_exception e( FC_LOG_MESSAGE(
                                                   error,
                                                   "alaio_assert_code called with reserved error code: ${error_code}",
                                                   ("error_code", error_code)
            ) );
            e.error_code = static_cast<uint64_t>(system_error_code::contract_restricted_error_code);
            throw e;
         } else {
            alaio_assert_code_exception e( FC_LOG_MESSAGE(
                                             error,
                                             "assertion failure with error code: ${error_code}",
                                             ("error_code", error_code)
            ) );
            e.error_code = error_code;
            throw e;
         }
      }
   }

   void interface::alaio_exit( int32_t code ) const {
      context.control.get_wasm_interface().exit();
   }
}}} // ns alaio::chain::webassembly
