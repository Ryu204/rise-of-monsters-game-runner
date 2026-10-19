#include "rise_of_monsters_game_runner/multiply.hpp"
#include <rise_of_monsters_simulation/adder.hpp>

namespace roms {

int multiply(int a, int b) { return a * b; }

int consume() { return add(1, 4); }

} // namespace roms