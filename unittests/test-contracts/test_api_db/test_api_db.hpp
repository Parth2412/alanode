#pragma once

#include <alaio/alaio.hpp>

class [[alaio::contract]] test_api_db : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action("pg")]]
   void primary_i64_general();

   [[alaio::action("pl")]]
   void primary_i64_lowerbound();

   [[alaio::action("pu")]]
   void primary_i64_upperbound();

   [[alaio::action("s1g")]]
   void idx64_general();

   [[alaio::action("s1l")]]
   void idx64_lowerbound();

   [[alaio::action("s1u")]]
   void idx64_upperbound();

   [[alaio::action("tia")]]
   void test_invalid_access( alaio::name code, uint64_t val, uint32_t index, bool store );

   [[alaio::action("sdnancreate")]]
   void idx_double_nan_create_fail();

   [[alaio::action("sdnanmodify")]]
   void idx_double_nan_modify_fail();

   [[alaio::action("sdnanlookup")]]
   void idx_double_nan_lookup_fail( uint32_t lookup_type );

   [[alaio::action("sk32align")]]
   void misaligned_secondary_key256_tests();

};
