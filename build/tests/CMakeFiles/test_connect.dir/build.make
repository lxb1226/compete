# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/heyjude/workspace/projects/compete

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/heyjude/workspace/projects/compete/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_connect.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_connect.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_connect.dir/flags.make

tests/CMakeFiles/test_connect.dir/test_connect.cpp.o: tests/CMakeFiles/test_connect.dir/flags.make
tests/CMakeFiles/test_connect.dir/test_connect.cpp.o: ../tests/test_connect.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heyjude/workspace/projects/compete/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_connect.dir/test_connect.cpp.o"
	cd /home/heyjude/workspace/projects/compete/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_connect.dir/test_connect.cpp.o -c /home/heyjude/workspace/projects/compete/tests/test_connect.cpp

tests/CMakeFiles/test_connect.dir/test_connect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_connect.dir/test_connect.cpp.i"
	cd /home/heyjude/workspace/projects/compete/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heyjude/workspace/projects/compete/tests/test_connect.cpp > CMakeFiles/test_connect.dir/test_connect.cpp.i

tests/CMakeFiles/test_connect.dir/test_connect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_connect.dir/test_connect.cpp.s"
	cd /home/heyjude/workspace/projects/compete/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heyjude/workspace/projects/compete/tests/test_connect.cpp -o CMakeFiles/test_connect.dir/test_connect.cpp.s

# Object files for target test_connect
test_connect_OBJECTS = \
"CMakeFiles/test_connect.dir/test_connect.cpp.o"

# External object files for target test_connect
test_connect_EXTERNAL_OBJECTS =

tests/test_connect: tests/CMakeFiles/test_connect.dir/test_connect.cpp.o
tests/test_connect: tests/CMakeFiles/test_connect.dir/build.make
tests/test_connect: /usr/local/lib/libhiredis.so
tests/test_connect: /usr/local/lib/libredis++.so
tests/test_connect: tests/CMakeFiles/test_connect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heyjude/workspace/projects/compete/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_connect"
	cd /home/heyjude/workspace/projects/compete/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_connect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_connect.dir/build: tests/test_connect

.PHONY : tests/CMakeFiles/test_connect.dir/build

tests/CMakeFiles/test_connect.dir/clean:
	cd /home/heyjude/workspace/projects/compete/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_connect.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_connect.dir/clean

tests/CMakeFiles/test_connect.dir/depend:
	cd /home/heyjude/workspace/projects/compete/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heyjude/workspace/projects/compete /home/heyjude/workspace/projects/compete/tests /home/heyjude/workspace/projects/compete/build /home/heyjude/workspace/projects/compete/build/tests /home/heyjude/workspace/projects/compete/build/tests/CMakeFiles/test_connect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_connect.dir/depend

