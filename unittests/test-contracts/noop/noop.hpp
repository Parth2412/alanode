#pragma once

#include <alaio/alaio.hpp>

class [[alaio::contract]] noop : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action]]
   void anyaction( alaio::name                       from,
                   const alaio::ignore<std::string>& type,
                   const alaio::ignore<std::string>& data );
};
