#include <alaio/alaio.hpp>

#include "test_api.hpp"

void test_types::types_size() {

   alaio_assert( sizeof(int64_t)   ==  8, "int64_t size != 8"   );
   alaio_assert( sizeof(uint64_t)  ==  8, "uint64_t size != 8"  );
   alaio_assert( sizeof(uint32_t)  ==  4, "uint32_t size != 4"  );
   alaio_assert( sizeof(int32_t)   ==  4, "int32_t size != 4"   );
   alaio_assert( sizeof(uint128_t) == 16, "uint128_t size != 16");
   alaio_assert( sizeof(int128_t)  == 16, "int128_t size != 16" );
   alaio_assert( sizeof(uint8_t)   ==  1, "uint8_t size != 1"   );

   alaio_assert( sizeof(alaio::name) ==  8, "name size !=  8");
}

void test_types::char_to_symbol() {

   alaio_assert( alaio::name::char_to_value('1') ==  1, "alaio::char_to_symbol('1') !=  1" );
   alaio_assert( alaio::name::char_to_value('2') ==  2, "alaio::char_to_symbol('2') !=  2" );
   alaio_assert( alaio::name::char_to_value('3') ==  3, "alaio::char_to_symbol('3') !=  3" );
   alaio_assert( alaio::name::char_to_value('4') ==  4, "alaio::char_to_symbol('4') !=  4" );
   alaio_assert( alaio::name::char_to_value('5') ==  5, "alaio::char_to_symbol('5') !=  5" );
   alaio_assert( alaio::name::char_to_value('a') ==  6, "alaio::char_to_symbol('a') !=  6" );
   alaio_assert( alaio::name::char_to_value('b') ==  7, "alaio::char_to_symbol('b') !=  7" );
   alaio_assert( alaio::name::char_to_value('c') ==  8, "alaio::char_to_symbol('c') !=  8" );
   alaio_assert( alaio::name::char_to_value('d') ==  9, "alaio::char_to_symbol('d') !=  9" );
   alaio_assert( alaio::name::char_to_value('e') == 10, "alaio::char_to_symbol('e') != 10" );
   alaio_assert( alaio::name::char_to_value('f') == 11, "alaio::char_to_symbol('f') != 11" );
   alaio_assert( alaio::name::char_to_value('g') == 12, "alaio::char_to_symbol('g') != 12" );
   alaio_assert( alaio::name::char_to_value('h') == 13, "alaio::char_to_symbol('h') != 13" );
   alaio_assert( alaio::name::char_to_value('i') == 14, "alaio::char_to_symbol('i') != 14" );
   alaio_assert( alaio::name::char_to_value('j') == 15, "alaio::char_to_symbol('j') != 15" );
   alaio_assert( alaio::name::char_to_value('k') == 16, "alaio::char_to_symbol('k') != 16" );
   alaio_assert( alaio::name::char_to_value('l') == 17, "alaio::char_to_symbol('l') != 17" );
   alaio_assert( alaio::name::char_to_value('m') == 18, "alaio::char_to_symbol('m') != 18" );
   alaio_assert( alaio::name::char_to_value('n') == 19, "alaio::char_to_symbol('n') != 19" );
   alaio_assert( alaio::name::char_to_value('o') == 20, "alaio::char_to_symbol('o') != 20" );
   alaio_assert( alaio::name::char_to_value('p') == 21, "alaio::char_to_symbol('p') != 21" );
   alaio_assert( alaio::name::char_to_value('q') == 22, "alaio::char_to_symbol('q') != 22" );
   alaio_assert( alaio::name::char_to_value('r') == 23, "alaio::char_to_symbol('r') != 23" );
   alaio_assert( alaio::name::char_to_value('s') == 24, "alaio::char_to_symbol('s') != 24" );
   alaio_assert( alaio::name::char_to_value('t') == 25, "alaio::char_to_symbol('t') != 25" );
   alaio_assert( alaio::name::char_to_value('u') == 26, "alaio::char_to_symbol('u') != 26" );
   alaio_assert( alaio::name::char_to_value('v') == 27, "alaio::char_to_symbol('v') != 27" );
   alaio_assert( alaio::name::char_to_value('w') == 28, "alaio::char_to_symbol('w') != 28" );
   alaio_assert( alaio::name::char_to_value('x') == 29, "alaio::char_to_symbol('x') != 29" );
   alaio_assert( alaio::name::char_to_value('y') == 30, "alaio::char_to_symbol('y') != 30" );
   alaio_assert( alaio::name::char_to_value('z') == 31, "alaio::char_to_symbol('z') != 31" );

   for(unsigned char i = 0; i<255; i++) {
      if( (i >= 'a' && i <= 'z') || (i >= '1' || i <= '5') ) continue;
      alaio_assert( alaio::name::char_to_value((char)i) == 0, "alaio::char_to_symbol() != 0" );
   }
}

void test_types::string_to_name() {
   return;
   alaio_assert( alaio::name("a") == "a"_n, "alaio::string_to_name(a)" );
   alaio_assert( alaio::name("ba") == "ba"_n, "alaio::string_to_name(ba)" );
   alaio_assert( alaio::name("cba") == "cba"_n, "alaio::string_to_name(cba)" );
   alaio_assert( alaio::name("dcba") == "dcba"_n, "alaio::string_to_name(dcba)" );
   alaio_assert( alaio::name("edcba") == "edcba"_n, "alaio::string_to_name(edcba)" );
   alaio_assert( alaio::name("fedcba") == "fedcba"_n, "alaio::string_to_name(fedcba)" );
   alaio_assert( alaio::name("gfedcba") == "gfedcba"_n, "alaio::string_to_name(gfedcba)" );
   alaio_assert( alaio::name("hgfedcba") == "hgfedcba"_n, "alaio::string_to_name(hgfedcba)" );
   alaio_assert( alaio::name("ihgfedcba") == "ihgfedcba"_n, "alaio::string_to_name(ihgfedcba)" );
   alaio_assert( alaio::name("jihgfedcba") == "jihgfedcba"_n, "alaio::string_to_name(jihgfedcba)" );
   alaio_assert( alaio::name("kjihgfedcba") == "kjihgfedcba"_n, "alaio::string_to_name(kjihgfedcba)" );
   alaio_assert( alaio::name("lkjihgfedcba") == "lkjihgfedcba"_n, "alaio::string_to_name(lkjihgfedcba)" );
   alaio_assert( alaio::name("mlkjihgfedcba") == "mlkjihgfedcba"_n, "alaio::string_to_name(mlkjihgfedcba)" );
}
