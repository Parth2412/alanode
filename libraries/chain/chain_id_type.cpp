#include <alaio/chain/chain_id_type.hpp>
#include <alaio/chain/exceptions.hpp>

namespace alaio { namespace chain {

   void chain_id_type::reflector_init()const {
      ALA_ASSERT( *reinterpret_cast<const fc::sha256*>(this) != fc::sha256(), chain_id_type_exception, "chain_id_type cannot be zero" );
   }

} }  // namespace alaio::chain

namespace fc {

   void to_variant(const alaio::chain::chain_id_type& cid, fc::variant& v) {
      to_variant( static_cast<const fc::sha256&>(cid), v);
   }

   void from_variant(const fc::variant& v, alaio::chain::chain_id_type& cid) {
      from_variant( v, static_cast<fc::sha256&>(cid) );
   }

} // fc
