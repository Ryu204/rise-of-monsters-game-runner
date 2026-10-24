#include "rise_of_monsters_game_runner/cmd_args.hpp"
#include <cstdlib>
#include <expected>
#include <stdexcept>
#include <string>
#include <string_view>

namespace romgr {

std::expected<cmd_args, error> cmd_args::parse(int argc, char **argv) {
  if (argc < 3) {
    return std::unexpected{
        error{std::string_view{"Missing socket address or port"}},
    };
  }
  if (argc > 3) {
    return std::unexpected{error{std::string_view{"Too many arguments"}}};
  }
  const auto *const input_address = argv[1];
  const auto *const port = argv[2];
  std::size_t parsed_port{};
  try {
    if (const auto result = std::stoi(port); result >= 0) {
      return cmd_args{
          .address = input_address,
          .port = static_cast<std::size_t>(result),
      };
    } else {
      return std::unexpected{error{std::string_view{"Invalid port"}}};
    }
  } catch (std::invalid_argument &e) {
    return std::unexpected{error{std::string_view{e.what()}}};
  }
}
} // namespace romgr