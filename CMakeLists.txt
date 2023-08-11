cmake_minimum_required(VERSION 3.0.0)
project(UNO++ VERSION 0.1.0)

include(CTest)
enable_testing()

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find the threading library
find_package(Threads REQUIRED)

file(GLOB SOURCES "source/*.cpp")

add_executable(UNO++ ${SOURCES})
target_link_libraries(UNO++ PRIVATE Threads::Threads)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
