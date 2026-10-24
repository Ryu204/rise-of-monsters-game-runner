find_package(
    rise-of-monsters-simulation
    REQUIRED
    VERSION 0.1
)

set(
    SOURCE_FILES
    include/rise_of_monsters_game_runner/cmd_args.hpp
    include/rise_of_monsters_game_runner/error.hpp
    include/rise_of_monsters_game_runner/socket.hpp
    src/cmd_args.cpp
    src/error.cpp
    src/socket.cpp
)

add_library(rise-of-monsters-game-runner-lib ${SOURCE_FILES})

target_include_directories(
    rise-of-monsters-game-runner-lib
    PUBLIC
    include
)

set(SOCKPP_BUILD_SHARED off)
set(SOCKPP_BUILD_STATIC on)
add_subdirectory(../extern/sockpp ${CMAKE_CURRENT_BINARY_DIR}/extern/sockpp)

target_link_libraries(
    rise-of-monsters-game-runner-lib
    PRIVATE
    rise-of-monsters-simulation
    sockpp-static
)
