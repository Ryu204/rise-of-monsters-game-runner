#pragma once

#include <cstddef>
#include <expected>
#include <string_view>
#include <type_traits>

namespace romgr {

class error;
class socket {
public:
  static std::expected<socket, error> open(std::string_view address,
                                           std::size_t port);

  ~socket();
  socket(socket &&other);
  socket(const socket &other) = delete;
  socket &operator=(const socket &other) = delete;
  socket &operator=(socket &&other);

private:
  socket();
  bool try_open(std::string_view address, std::size_t port);

  class Impl;
  Impl *p_impl{};
};

static_assert(std::is_move_constructible_v<socket>);

} // namespace romgr