# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Martin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\182.4129.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Martin\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\182.4129.51\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Martin\CLionProjects\WebServ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Martin\CLionProjects\WebServ\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ThreadTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ThreadTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ThreadTest.dir/flags.make

CMakeFiles/ThreadTest.dir/main.cpp.obj: CMakeFiles/ThreadTest.dir/flags.make
CMakeFiles/ThreadTest.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Martin\CLionProjects\WebServ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ThreadTest.dir/main.cpp.obj"
	C:\CodeBlocks\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ThreadTest.dir\main.cpp.obj -c C:\Users\Martin\CLionProjects\WebServ\main.cpp

CMakeFiles/ThreadTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadTest.dir/main.cpp.i"
	C:\CodeBlocks\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Martin\CLionProjects\WebServ\main.cpp > CMakeFiles\ThreadTest.dir\main.cpp.i

CMakeFiles/ThreadTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadTest.dir/main.cpp.s"
	C:\CodeBlocks\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Martin\CLionProjects\WebServ\main.cpp -o CMakeFiles\ThreadTest.dir\main.cpp.s

CMakeFiles/ThreadTest.dir/web_serv.cpp.obj: CMakeFiles/ThreadTest.dir/flags.make
CMakeFiles/ThreadTest.dir/web_serv.cpp.obj: ../web_serv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Martin\CLionProjects\WebServ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ThreadTest.dir/web_serv.cpp.obj"
	C:\CodeBlocks\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ThreadTest.dir\web_serv.cpp.obj -c C:\Users\Martin\CLionProjects\WebServ\web_serv.cpp

CMakeFiles/ThreadTest.dir/web_serv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadTest.dir/web_serv.cpp.i"
	C:\CodeBlocks\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Martin\CLionProjects\WebServ\web_serv.cpp > CMakeFiles\ThreadTest.dir\web_serv.cpp.i

CMakeFiles/ThreadTest.dir/web_serv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadTest.dir/web_serv.cpp.s"
	C:\CodeBlocks\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Martin\CLionProjects\WebServ\web_serv.cpp -o CMakeFiles\ThreadTest.dir\web_serv.cpp.s

CMakeFiles/ThreadTest.dir/request_response.cpp.obj: CMakeFiles/ThreadTest.dir/flags.make
CMakeFiles/ThreadTest.dir/request_response.cpp.obj: ../request_response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Martin\CLionProjects\WebServ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ThreadTest.dir/request_response.cpp.obj"
	C:\CodeBlocks\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ThreadTest.dir\request_response.cpp.obj -c C:\Users\Martin\CLionProjects\WebServ\request_response.cpp

CMakeFiles/ThreadTest.dir/request_response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ThreadTest.dir/request_response.cpp.i"
	C:\CodeBlocks\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Martin\CLionProjects\WebServ\request_response.cpp > CMakeFiles\ThreadTest.dir\request_response.cpp.i

CMakeFiles/ThreadTest.dir/request_response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ThreadTest.dir/request_response.cpp.s"
	C:\CodeBlocks\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Martin\CLionProjects\WebServ\request_response.cpp -o CMakeFiles\ThreadTest.dir\request_response.cpp.s

# Object files for target ThreadTest
ThreadTest_OBJECTS = \
"CMakeFiles/ThreadTest.dir/main.cpp.obj" \
"CMakeFiles/ThreadTest.dir/web_serv.cpp.obj" \
"CMakeFiles/ThreadTest.dir/request_response.cpp.obj"

# External object files for target ThreadTest
ThreadTest_EXTERNAL_OBJECTS =

ThreadTest.exe: CMakeFiles/ThreadTest.dir/main.cpp.obj
ThreadTest.exe: CMakeFiles/ThreadTest.dir/web_serv.cpp.obj
ThreadTest.exe: CMakeFiles/ThreadTest.dir/request_response.cpp.obj
ThreadTest.exe: CMakeFiles/ThreadTest.dir/build.make
ThreadTest.exe: CMakeFiles/ThreadTest.dir/linklibs.rsp
ThreadTest.exe: CMakeFiles/ThreadTest.dir/objects1.rsp
ThreadTest.exe: CMakeFiles/ThreadTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Martin\CLionProjects\WebServ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ThreadTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ThreadTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ThreadTest.dir/build: ThreadTest.exe

.PHONY : CMakeFiles/ThreadTest.dir/build

CMakeFiles/ThreadTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ThreadTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ThreadTest.dir/clean

CMakeFiles/ThreadTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Martin\CLionProjects\WebServ C:\Users\Martin\CLionProjects\WebServ C:\Users\Martin\CLionProjects\WebServ\cmake-build-debug C:\Users\Martin\CLionProjects\WebServ\cmake-build-debug C:\Users\Martin\CLionProjects\WebServ\cmake-build-debug\CMakeFiles\ThreadTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ThreadTest.dir/depend

