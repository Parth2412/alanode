#pragma once

#include <alaio/alaio.hpp>

class [[alaio::contract]] integration_test : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action]]
   void store( alaio::name from, alaio::name to, uint64_t num );

   struct [[alaio::table("payloads")]] payload {
      uint64_t              key;
      std::vector<uint64_t> data;

      uint64_t primary_key()const { return key; }

      ALALIB_SERIALIZE( payload, (key)(data) )
   };

   using payloads_table = alaio::multi_index< "payloads"_n,  payload >;

};
