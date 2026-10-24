#include "rise_of_monsters_game_runner/error.hpp"
#include <ostream>
#include <string_view>
#include <utility>
#include <variant>

namespace romgr {

error::error() : message{std::string_view{"Unknown error"}} {}
error::error(std::string_view message) : message{message} {}
error::error(std::string message) : message(std::move(message)) {}

std::ostream &operator<<(std::ostream &os, const error &err) {
  std::visit([&os](const auto &message) -> void { os << message; },
             err.message);
  return os;
}

} // namespace romgr
