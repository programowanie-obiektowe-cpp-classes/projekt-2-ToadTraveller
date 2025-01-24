cmake_minimum_required(VERSION 3.10)

project(Advent1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Advent1 main.cpp)

add_custom_command(
	TARGET Advent1 POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"${CMAKE_SOURCE_DIR}/input_day1.txt"
		"${CMAKE_BINARY_DIR}/input_day1.txt"


)
