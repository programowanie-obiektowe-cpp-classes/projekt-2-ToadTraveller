# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1433/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1433/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/denturov/Desktop/advent-of-code/7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denturov/Desktop/advent-of-code/7/build

# Include any dependencies generated for this target.
include CMakeFiles/Advent7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Advent7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Advent7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Advent7.dir/flags.make

CMakeFiles/Advent7.dir/codegen:
.PHONY : CMakeFiles/Advent7.dir/codegen

CMakeFiles/Advent7.dir/main.cpp.o: CMakeFiles/Advent7.dir/flags.make
CMakeFiles/Advent7.dir/main.cpp.o: /home/denturov/Desktop/advent-of-code/7/main.cpp
CMakeFiles/Advent7.dir/main.cpp.o: CMakeFiles/Advent7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/denturov/Desktop/advent-of-code/7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Advent7.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Advent7.dir/main.cpp.o -MF CMakeFiles/Advent7.dir/main.cpp.o.d -o CMakeFiles/Advent7.dir/main.cpp.o -c /home/denturov/Desktop/advent-of-code/7/main.cpp

CMakeFiles/Advent7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Advent7.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denturov/Desktop/advent-of-code/7/main.cpp > CMakeFiles/Advent7.dir/main.cpp.i

CMakeFiles/Advent7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Advent7.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denturov/Desktop/advent-of-code/7/main.cpp -o CMakeFiles/Advent7.dir/main.cpp.s

CMakeFiles/Advent7.dir/data_read.cpp.o: CMakeFiles/Advent7.dir/flags.make
CMakeFiles/Advent7.dir/data_read.cpp.o: /home/denturov/Desktop/advent-of-code/7/data_read.cpp
CMakeFiles/Advent7.dir/data_read.cpp.o: CMakeFiles/Advent7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/denturov/Desktop/advent-of-code/7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Advent7.dir/data_read.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Advent7.dir/data_read.cpp.o -MF CMakeFiles/Advent7.dir/data_read.cpp.o.d -o CMakeFiles/Advent7.dir/data_read.cpp.o -c /home/denturov/Desktop/advent-of-code/7/data_read.cpp

CMakeFiles/Advent7.dir/data_read.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Advent7.dir/data_read.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denturov/Desktop/advent-of-code/7/data_read.cpp > CMakeFiles/Advent7.dir/data_read.cpp.i

CMakeFiles/Advent7.dir/data_read.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Advent7.dir/data_read.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denturov/Desktop/advent-of-code/7/data_read.cpp -o CMakeFiles/Advent7.dir/data_read.cpp.s

# Object files for target Advent7
Advent7_OBJECTS = \
"CMakeFiles/Advent7.dir/main.cpp.o" \
"CMakeFiles/Advent7.dir/data_read.cpp.o"

# External object files for target Advent7
Advent7_EXTERNAL_OBJECTS =

Advent7: CMakeFiles/Advent7.dir/main.cpp.o
Advent7: CMakeFiles/Advent7.dir/data_read.cpp.o
Advent7: CMakeFiles/Advent7.dir/build.make
Advent7: CMakeFiles/Advent7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/denturov/Desktop/advent-of-code/7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Advent7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Advent7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Advent7.dir/build: Advent7
.PHONY : CMakeFiles/Advent7.dir/build

CMakeFiles/Advent7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Advent7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Advent7.dir/clean

CMakeFiles/Advent7.dir/depend:
	cd /home/denturov/Desktop/advent-of-code/7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denturov/Desktop/advent-of-code/7 /home/denturov/Desktop/advent-of-code/7 /home/denturov/Desktop/advent-of-code/7/build /home/denturov/Desktop/advent-of-code/7/build /home/denturov/Desktop/advent-of-code/7/build/CMakeFiles/Advent7.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Advent7.dir/depend

