# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/moonnz/Téléchargements/clion-2018.1.6/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/moonnz/Téléchargements/clion-2018.1.6/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/CLionProjects/ThreadTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/CLionProjects/ThreadTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ThreadTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ThreadTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ThreadTest.dir/flags.make

CMakeFiles/ThreadTest.dir/main.cpp.o: CMakeFiles/ThreadTest.dir/flags.make
CMakeFiles/ThreadTest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/ThreadTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ThreadTest.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ThreadTest.dir/main.cpp.o -c /root/CLionProjects/ThreadTest/main.cpp

CMakeFiles/ThreadTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadTest.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/ThreadTest/main.cpp > CMakeFiles/ThreadTest.dir/main.cpp.i

CMakeFiles/ThreadTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadTest.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/ThreadTest/main.cpp -o CMakeFiles/ThreadTest.dir/main.cpp.s

CMakeFiles/ThreadTest.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ThreadTest.dir/main.cpp.o.requires

CMakeFiles/ThreadTest.dir/main.cpp.o.provides: CMakeFiles/ThreadTest.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ThreadTest.dir/build.make CMakeFiles/ThreadTest.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ThreadTest.dir/main.cpp.o.provides

CMakeFiles/ThreadTest.dir/main.cpp.o.provides.build: CMakeFiles/ThreadTest.dir/main.cpp.o


CMakeFiles/ThreadTest.dir/web_serv.cpp.o: CMakeFiles/ThreadTest.dir/flags.make
CMakeFiles/ThreadTest.dir/web_serv.cpp.o: ../web_serv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/CLionProjects/ThreadTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ThreadTest.dir/web_serv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ThreadTest.dir/web_serv.cpp.o -c /root/CLionProjects/ThreadTest/web_serv.cpp

CMakeFiles/ThreadTest.dir/web_serv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadTest.dir/web_serv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/CLionProjects/ThreadTest/web_serv.cpp > CMakeFiles/ThreadTest.dir/web_serv.cpp.i

CMakeFiles/ThreadTest.dir/web_serv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadTest.dir/web_serv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/CLionProjects/ThreadTest/web_serv.cpp -o CMakeFiles/ThreadTest.dir/web_serv.cpp.s

CMakeFiles/ThreadTest.dir/web_serv.cpp.o.requires:

.PHONY : CMakeFiles/ThreadTest.dir/web_serv.cpp.o.requires

CMakeFiles/ThreadTest.dir/web_serv.cpp.o.provides: CMakeFiles/ThreadTest.dir/web_serv.cpp.o.requires
	$(MAKE) -f CMakeFiles/ThreadTest.dir/build.make CMakeFiles/ThreadTest.dir/web_serv.cpp.o.provides.build
.PHONY : CMakeFiles/ThreadTest.dir/web_serv.cpp.o.provides

CMakeFiles/ThreadTest.dir/web_serv.cpp.o.provides.build: CMakeFiles/ThreadTest.dir/web_serv.cpp.o


# Object files for target ThreadTest
ThreadTest_OBJECTS = \
"CMakeFiles/ThreadTest.dir/main.cpp.o" \
"CMakeFiles/ThreadTest.dir/web_serv.cpp.o"

# External object files for target ThreadTest
ThreadTest_EXTERNAL_OBJECTS =

ThreadTest: CMakeFiles/ThreadTest.dir/main.cpp.o
ThreadTest: CMakeFiles/ThreadTest.dir/web_serv.cpp.o
ThreadTest: CMakeFiles/ThreadTest.dir/build.make
ThreadTest: CMakeFiles/ThreadTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/CLionProjects/ThreadTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ThreadTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ThreadTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ThreadTest.dir/build: ThreadTest

.PHONY : CMakeFiles/ThreadTest.dir/build

CMakeFiles/ThreadTest.dir/requires: CMakeFiles/ThreadTest.dir/main.cpp.o.requires
CMakeFiles/ThreadTest.dir/requires: CMakeFiles/ThreadTest.dir/web_serv.cpp.o.requires

.PHONY : CMakeFiles/ThreadTest.dir/requires

CMakeFiles/ThreadTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ThreadTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ThreadTest.dir/clean

CMakeFiles/ThreadTest.dir/depend:
	cd /root/CLionProjects/ThreadTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/CLionProjects/ThreadTest /root/CLionProjects/ThreadTest /root/CLionProjects/ThreadTest/cmake-build-debug /root/CLionProjects/ThreadTest/cmake-build-debug /root/CLionProjects/ThreadTest/cmake-build-debug/CMakeFiles/ThreadTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ThreadTest.dir/depend

