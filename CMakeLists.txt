cmake_minimum_required(VERSION 3.0.0)
project(UNO++ VERSION 0.1.0)


# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(src/operations)
add_subdirectory(src/game)

add_executable(UNO++ src/main.cpp)
target_link_libraries(UNO++ PUBLIC  UNO_Works UNO_Operations )
