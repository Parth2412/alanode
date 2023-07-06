#pragma once

#include <alaio/alaio.hpp>

using bytes = std::vector<char>;

namespace alaio {
   namespace internal_use_do_not_use {
      extern "C" {
         __attribute__((alaio_wasm_import))
         uint32_t get_block_num(); 
      }
   }
}

class [[alaio::contract]] get_block_num_test : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action]]
   void testblock(uint32_t expected_result);
};
