# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bimberiev/Desktop/advent-of-code/6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bimberiev/Desktop/advent-of-code/6/build

# Include any dependencies generated for this target.
include CMakeFiles/Advent6.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Advent6.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Advent6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Advent6.dir/flags.make

CMakeFiles/Advent6.dir/main.cpp.o: CMakeFiles/Advent6.dir/flags.make
CMakeFiles/Advent6.dir/main.cpp.o: ../main.cpp
CMakeFiles/Advent6.dir/main.cpp.o: CMakeFiles/Advent6.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bimberiev/Desktop/advent-of-code/6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Advent6.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Advent6.dir/main.cpp.o -MF CMakeFiles/Advent6.dir/main.cpp.o.d -o CMakeFiles/Advent6.dir/main.cpp.o -c /home/bimberiev/Desktop/advent-of-code/6/main.cpp

CMakeFiles/Advent6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Advent6.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bimberiev/Desktop/advent-of-code/6/main.cpp > CMakeFiles/Advent6.dir/main.cpp.i

CMakeFiles/Advent6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Advent6.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bimberiev/Desktop/advent-of-code/6/main.cpp -o CMakeFiles/Advent6.dir/main.cpp.s

# Object files for target Advent6
Advent6_OBJECTS = \
"CMakeFiles/Advent6.dir/main.cpp.o"

# External object files for target Advent6
Advent6_EXTERNAL_OBJECTS =

Advent6: CMakeFiles/Advent6.dir/main.cpp.o
Advent6: CMakeFiles/Advent6.dir/build.make
Advent6: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
Advent6: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
Advent6: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
Advent6: CMakeFiles/Advent6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bimberiev/Desktop/advent-of-code/6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Advent6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Advent6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Advent6.dir/build: Advent6
.PHONY : CMakeFiles/Advent6.dir/build

CMakeFiles/Advent6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Advent6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Advent6.dir/clean

CMakeFiles/Advent6.dir/depend:
	cd /home/bimberiev/Desktop/advent-of-code/6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bimberiev/Desktop/advent-of-code/6 /home/bimberiev/Desktop/advent-of-code/6 /home/bimberiev/Desktop/advent-of-code/6/build /home/bimberiev/Desktop/advent-of-code/6/build /home/bimberiev/Desktop/advent-of-code/6/build/CMakeFiles/Advent6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Advent6.dir/depend

