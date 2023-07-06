#pragma once

#include <alaio/alaio.hpp>
#include <alaio/singleton.hpp>
#include <alaio/asset.hpp>

// Extacted from alaio.token contract:
namespace alaio {
   class [[alaio::contract("alaio.token")]] token : public alaio::contract {
   public:
      using alaio::contract::contract;

      [[alaio::action]]
      void transfer( alaio::name        from,
                     alaio::name        to,
                     alaio::asset       quantity,
                     const std::string& memo );
      using transfer_action = alaio::action_wrapper<"transfer"_n, &token::transfer>;
   };
}

// This contract:
class [[alaio::contract]] proxy : public alaio::contract {
public:
   proxy( alaio::name self, alaio::name first_receiver, alaio::datastream<const char*> ds );

   [[alaio::action]]
   void setowner( alaio::name owner, uint32_t delay );

   [[alaio::on_notify("alaio.token::transfer")]]
   void on_transfer( alaio::name        from,
                     alaio::name        to,
                     alaio::asset       quantity,
                     const std::string& memo );

   [[alaio::on_notify("alaio::onerror")]]
   void on_error( uint128_t sender_id, alaio::ignore<std::vector<char>> sent_trx );

   struct [[alaio::table]] config {
      alaio::name owner;
      uint32_t    delay   = 0;
      uint32_t    next_id = 0;

      ALALIB_SERIALIZE( config, (owner)(delay)(next_id) )
   };

   using config_singleton = alaio::singleton< "config"_n,  config >;

protected:
   config_singleton _config;
};
