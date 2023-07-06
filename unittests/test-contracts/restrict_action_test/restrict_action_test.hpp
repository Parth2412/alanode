#pragma once

#include <alaio/alaio.hpp>

class [[alaio::contract]] restrict_action_test : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action]]
   void noop( );

   [[alaio::action]]
   void sendinline( alaio::name authorizer );

   [[alaio::action]]
   void senddefer( alaio::name authorizer, uint32_t senderid );


   [[alaio::action]]
   void notifyinline( alaio::name acctonotify, alaio::name authorizer );

   [[alaio::action]]
   void notifydefer( alaio::name acctonotify, alaio::name authorizer, uint32_t senderid );

   [[alaio::on_notify("testacc::notifyinline")]]
   void on_notify_inline( alaio::name acctonotify, alaio::name authorizer );

   [[alaio::on_notify("testacc::notifydefer")]]
   void on_notify_defer( alaio::name acctonotify, alaio::name authorizer, uint32_t senderid );
};
