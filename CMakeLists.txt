cmake_minimum_required(VERSION 3.16)

option(RISE_OF_MONSTERS_GAME_RUNNER_BUILD_TESTS off)

project(rise-of-monsters-game-runner LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

add_subdirectory(lib)

if(RISE_OF_MONSTERS_GAME_RUNNER_BUILD_TESTS)
    add_subdirectory(test)
endif()

set(SOURCE_FILES bin/main.cpp)

add_executable(rise-of-monsters-game-runner ${SOURCE_FILES})

target_link_libraries(
    rise-of-monsters-game-runner
    PRIVATE
    rise-of-monsters-game-runner-lib
)

install(TARGETS rise-of-monsters-game-runner
    EXPORT rise-of-monsters-game-runner
    RUNTIME DESTINATION bin
)
