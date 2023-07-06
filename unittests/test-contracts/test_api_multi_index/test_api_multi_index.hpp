#pragma once

#include <alaio/alaio.hpp>

class [[alaio::contract]] test_api_multi_index : public alaio::contract {
public:
   using alaio::contract::contract;

   [[alaio::action("s1g")]]
   void idx64_general();

   [[alaio::action("s1store")]]
   void idx64_store_only();

   [[alaio::action("s1check")]]
   void idx64_check_without_storing();

   [[alaio::action("s1findfail1")]]
   void idx64_require_find_fail();

   [[alaio::action("s1findfail2")]]
   void idx64_require_find_fail_with_msg();

   [[alaio::action("s1findfail3")]]
   void idx64_require_find_sk_fail();

   [[alaio::action("s1findfail4")]]
   void idx64_require_find_sk_fail_with_msg();

   [[alaio::action("s1pkend")]]
   void idx64_pk_iterator_exceed_end();

   [[alaio::action("s1skend")]]
   void idx64_sk_iterator_exceed_end();

   [[alaio::action("s1pkbegin")]]
   void idx64_pk_iterator_exceed_begin();

   [[alaio::action("s1skbegin")]]
   void idx64_sk_iterator_exceed_begin();

   [[alaio::action("s1pkref")]]
   void idx64_pass_pk_ref_to_other_table();

   [[alaio::action("s1skref")]]
   void idx64_pass_sk_ref_to_other_table();

   [[alaio::action("s1pkitrto")]]
   void idx64_pass_pk_end_itr_to_iterator_to();

   [[alaio::action("s1pkmodify")]]
   void idx64_pass_pk_end_itr_to_modify();

   [[alaio::action("s1pkerase")]]
   void idx64_pass_pk_end_itr_to_erase();

   [[alaio::action("s1skitrto")]]
   void idx64_pass_sk_end_itr_to_iterator_to();

   [[alaio::action("s1skmodify")]]
   void idx64_pass_sk_end_itr_to_modify();

   [[alaio::action("s1skerase")]]
   void idx64_pass_sk_end_itr_to_erase();

   [[alaio::action("s1modpk")]]
   void idx64_modify_primary_key();

   [[alaio::action("s1exhaustpk")]]
   void idx64_run_out_of_avl_pk();

   [[alaio::action("s1skcache")]]
   void idx64_sk_cache_pk_lookup();

   [[alaio::action("s1pkcache")]]
   void idx64_pk_cache_sk_lookup();

   [[alaio::action("s2g")]]
   void idx128_general();

   [[alaio::action("s2store")]]
   void idx128_store_only();

   [[alaio::action("s2check")]]
   void idx128_check_without_storing();

   [[alaio::action("s2autoinc")]]
   void idx128_autoincrement_test();

   [[alaio::action("s2autoinc1")]]
   void idx128_autoincrement_test_part1();

   [[alaio::action("s2autoinc2")]]
   void idx128_autoincrement_test_part2();

   [[alaio::action("s3g")]]
   void idx256_general();

   [[alaio::action("sdg")]]
   void idx_double_general();

   [[alaio::action("sldg")]]
   void idx_long_double_general();

};
