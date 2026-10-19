project(rise-of-monsters-game-runner-test LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY git@github.com:catchorg/Catch2.git
    GIT_TAG v3.16.1
)
set(CATCH_INSTALL_DOCS off)
set(CATCH_INSTALL_EXTRAS off)
FetchContent_MakeAvailable(Catch2)

include(${catch2_SOURCE_DIR}/extras/Catch.cmake)
include(CTest)

function(add_test_executable target source)
    add_executable(${target} ${source})
    target_link_libraries(
        ${target}
        PRIVATE
        Catch2::Catch2WithMain
        rise-of-monsters-game-runner-lib
    )
    catch_discover_tests(${target})
endfunction()

add_test_executable(multiply multiply.test.cpp)
