cmake_minimum_required(VERSION 2.8.2)
project(dynamic)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS -pthread)

add_executable(dynamic main.c Dynamic.c Dynamic.h)