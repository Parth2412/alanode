#pragma once

#include <alaio/chain/types.hpp>
#include <alaio/chain/webassembly/ala-vm-oc/ala-vm-oc.h>

#include <exception>

#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>

#include <vector>
#include <list>

namespace alaio { namespace chain {

class apply_context;

namespace alavmoc {

using control_block = ala_vm_oc_control_block;

struct no_offset{};
struct code_offset {
   size_t offset; 
};    
struct intrinsic_ordinal { 
   size_t ordinal; 
};

using alavmoc_optional_offset_or_import_t = std::variant<no_offset, code_offset, intrinsic_ordinal>;

struct code_descriptor {
   digest_type code_hash;
   uint8_t vm_version;
   uint8_t codegen_version;
   size_t code_begin;
   alavmoc_optional_offset_or_import_t start;
   unsigned apply_offset;
   int starting_memory_pages;
   size_t initdata_begin;
   unsigned initdata_size;
   unsigned initdata_prologue_size;
};

enum alavmoc_exitcode : int {
   ALAVMOC_EXIT_CLEAN_EXIT = 1,
   ALAVMOC_EXIT_CHECKTIME_FAIL,
   ALAVMOC_EXIT_SEGV,
   ALAVMOC_EXIT_EXCEPTION
};

static constexpr uint8_t current_codegen_version = 1;

}}}

FC_REFLECT(alaio::chain::alavmoc::no_offset, );
FC_REFLECT(alaio::chain::alavmoc::code_offset, (offset));
FC_REFLECT(alaio::chain::alavmoc::intrinsic_ordinal, (ordinal));
FC_REFLECT(alaio::chain::alavmoc::code_descriptor, (code_hash)(vm_version)(codegen_version)(code_begin)(start)(apply_offset)(starting_memory_pages)(initdata_begin)(initdata_size)(initdata_prologue_size));

#define ALAVMOC_INTRINSIC_INIT_PRIORITY __attribute__((init_priority(198)))
