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
include tests/CMakeFiles/test_name.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_name.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_name.dir/flags.make

tests/CMakeFiles/test_name.dir/test_name.cpp.o: tests/CMakeFiles/test_name.dir/flags.make
tests/CMakeFiles/test_name.dir/test_name.cpp.o: ../tests/test_name.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heyjude/workspace/projects/compete/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_name.dir/test_name.cpp.o"
	cd /home/heyjude/workspace/projects/compete/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_name.dir/test_name.cpp.o -c /home/heyjude/workspace/projects/compete/tests/test_name.cpp

tests/CMakeFiles/test_name.dir/test_name.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_name.dir/test_name.cpp.i"
	cd /home/heyjude/workspace/projects/compete/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heyjude/workspace/projects/compete/tests/test_name.cpp > CMakeFiles/test_name.dir/test_name.cpp.i

tests/CMakeFiles/test_name.dir/test_name.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_name.dir/test_name.cpp.s"
	cd /home/heyjude/workspace/projects/compete/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heyjude/workspace/projects/compete/tests/test_name.cpp -o CMakeFiles/test_name.dir/test_name.cpp.s

tests/CMakeFiles/test_name.dir/serialtest.cpp.o: tests/CMakeFiles/test_name.dir/flags.make
tests/CMakeFiles/test_name.dir/serialtest.cpp.o: ../tests/serialtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heyjude/workspace/projects/compete/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/test_name.dir/serialtest.cpp.o"
	cd /home/heyjude/workspace/projects/compete/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_name.dir/serialtest.cpp.o -c /home/heyjude/workspace/projects/compete/tests/serialtest.cpp

tests/CMakeFiles/test_name.dir/serialtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_name.dir/serialtest.cpp.i"
	cd /home/heyjude/workspace/projects/compete/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heyjude/workspace/projects/compete/tests/serialtest.cpp > CMakeFiles/test_name.dir/serialtest.cpp.i

tests/CMakeFiles/test_name.dir/serialtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_name.dir/serialtest.cpp.s"
	cd /home/heyjude/workspace/projects/compete/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heyjude/workspace/projects/compete/tests/serialtest.cpp -o CMakeFiles/test_name.dir/serialtest.cpp.s

# Object files for target test_name
test_name_OBJECTS = \
"CMakeFiles/test_name.dir/test_name.cpp.o" \
"CMakeFiles/test_name.dir/serialtest.cpp.o"

# External object files for target test_name
test_name_EXTERNAL_OBJECTS =

tests/test_name: tests/CMakeFiles/test_name.dir/test_name.cpp.o
tests/test_name: tests/CMakeFiles/test_name.dir/serialtest.cpp.o
tests/test_name: tests/CMakeFiles/test_name.dir/build.make
tests/test_name: /usr/local/lib/libboost_serialization.so.1.78.0
tests/test_name: tests/CMakeFiles/test_name.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heyjude/workspace/projects/compete/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_name"
	cd /home/heyjude/workspace/projects/compete/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_name.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_name.dir/build: tests/test_name

.PHONY : tests/CMakeFiles/test_name.dir/build

tests/CMakeFiles/test_name.dir/clean:
	cd /home/heyjude/workspace/projects/compete/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_name.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_name.dir/clean

tests/CMakeFiles/test_name.dir/depend:
	cd /home/heyjude/workspace/projects/compete/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heyjude/workspace/projects/compete /home/heyjude/workspace/projects/compete/tests /home/heyjude/workspace/projects/compete/build /home/heyjude/workspace/projects/compete/build/tests /home/heyjude/workspace/projects/compete/build/tests/CMakeFiles/test_name.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_name.dir/depend
