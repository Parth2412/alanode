#pragma once

#include <alaio/alaio.hpp>

class [[alaio::contract]] ram_restrictions_test : public alaio::contract {
public:
   struct [[alaio::table]] data {
      uint64_t           key;
      std::vector<char>  value;

      uint64_t primary_key() const { return key; }
   };

   typedef alaio::multi_index<"tablea"_n, data> tablea;
   typedef alaio::multi_index<"tableb"_n, data> tableb;

public:
   using alaio::contract::contract;

   [[alaio::action]]
   void noop();

   [[alaio::action]]
   void setdata( uint32_t len1, uint32_t len2, alaio::name payer );

   [[alaio::action]]
   void notifysetdat( alaio::name acctonotify, uint32_t len1, uint32_t len2, alaio::name payer );

   [[alaio::on_notify("tester2::notifysetdat")]]
   void on_notify_setdata( alaio::name acctonotify, uint32_t len1, uint32_t len2, alaio::name payer );

   [[alaio::action]]
   void senddefer( uint64_t senderid, alaio::name payer );

   [[alaio::action]]
   void notifydefer( alaio::name acctonotify, uint64_t senderid, alaio::name payer );

   [[alaio::on_notify("tester2::notifydefer")]]
   void on_notifydefer( alaio::name acctonotify, uint64_t senderid, alaio::name payer );

};
