#pragma once

#include <alaio/chain/webassembly/ala-vm-oc/config.hpp>

#include <boost/asio/local/datagram_protocol.hpp>
#include <alaio/chain/webassembly/ala-vm-oc/ipc_helpers.hpp>

namespace alaio { namespace chain { namespace alavmoc {

wrapped_fd get_connection_to_compile_monitor(int cache_fd);

}}}