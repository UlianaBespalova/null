cmake_minimum_required(VERSION 2.8.2)
project(program)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++0x -Wall -ggdb3 -pthread")
set(CMAKE_C_FLAGS -pthread)

link_directories(static dynamic)
include_directories(static dynamic)

add_executable(program main.c)
add_executable(unit_tests unit_tests.cpp)

#************************************************************

target_link_libraries(program libDynamic.so Static)
target_link_libraries(unit_tests libDynamic.so Static)

#================================================================
include_directories(${GTEST_INCLUDE_DIRS})

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build")

if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif()
#================================================================

#Link with GoogleTest
target_link_libraries(unit_tests gtest gtest_main)