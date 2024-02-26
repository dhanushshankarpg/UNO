if (UNIX)
    cmake_minimum_required(VERSION 3.22.1)
endif (UNIX)
if (WIN32)
    cmake_minimum_required(VERSION  3.25.0-rc4)
endif (WIN32)

project(UNO++ VERSION 0.1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(src/operations)
add_subdirectory(src/game)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC  UNO_Works UNO_Operations )
