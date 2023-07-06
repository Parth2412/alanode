#pragma once

#include <alaio/alaio.hpp>

class [[alaio::contract]] get_sender_test : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action]]
   void assertsender( alaio::name expected_sender );
   using assertsender_action = alaio::action_wrapper<"assertsender"_n, &get_sender_test::assertsender>;

   [[alaio::action]]
   void sendinline( alaio::name to, alaio::name expected_sender );

   [[alaio::action]]
   void notify( alaio::name to, alaio::name expected_sender, bool send_inline );

   [[alaio::on_notify("*::notify")]]
   void on_notify( alaio::name to, alaio::name expected_sender, bool send_inline );

};
