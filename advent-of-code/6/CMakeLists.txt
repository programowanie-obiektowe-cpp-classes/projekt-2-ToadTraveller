cmake_minimum_required(VERSION 3.10)

project(Advent6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable(Advent6 main.cpp)

target_link_libraries(Advent6 sfml-graphics sfml-window sfml-system)
