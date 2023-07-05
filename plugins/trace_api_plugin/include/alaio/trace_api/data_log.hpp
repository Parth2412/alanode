#pragma once
#include <fc/variant.hpp>
#include <alaio/trace_api/trace.hpp>
#include <alaio/chain/abi_def.hpp>
#include <alaio/chain/protocol_feature_activation.hpp>

namespace alaio { namespace trace_api {

   using data_log_entry = std::variant<
      block_trace_v0,
      block_trace_v1,
      block_trace_v2
   >;

}}
