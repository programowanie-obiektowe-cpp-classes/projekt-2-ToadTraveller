cmake_minimum_required(VERSION 3.10)

project(Advent7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(Advent7 main.cpp data_read.cpp)

target_compile_options(Advent7 PRIVATE -Wall -Wextra -Wpedantic)