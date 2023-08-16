cmake_minimum_required(VERSION 3.0.0)
project(UNO++ VERSION 0.1.0)

include(CTest)
enable_testing()

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Generate compile_commands.json for cppcheck
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find the threading library
find_package(Threads REQUIRED)

file(GLOB SOURCES "source/*.cpp")
file(GLOB HEADERS "header/*.h")

# add_compile_options()

add_executable(UNO++ ${SOURCES})
# target_link_libraries(UNO++ PRIVATE Threads::Threads)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_program(CPPCHECK cppcheck)  # Find the cppcheck executable

if(CPPCHECK)
    add_custom_target(cppcheck
        COMMAND ${CPPCHECK} --std=c++11 
                            --language=c++
                             --verbose
                            # --enable=warning,style,performance,portability
                            ${SOURCES} ${HEADERS}

        COMMENT "Running cppcheck"
    )
else()
    message(WARNING "cppcheck not found. Custom target cppcheck won't be available.")
endif()
