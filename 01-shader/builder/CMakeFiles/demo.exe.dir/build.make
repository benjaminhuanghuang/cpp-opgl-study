# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bhuang/ben-github/opgl-study/01-shader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bhuang/ben-github/opgl-study/01-shader/builder

# Include any dependencies generated for this target.
include CMakeFiles/demo.exe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.exe.dir/flags.make

CMakeFiles/demo.exe.dir/shader-demo.cpp.o: CMakeFiles/demo.exe.dir/flags.make
CMakeFiles/demo.exe.dir/shader-demo.cpp.o: ../shader-demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bhuang/ben-github/opgl-study/01-shader/builder/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo.exe.dir/shader-demo.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.exe.dir/shader-demo.cpp.o -c /Users/bhuang/ben-github/opgl-study/01-shader/shader-demo.cpp

CMakeFiles/demo.exe.dir/shader-demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.exe.dir/shader-demo.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bhuang/ben-github/opgl-study/01-shader/shader-demo.cpp > CMakeFiles/demo.exe.dir/shader-demo.cpp.i

CMakeFiles/demo.exe.dir/shader-demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.exe.dir/shader-demo.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bhuang/ben-github/opgl-study/01-shader/shader-demo.cpp -o CMakeFiles/demo.exe.dir/shader-demo.cpp.s

# Object files for target demo.exe
demo_exe_OBJECTS = \
"CMakeFiles/demo.exe.dir/shader-demo.cpp.o"

# External object files for target demo.exe
demo_exe_EXTERNAL_OBJECTS =

demo.exe: CMakeFiles/demo.exe.dir/shader-demo.cpp.o
demo.exe: CMakeFiles/demo.exe.dir/build.make
demo.exe: CMakeFiles/demo.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bhuang/ben-github/opgl-study/01-shader/builder/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable demo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.exe.dir/build: demo.exe

.PHONY : CMakeFiles/demo.exe.dir/build

CMakeFiles/demo.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.exe.dir/clean

CMakeFiles/demo.exe.dir/depend:
	cd /Users/bhuang/ben-github/opgl-study/01-shader/builder && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bhuang/ben-github/opgl-study/01-shader /Users/bhuang/ben-github/opgl-study/01-shader /Users/bhuang/ben-github/opgl-study/01-shader/builder /Users/bhuang/ben-github/opgl-study/01-shader/builder /Users/bhuang/ben-github/opgl-study/01-shader/builder/CMakeFiles/demo.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo.exe.dir/depend

