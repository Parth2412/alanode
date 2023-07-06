#pragma once

#include <alaio/alaio.hpp>
#include <vector>

class [[alaio::contract]] deferred_test : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action]]
   void defercall( alaio::name payer, uint64_t sender_id, alaio::name contract, uint64_t payload );

   [[alaio::action]]
   void delayedcall( alaio::name payer, uint64_t sender_id, alaio::name contract,
                     uint64_t payload, uint32_t delay_sec, bool replace_existing );

   [[alaio::action]]
   void deferfunc( uint64_t payload );
   using deferfunc_action = alaio::action_wrapper<"deferfunc"_n, &deferred_test::deferfunc>;

   [[alaio::action]]
   void inlinecall( alaio::name contract, alaio::name authorizer, uint64_t payload );

   [[alaio::action]]
   void fail();

   [[alaio::on_notify("alaio::onerror")]]
   void on_error( uint128_t sender_id, alaio::ignore<std::vector<char>> sent_trx );
};
