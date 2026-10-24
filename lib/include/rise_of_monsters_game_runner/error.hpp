#pragma once

#include <ostream>
#include <string>
#include <string_view>
#include <variant>

namespace romgr {

class error {
public:
  error(std::string_view message);
  error(std::string message);
  error();

private:
  std::variant<std::string_view, std::string> message;
  friend std::ostream &operator<<(std::ostream &, const error &);
};

std::ostream &operator<<(std::ostream &os, const error &err);

} // namespace romgr