#pragma once

#include <alaio/state_history/types.hpp>

namespace alaio {
namespace state_history {

std::vector<table_delta> create_deltas(const chainbase::database& db, bool full_snapshot);

} // namespace state_history
} // namespace alaio
