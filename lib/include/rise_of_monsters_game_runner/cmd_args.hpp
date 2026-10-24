#pragma once

#include <cstddef>
#include <expected>
#include <string_view>

#include "error.hpp"

namespace romgr {

struct cmd_args {
  std::string_view address{};
  std::size_t port{};

  static std::expected<cmd_args, error> parse(int argc, char **argv);
};

} // namespace romgr