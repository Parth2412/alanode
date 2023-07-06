#pragma once

#include <alaio/alaio.hpp>

class [[alaio::contract]] asserter : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action]]
   void procassert( int8_t condition, std::string message );

   [[alaio::action]]
   void provereset();
};
