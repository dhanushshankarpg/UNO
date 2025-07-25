cmake_minimum_required(VERSION 4.1.0)
# Set the C++ standard
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED true)

project(UNO)

add_subdirectory(src/operations)
add_subdirectory(src/game)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC    UNO_Works
                                                UNO_Operations)
