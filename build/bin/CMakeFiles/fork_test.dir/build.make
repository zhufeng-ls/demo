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
CMAKE_SOURCE_DIR = /home/zz/code/demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zz/code/demo/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/fork_test.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/fork_test.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/fork_test.dir/flags.make

bin/CMakeFiles/fork_test.dir/fork/fork_test.cc.o: bin/CMakeFiles/fork_test.dir/flags.make
bin/CMakeFiles/fork_test.dir/fork/fork_test.cc.o: ../samples/fork/fork_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zz/code/demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/fork_test.dir/fork/fork_test.cc.o"
	cd /home/zz/code/demo/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fork_test.dir/fork/fork_test.cc.o -c /home/zz/code/demo/samples/fork/fork_test.cc

bin/CMakeFiles/fork_test.dir/fork/fork_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fork_test.dir/fork/fork_test.cc.i"
	cd /home/zz/code/demo/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zz/code/demo/samples/fork/fork_test.cc > CMakeFiles/fork_test.dir/fork/fork_test.cc.i

bin/CMakeFiles/fork_test.dir/fork/fork_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fork_test.dir/fork/fork_test.cc.s"
	cd /home/zz/code/demo/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zz/code/demo/samples/fork/fork_test.cc -o CMakeFiles/fork_test.dir/fork/fork_test.cc.s

# Object files for target fork_test
fork_test_OBJECTS = \
"CMakeFiles/fork_test.dir/fork/fork_test.cc.o"

# External object files for target fork_test
fork_test_EXTERNAL_OBJECTS =

bin/fork_test: bin/CMakeFiles/fork_test.dir/fork/fork_test.cc.o
bin/fork_test: bin/CMakeFiles/fork_test.dir/build.make
bin/fork_test: bin/CMakeFiles/fork_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zz/code/demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fork_test"
	cd /home/zz/code/demo/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fork_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/fork_test.dir/build: bin/fork_test

.PHONY : bin/CMakeFiles/fork_test.dir/build

bin/CMakeFiles/fork_test.dir/clean:
	cd /home/zz/code/demo/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/fork_test.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/fork_test.dir/clean

bin/CMakeFiles/fork_test.dir/depend:
	cd /home/zz/code/demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zz/code/demo /home/zz/code/demo/samples /home/zz/code/demo/build /home/zz/code/demo/build/bin /home/zz/code/demo/build/bin/CMakeFiles/fork_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/fork_test.dir/depend

