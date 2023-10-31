cmake_minimum_required(VERSION 3.0.0)
project(UNO++ VERSION 0.1.0)


# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)


file(GLOB SOURCES "src/*.cpp")

file(GLOB HEADERS "include/*.h"
                  "src/utils/*.h")

set(UNOSOURCES
    src/Deck.cpp
    src/game.cpp
    src/helpers.cpp
    src/player.cpp
    src/main.cpp
    src/cardOps.cpp
    src/gameOps.cpp
)
# add_compile_options()

add_executable(UNO++ ${UNOSOURCES})
