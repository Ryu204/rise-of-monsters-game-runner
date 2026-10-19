find_package(
    rise-of-monsters-simulation
    REQUIRED
    VERSION 0.1
)

set(
    SOURCE_FILES
    include/rise_of_monsters_game_runner.hpp
    include/rise_of_monsters_game_runner/multiply.hpp
    src/multiply.cpp
)

add_library(rise-of-monsters-game-runner-lib ${SOURCE_FILES})

target_include_directories(
    rise-of-monsters-game-runner-lib
    PUBLIC
    include
)
target_link_libraries(rise-of-monsters-game-runner-lib PRIVATE rise-of-monsters-simulation)
