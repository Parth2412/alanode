#include <alaio/alaio.hpp>

extern "C" {
   void _type_i32() {
      return;
   }

   void _type_i64() {
      return;
   }

   void _type_f32() {
      return;
   }

   void _type_f64() {
      return;
   }

   int32_t _type_i32_value() {
      return 0;
   }

   int64_t _type_i64_value() {
      return 0;
   }

   float _type_f32_value() {
      return 0.0f;
   }

   double _type_f64_value() {
      return 0.0f;
   }

   int32_t _empty(int32_t) {
      return 0;
   }

   int32_t _empty_value(int32_t) {
      return 0;
   }

   int32_t _singleton(int32_t) {
      return 0;
   }

   int32_t _singleton_value(int32_t) {
      return 0;
   }

   int32_t _multiple(int32_t) {
      return 0;
   }

   int32_t _multiple_value(int32_t) {
      return 0;
   }

   int32_t _large(int32_t) {
      return 0;
   }

   void _as_block_first() {
      return;
   }

   void _as_block_mid() {
      return;
   }

   void _as_block_last() {
      return;
   }

   int32_t _as_block_value() {
      return 0;
   }

   int32_t _as_loop_first() {
      return 0;
   }

   int32_t _as_loop_mid() {
      return 0;
   }

   int32_t _as_loop_last() {
      return 0;
   }

   int32_t _as_br_value() {
      return 0;
   }

   void _as_br_if_cond() {
      return;
   }

   int32_t _as_br_if_value() {
      return 0;
   }

   int32_t _as_br_if_value_cond() {
      return 0;
   }

   void _as_br_table_index() {
      return;
   }

   int32_t _as_br_table_value() {
      return 0;
   }

   int32_t _as_br_table_value_index() {
      return 0;
   }

   int64_t _as_return_value() {
      return 0;
   }

   int32_t _as_if_cond() {
      return 0;
   }

   int32_t _as_if_then(int32_t, int32_t) {
      return 0;
   }

   int32_t _as_if_else(int32_t, int32_t) {
      return 0;
   }

   int32_t _as_select_first(int32_t, int32_t) {
      return 0;
   }

   int32_t _as_select_second(int32_t, int32_t) {
      return 0;
   }

   int32_t _as_select_cond() {
      return 0;
   }

   int32_t _as_call_first() {
      return 0;
   }

   int32_t _as_call_mid() {
      return 0;
   }

   int32_t _as_call_last() {
      return 0;
   }

   int32_t _as_call_indirect_first() {
      return 0;
   }

   int32_t _as_call_indirect_mid() {
      return 0;
   }

   int32_t _as_call_indirect_last() {
      return 0;
   }

   int32_t _as_call_indirect_func() {
      return 0;
   }

   int32_t _as_local_set_value() {
      return 0;
   }

   int32_t _as_local_tee_value() {
      return 0;
   }

   int32_t _as_global_set_value() {
      return 0;
   }

   float _as_load_address() {
      return 0.0f;
   }

   int64_t _as_loadN_address() {
      return 0;
   }

   int32_t _as_store_address() {
      return 0;
   }

   int32_t _as_store_value() {
      return 0;
   }

   int32_t _as_storeN_address() {
      return 0;
   }

   int32_t _as_storeN_value() {
      return 0;
   }

   float _as_unary_operand() {
      return 0.0f;
   }

   int32_t _as_binary_left() {
      return 0;
   }

   int64_t _as_binary_right() {
      return 0;
   }

   int32_t _as_test_operand() {
      return 0;
   }

   int32_t _as_compare_left() {
      return 0;
   }

   int32_t _as_compare_right() {
      return 0;
   }

   int32_t _as_convert_operand() {
      return 0;
   }

   int32_t _as_memory_grow_size() {
      return 0;
   }

   int32_t _nested_block_value(int32_t) {
      return 0;
   }

   int32_t _nested_br_value(int32_t) {
      return 0;
   }

   int32_t _nested_br_if_value(int32_t) {
      return 0;
   }

   int32_t _nested_br_if_value_cond(int32_t) {
      return 0;
   }

   int32_t _nested_br_table_value(int32_t) {
      return 0;
   }

   int32_t _nested_br_table_value_index(int32_t) {
      return 0;
   }

   int32_t _nested_br_table_loop_block(int32_t) {
      return 0;
   }

   void sub_apply_0() {
      _type_i32();

      _type_i64();

      _type_f32();

      _type_f64();

      int32_t x5 = _type_i32_value();
      alaio::check(x5 == (int32_t)1, "_type_i32_value fail 5");

      int64_t x6 = _type_i64_value();
      alaio::check(x6 == (int64_t)2, "_type_i64_value fail 6");

      float x7 = _type_f32_value();
      alaio::check(*(uint32_t*)&x7 == (float)1077936128, "_type_f32_value fail 7");

      double x8 = _type_f64_value();
      alaio::check(*(uint64_t*)&x8 == (double)4616189618054758400, "_type_f64_value fail 8");

      int32_t x9 = _empty((int32_t)0);
      alaio::check(x9 == (int32_t)22, "_empty fail 9");

      int32_t x10 = _empty((int32_t)1);
      alaio::check(x10 == (int32_t)22, "_empty fail 10");

      int32_t x11 = _empty((int32_t)11);
      alaio::check(x11 == (int32_t)22, "_empty fail 11");

      int32_t x12 = _empty((int32_t)4294967295);
      alaio::check(x12 == (int32_t)22, "_empty fail 12");

      int32_t x13 = _empty((int32_t)4294967196);
      alaio::check(x13 == (int32_t)22, "_empty fail 13");

      int32_t x14 = _empty((int32_t)4294967295);
      alaio::check(x14 == (int32_t)22, "_empty fail 14");

      int32_t x15 = _empty_value((int32_t)0);
      alaio::check(x15 == (int32_t)33, "_empty_value fail 15");

      int32_t x16 = _empty_value((int32_t)1);
      alaio::check(x16 == (int32_t)33, "_empty_value fail 16");

      int32_t x17 = _empty_value((int32_t)11);
      alaio::check(x17 == (int32_t)33, "_empty_value fail 17");

      int32_t x18 = _empty_value((int32_t)4294967295);
      alaio::check(x18 == (int32_t)33, "_empty_value fail 18");

      int32_t x19 = _empty_value((int32_t)4294967196);
      alaio::check(x19 == (int32_t)33, "_empty_value fail 19");

      int32_t x20 = _empty_value((int32_t)4294967295);
      alaio::check(x20 == (int32_t)33, "_empty_value fail 20");

      int32_t x21 = _singleton((int32_t)0);
      alaio::check(x21 == (int32_t)22, "_singleton fail 21");

      int32_t x22 = _singleton((int32_t)1);
      alaio::check(x22 == (int32_t)20, "_singleton fail 22");

      int32_t x23 = _singleton((int32_t)11);
      alaio::check(x23 == (int32_t)20, "_singleton fail 23");

      int32_t x24 = _singleton((int32_t)4294967295);
      alaio::check(x24 == (int32_t)20, "_singleton fail 24");

      int32_t x25 = _singleton((int32_t)4294967196);
      alaio::check(x25 == (int32_t)20, "_singleton fail 25");

      int32_t x26 = _singleton((int32_t)4294967295);
      alaio::check(x26 == (int32_t)20, "_singleton fail 26");

      int32_t x27 = _singleton_value((int32_t)0);
      alaio::check(x27 == (int32_t)32, "_singleton_value fail 27");

      int32_t x28 = _singleton_value((int32_t)1);
      alaio::check(x28 == (int32_t)33, "_singleton_value fail 28");

      int32_t x29 = _singleton_value((int32_t)11);
      alaio::check(x29 == (int32_t)33, "_singleton_value fail 29");

      int32_t x30 = _singleton_value((int32_t)4294967295);
      alaio::check(x30 == (int32_t)33, "_singleton_value fail 30");

      int32_t x31 = _singleton_value((int32_t)4294967196);
      alaio::check(x31 == (int32_t)33, "_singleton_value fail 31");

      int32_t x32 = _singleton_value((int32_t)4294967295);
      alaio::check(x32 == (int32_t)33, "_singleton_value fail 32");

      int32_t x33 = _multiple((int32_t)0);
      alaio::check(x33 == (int32_t)103, "_multiple fail 33");

      int32_t x34 = _multiple((int32_t)1);
      alaio::check(x34 == (int32_t)102, "_multiple fail 34");

      int32_t x35 = _multiple((int32_t)2);
      alaio::check(x35 == (int32_t)101, "_multiple fail 35");

      int32_t x36 = _multiple((int32_t)3);
      alaio::check(x36 == (int32_t)100, "_multiple fail 36");

      int32_t x37 = _multiple((int32_t)4);
      alaio::check(x37 == (int32_t)104, "_multiple fail 37");

      int32_t x38 = _multiple((int32_t)5);
      alaio::check(x38 == (int32_t)104, "_multiple fail 38");

      int32_t x39 = _multiple((int32_t)6);
      alaio::check(x39 == (int32_t)104, "_multiple fail 39");

      int32_t x40 = _multiple((int32_t)10);
      alaio::check(x40 == (int32_t)104, "_multiple fail 40");

      int32_t x41 = _multiple((int32_t)4294967295);
      alaio::check(x41 == (int32_t)104, "_multiple fail 41");

      int32_t x42 = _multiple((int32_t)4294967295);
      alaio::check(x42 == (int32_t)104, "_multiple fail 42");

      int32_t x43 = _multiple_value((int32_t)0);
      alaio::check(x43 == (int32_t)213, "_multiple_value fail 43");

      int32_t x44 = _multiple_value((int32_t)1);
      alaio::check(x44 == (int32_t)212, "_multiple_value fail 44");

      int32_t x45 = _multiple_value((int32_t)2);
      alaio::check(x45 == (int32_t)211, "_multiple_value fail 45");

      int32_t x46 = _multiple_value((int32_t)3);
      alaio::check(x46 == (int32_t)210, "_multiple_value fail 46");

      int32_t x47 = _multiple_value((int32_t)4);
      alaio::check(x47 == (int32_t)214, "_multiple_value fail 47");

      int32_t x48 = _multiple_value((int32_t)5);
      alaio::check(x48 == (int32_t)214, "_multiple_value fail 48");

      int32_t x49 = _multiple_value((int32_t)6);
      alaio::check(x49 == (int32_t)214, "_multiple_value fail 49");

      int32_t x50 = _multiple_value((int32_t)10);
      alaio::check(x50 == (int32_t)214, "_multiple_value fail 50");

      int32_t x51 = _multiple_value((int32_t)4294967295);
      alaio::check(x51 == (int32_t)214, "_multiple_value fail 51");

      int32_t x52 = _multiple_value((int32_t)4294967295);
      alaio::check(x52 == (int32_t)214, "_multiple_value fail 52");

      int32_t x53 = _large((int32_t)0);
      alaio::check(x53 == (int32_t)0, "_large fail 53");

      int32_t x54 = _large((int32_t)1);
      alaio::check(x54 == (int32_t)1, "_large fail 54");

      int32_t x55 = _large((int32_t)100);
      alaio::check(x55 == (int32_t)0, "_large fail 55");

      int32_t x56 = _large((int32_t)101);
      alaio::check(x56 == (int32_t)1, "_large fail 56");

      int32_t x57 = _large((int32_t)1000);
      alaio::check(x57 == (int32_t)0, "_large fail 57");

      int32_t x58 = _large((int32_t)1001);
      alaio::check(x58 == (int32_t)1, "_large fail 58");

      int32_t x59 = _large((int32_t)4096);
      alaio::check(x59 == (int32_t)0, "_large fail 59");

      int32_t x60 = _large((int32_t)4097);
      alaio::check(x60 == (int32_t)1, "_large fail 60");

      _as_block_first();

      _as_block_mid();

      _as_block_last();

      int32_t x64 = _as_block_value();
      alaio::check(x64 == (int32_t)2, "_as_block_value fail 64");

      int32_t x65 = _as_loop_first();
      alaio::check(x65 == (int32_t)3, "_as_loop_first fail 65");

      int32_t x66 = _as_loop_mid();
      alaio::check(x66 == (int32_t)4, "_as_loop_mid fail 66");

      int32_t x67 = _as_loop_last();
      alaio::check(x67 == (int32_t)5, "_as_loop_last fail 67");

      int32_t x68 = _as_br_value();
      alaio::check(x68 == (int32_t)9, "_as_br_value fail 68");

      _as_br_if_cond();

      int32_t x70 = _as_br_if_value();
      alaio::check(x70 == (int32_t)8, "_as_br_if_value fail 70");

      int32_t x71 = _as_br_if_value_cond();
      alaio::check(x71 == (int32_t)9, "_as_br_if_value_cond fail 71");

      _as_br_table_index();

      int32_t x73 = _as_br_table_value();
      alaio::check(x73 == (int32_t)10, "_as_br_table_value fail 73");

      int32_t x74 = _as_br_table_value_index();
      alaio::check(x74 == (int32_t)11, "_as_br_table_value_index fail 74");

      int64_t x75 = _as_return_value();
      alaio::check(x75 == (int64_t)7, "_as_return_value fail 75");

      int32_t x76 = _as_if_cond();
      alaio::check(x76 == (int32_t)2, "_as_if_cond fail 76");

      int32_t x77 = _as_if_then((int32_t) 1, (int32_t)6);
      alaio::check(x77 == (int32_t)3, "_as_if_then fail 77");

      int32_t x78 = _as_if_then((int32_t) 0, (int32_t)6);
      alaio::check(x78 == (int32_t)6, "_as_if_then fail 78");

      int32_t x79 = _as_if_else((int32_t) 0, (int32_t)6);
      alaio::check(x79 == (int32_t)4, "_as_if_else fail 79");

      int32_t x80 = _as_if_else((int32_t) 1, (int32_t)6);
      alaio::check(x80 == (int32_t)6, "_as_if_else fail 80");

      int32_t x81 = _as_select_first((int32_t) 0, (int32_t)6);
      alaio::check(x81 == (int32_t)5, "_as_select_first fail 81");

      int32_t x82 = _as_select_first((int32_t) 1, (int32_t)6);
      alaio::check(x82 == (int32_t)5, "_as_select_first fail 82");

      int32_t x83 = _as_select_second((int32_t) 0, (int32_t)6);
      alaio::check(x83 == (int32_t)6, "_as_select_second fail 83");

      int32_t x84 = _as_select_second((int32_t) 1, (int32_t)6);
      alaio::check(x84 == (int32_t)6, "_as_select_second fail 84");

      int32_t x85 = _as_select_cond();
      alaio::check(x85 == (int32_t)7, "_as_select_cond fail 85");

      int32_t x86 = _as_call_first();
      alaio::check(x86 == (int32_t)12, "_as_call_first fail 86");

      int32_t x87 = _as_call_mid();
      alaio::check(x87 == (int32_t)13, "_as_call_mid fail 87");

      int32_t x88 = _as_call_last();
      alaio::check(x88 == (int32_t)14, "_as_call_last fail 88");

      int32_t x89 = _as_call_indirect_first();
      alaio::check(x89 == (int32_t)20, "_as_call_indirect_first fail 89");

      int32_t x90 = _as_call_indirect_mid();
      alaio::check(x90 == (int32_t)21, "_as_call_indirect_mid fail 90");

      int32_t x91 = _as_call_indirect_last();
      alaio::check(x91 == (int32_t)22, "_as_call_indirect_last fail 91");

      int32_t x92 = _as_call_indirect_func();
      alaio::check(x92 == (int32_t)23, "_as_call_indirect_func fail 92");

      int32_t x93 = _as_local_set_value();
      alaio::check(x93 == (int32_t)17, "_as_local_set_value fail 93");

      int32_t x94 = _as_local_tee_value();
      alaio::check(x94 == (int32_t)1, "_as_local_tee_value fail 94");

      int32_t x95 = _as_global_set_value();
      alaio::check(x95 == (int32_t)1, "_as_global_set_value fail 95");

      float x96 = _as_load_address();
      alaio::check(*(uint32_t*)&x96 == (float)1071225242, "_as_load_address fail 96");

      int64_t x97 = _as_loadN_address();
      alaio::check(x97 == (int64_t)30, "_as_loadN_address fail 97");

      int32_t x98 = _as_store_address();
      alaio::check(x98 == (int32_t)30, "_as_store_address fail 98");

      int32_t x99 = _as_store_value();
      alaio::check(x99 == (int32_t)31, "_as_store_value fail 99");

      int32_t x100 = _as_storeN_address();
      alaio::check(x100 == (int32_t)32, "_as_storeN_address fail 100");

   }
   void sub_apply_1() {
      int32_t x101 = _as_storeN_value();
      alaio::check(x101 == (int32_t)33, "_as_storeN_value fail 101");

      float x102 = _as_unary_operand();
      alaio::check(*(uint32_t*)&x102 == (float)1079613850, "_as_unary_operand fail 102");

      int32_t x103 = _as_binary_left();
      alaio::check(x103 == (int32_t)3, "_as_binary_left fail 103");

      int64_t x104 = _as_binary_right();
      alaio::check(x104 == (int64_t)45, "_as_binary_right fail 104");

      int32_t x105 = _as_test_operand();
      alaio::check(x105 == (int32_t)44, "_as_test_operand fail 105");

      int32_t x106 = _as_compare_left();
      alaio::check(x106 == (int32_t)43, "_as_compare_left fail 106");

      int32_t x107 = _as_compare_right();
      alaio::check(x107 == (int32_t)42, "_as_compare_right fail 107");

      int32_t x108 = _as_convert_operand();
      alaio::check(x108 == (int32_t)41, "_as_convert_operand fail 108");

      int32_t x109 = _as_memory_grow_size();
      alaio::check(x109 == (int32_t)40, "_as_memory_grow_size fail 109");

      int32_t x110 = _nested_block_value((int32_t)0);
      alaio::check(x110 == (int32_t)19, "_nested_block_value fail 110");

      int32_t x111 = _nested_block_value((int32_t)1);
      alaio::check(x111 == (int32_t)17, "_nested_block_value fail 111");

      int32_t x112 = _nested_block_value((int32_t)2);
      alaio::check(x112 == (int32_t)16, "_nested_block_value fail 112");

      int32_t x113 = _nested_block_value((int32_t)10);
      alaio::check(x113 == (int32_t)16, "_nested_block_value fail 113");

      int32_t x114 = _nested_block_value((int32_t)4294967295);
      alaio::check(x114 == (int32_t)16, "_nested_block_value fail 114");

      int32_t x115 = _nested_block_value((int32_t)100000);
      alaio::check(x115 == (int32_t)16, "_nested_block_value fail 115");

      int32_t x116 = _nested_br_value((int32_t)0);
      alaio::check(x116 == (int32_t)8, "_nested_br_value fail 116");

      int32_t x117 = _nested_br_value((int32_t)1);
      alaio::check(x117 == (int32_t)9, "_nested_br_value fail 117");

      int32_t x118 = _nested_br_value((int32_t)2);
      alaio::check(x118 == (int32_t)17, "_nested_br_value fail 118");

      int32_t x119 = _nested_br_value((int32_t)11);
      alaio::check(x119 == (int32_t)17, "_nested_br_value fail 119");

      int32_t x120 = _nested_br_value((int32_t)4294967292);
      alaio::check(x120 == (int32_t)17, "_nested_br_value fail 120");

      int32_t x121 = _nested_br_value((int32_t)10213210);
      alaio::check(x121 == (int32_t)17, "_nested_br_value fail 121");

      int32_t x122 = _nested_br_if_value((int32_t)0);
      alaio::check(x122 == (int32_t)17, "_nested_br_if_value fail 122");

      int32_t x123 = _nested_br_if_value((int32_t)1);
      alaio::check(x123 == (int32_t)9, "_nested_br_if_value fail 123");

      int32_t x124 = _nested_br_if_value((int32_t)2);
      alaio::check(x124 == (int32_t)8, "_nested_br_if_value fail 124");

      int32_t x125 = _nested_br_if_value((int32_t)9);
      alaio::check(x125 == (int32_t)8, "_nested_br_if_value fail 125");

      int32_t x126 = _nested_br_if_value((int32_t)4294967287);
      alaio::check(x126 == (int32_t)8, "_nested_br_if_value fail 126");

      int32_t x127 = _nested_br_if_value((int32_t)999999);
      alaio::check(x127 == (int32_t)8, "_nested_br_if_value fail 127");

      int32_t x128 = _nested_br_if_value_cond((int32_t)0);
      alaio::check(x128 == (int32_t)9, "_nested_br_if_value_cond fail 128");

      int32_t x129 = _nested_br_if_value_cond((int32_t)1);
      alaio::check(x129 == (int32_t)8, "_nested_br_if_value_cond fail 129");

      int32_t x130 = _nested_br_if_value_cond((int32_t)2);
      alaio::check(x130 == (int32_t)9, "_nested_br_if_value_cond fail 130");

      int32_t x131 = _nested_br_if_value_cond((int32_t)3);
      alaio::check(x131 == (int32_t)9, "_nested_br_if_value_cond fail 131");

      int32_t x132 = _nested_br_if_value_cond((int32_t)4293967296);
      alaio::check(x132 == (int32_t)9, "_nested_br_if_value_cond fail 132");

      int32_t x133 = _nested_br_if_value_cond((int32_t)9423975);
      alaio::check(x133 == (int32_t)9, "_nested_br_if_value_cond fail 133");

      int32_t x134 = _nested_br_table_value((int32_t)0);
      alaio::check(x134 == (int32_t)17, "_nested_br_table_value fail 134");

      int32_t x135 = _nested_br_table_value((int32_t)1);
      alaio::check(x135 == (int32_t)9, "_nested_br_table_value fail 135");

      int32_t x136 = _nested_br_table_value((int32_t)2);
      alaio::check(x136 == (int32_t)8, "_nested_br_table_value fail 136");

      int32_t x137 = _nested_br_table_value((int32_t)9);
      alaio::check(x137 == (int32_t)8, "_nested_br_table_value fail 137");

      int32_t x138 = _nested_br_table_value((int32_t)4294967287);
      alaio::check(x138 == (int32_t)8, "_nested_br_table_value fail 138");

      int32_t x139 = _nested_br_table_value((int32_t)999999);
      alaio::check(x139 == (int32_t)8, "_nested_br_table_value fail 139");

      int32_t x140 = _nested_br_table_value_index((int32_t)0);
      alaio::check(x140 == (int32_t)9, "_nested_br_table_value_index fail 140");

      int32_t x141 = _nested_br_table_value_index((int32_t)1);
      alaio::check(x141 == (int32_t)8, "_nested_br_table_value_index fail 141");

      int32_t x142 = _nested_br_table_value_index((int32_t)2);
      alaio::check(x142 == (int32_t)9, "_nested_br_table_value_index fail 142");

      int32_t x143 = _nested_br_table_value_index((int32_t)3);
      alaio::check(x143 == (int32_t)9, "_nested_br_table_value_index fail 143");

      int32_t x144 = _nested_br_table_value_index((int32_t)4293967296);
      alaio::check(x144 == (int32_t)9, "_nested_br_table_value_index fail 144");

      int32_t x145 = _nested_br_table_value_index((int32_t)9423975);
      alaio::check(x145 == (int32_t)9, "_nested_br_table_value_index fail 145");

      int32_t x146 = _nested_br_table_loop_block((int32_t)1);
      alaio::check(x146 == (int32_t)3, "_nested_br_table_loop_block fail 146");

   }
   void apply(uint64_t, uint64_t, uint64_t test_to_run) {
      volatile uint64_t* r = (uint64_t*)0;
      *r = 0;
      switch(test_to_run) {
         case 0:
            sub_apply_0();
            break;
         case 1:
            sub_apply_1();
            break;
      }
   }
}
