#include <boost/test/unit_test.hpp>

#include <alaio/chain/exceptions.hpp>
#include <alaio/chain_plugin/chain_plugin.hpp>
#include <alaio_system_tester.hpp>

#include <fc/variant_object.hpp>

#include <fc/log/logger.hpp>


BOOST_AUTO_TEST_SUITE(get_producers_tests)
using namespace alaio::testing;

// this test verifies the exception case of get_producer, where it is populated by the active schedule of producers
BOOST_AUTO_TEST_CASE( get_producers) { try {
      tester chain;

      alaio::chain_apis::read_only plugin(*(chain.control), {}, fc::microseconds::maximum(), fc::microseconds::maximum(), {}, {});
      alaio::chain_apis::read_only::get_producers_params params = { .json = true, .lower_bound = "", .limit = 21 };

      auto results = plugin.get_producers(params, fc::time_point::maximum());
      BOOST_REQUIRE_EQUAL(results.more, "");
      BOOST_REQUIRE_EQUAL(results.rows.size(), 1);
      const auto& row = results.rows[0].get_object();
      BOOST_REQUIRE(row.contains("owner"));
      BOOST_REQUIRE_EQUAL(row["owner"].as_string(), "alaio");
      // check for producer_authority, since it is only set when the producer schedule is used
      BOOST_REQUIRE(row.contains("producer_authority"));


      chain.produce_blocks(2);

      chain.create_accounts( {"dan"_n,"sam"_n,"pam"_n} );
      chain.produce_block();
      chain.set_producers( {"dan"_n,"sam"_n,"pam"_n} );
      chain.produce_blocks(30);

      results = plugin.get_producers(params, fc::time_point::maximum());
      BOOST_REQUIRE_EQUAL(results.rows.size(), 3);
      auto owners = std::vector<std::string>{"dan", "sam", "pam"};
      auto it     = owners.begin();
      for (const auto& elem : results.rows) {
         BOOST_REQUIRE_EQUAL(elem["owner"].as_string(), *it++);
      }
   } FC_LOG_AND_RETHROW() }

// this test verifies the normal case of get_producer, where the contents of the system contract's producers table is used
BOOST_AUTO_TEST_CASE( get_producers_from_table) { try {
      alaio_system::alaio_system_tester chain;

      // ensure that enough voting is occurring so that producer1111 is elected as the producer
      chain.cross_15_percent_threshold();

      alaio::chain_apis::read_only plugin(*(chain.control), {}, fc::microseconds::maximum(), fc::microseconds::maximum(), {}, {});
      alaio::chain_apis::read_only::get_producers_params params = { .json = true, .lower_bound = "", .limit = 21 };

      auto results = plugin.get_producers(params, fc::time_point::maximum());
      BOOST_REQUIRE_EQUAL(results.more, "");
      BOOST_REQUIRE_EQUAL(results.rows.size(), 1);
      const auto& row = results.rows[0].get_object();
      BOOST_REQUIRE(row.contains("owner"));
      BOOST_REQUIRE_EQUAL(row["owner"].as_string(), "producer1111");
      // check for producer_authority not present, since it is only set when the producer schedule is used, this verifies producers table was used
      BOOST_REQUIRE(!row.contains("producer_authority"));

   } FC_LOG_AND_RETHROW() }


BOOST_AUTO_TEST_SUITE_END()