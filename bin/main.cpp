#include "rise_of_monsters_game_runner/cmd_args.hpp"
#include "rise_of_monsters_game_runner/socket.hpp"
#include <iostream>

int main(int argc, char **argv) {
  const auto args = romgr::cmd_args::parse(argc, argv);
  if (!args.has_value()) {
    std::cerr << args.error() << '\n';
    return -1;
  }
  auto maybe_socket = romgr::socket::open(args->address, args->port);
  return 0;
}
