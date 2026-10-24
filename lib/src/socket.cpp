#include "rise_of_monsters_game_runner/socket.hpp"
#include "rise_of_monsters_game_runner/error.hpp"
#include "sockpp/inet_address.h"
#include "sockpp/tcp_socket.h"

#include <limits>
#include <sockpp/tcp_connector.h>

#include <cstddef>
#include <expected>
#include <format>

namespace romgr {

class socket::Impl final {
public:
  bool try_open(std::string_view address, std::size_t port) {
    connector.close();

    if (port > std::numeric_limits<in_port_t>::max()) {
      std::cerr << "Invalid port number " << port << '\n';
      return false;
    }

    const sockpp::inet_address addr{
        std::string{address},
        static_cast<in_port_t>(port),
    };
    if (!connector.connect(addr)) {
      std::cerr << "Cannot connect to " << addr << '\n'
                << connector.last_error_str() << '\n';
      return false;
    }

    return true;
  }

  ~Impl() { connector.close(); }

private:
  sockpp::tcp_connector connector;
};

std::expected<socket, error> socket::open(std::string_view address,
                                          std::size_t port) {
  socket result;
  if (!result.try_open(address, port)) {
    return std::unexpected<error>(
        std::format("Failed to open socket: {}:{}", address, port));
  }
  return result;
}

bool socket::try_open(std::string_view address, std::size_t port) {
  return p_impl->try_open(address, port);
}

socket::socket() : p_impl{new Impl} {}
socket::~socket() {
  if (p_impl)
    delete p_impl;
}
socket::socket(socket &&other) {
  if (other.p_impl) {
    p_impl = other.p_impl;
    other.p_impl = nullptr;
  }
}
socket &socket::operator=(socket &&other) {
  auto *new_p = other.p_impl;
  other.p_impl = nullptr;
  p_impl = new_p;
  return *this;
}
} // namespace romgr