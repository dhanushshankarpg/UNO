cmake_minimum_required(VERSION 3.22)
project(UNO LANGUAGES CXX)

add_subdirectory(libs/spdlog)
add_subdirectory(libs/SFML)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries( ${PROJECT_NAME} PRIVATE SFML::Graphics spdlog::spdlog)