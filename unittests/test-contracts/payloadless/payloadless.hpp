#pragma once

#include <alaio/alaio.hpp>

class [[alaio::contract]] payloadless : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action]]
   void doit();
};
