# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "D:\software\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\software\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\git_proj\leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\git_proj\leetcode\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/flags.make

CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/12_INTEGER_TO_ROMAN.cpp.obj: CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/flags.make
CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/12_INTEGER_TO_ROMAN.cpp.obj: ../12_INTEGER_TO_ROMAN.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\git_proj\leetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/12_INTEGER_TO_ROMAN.cpp.obj"
	D:\software\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\12_INTEGER_TO_ROMAN.test.dir\12_INTEGER_TO_ROMAN.cpp.obj -c E:\git_proj\leetcode\12_INTEGER_TO_ROMAN.cpp

CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/12_INTEGER_TO_ROMAN.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/12_INTEGER_TO_ROMAN.cpp.i"
	D:\software\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\git_proj\leetcode\12_INTEGER_TO_ROMAN.cpp > CMakeFiles\12_INTEGER_TO_ROMAN.test.dir\12_INTEGER_TO_ROMAN.cpp.i

CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/12_INTEGER_TO_ROMAN.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/12_INTEGER_TO_ROMAN.cpp.s"
	D:\software\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\git_proj\leetcode\12_INTEGER_TO_ROMAN.cpp -o CMakeFiles\12_INTEGER_TO_ROMAN.test.dir\12_INTEGER_TO_ROMAN.cpp.s

# Object files for target 12_INTEGER_TO_ROMAN.test
12_INTEGER_TO_ROMAN_test_OBJECTS = \
"CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/12_INTEGER_TO_ROMAN.cpp.obj"

# External object files for target 12_INTEGER_TO_ROMAN.test
12_INTEGER_TO_ROMAN_test_EXTERNAL_OBJECTS =

12_INTEGER_TO_ROMAN.test.exe: CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/12_INTEGER_TO_ROMAN.cpp.obj
12_INTEGER_TO_ROMAN.test.exe: CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/build.make
12_INTEGER_TO_ROMAN.test.exe: CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/linklibs.rsp
12_INTEGER_TO_ROMAN.test.exe: CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/objects1.rsp
12_INTEGER_TO_ROMAN.test.exe: CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\git_proj\leetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 12_INTEGER_TO_ROMAN.test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\12_INTEGER_TO_ROMAN.test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/build: 12_INTEGER_TO_ROMAN.test.exe

.PHONY : CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/build

CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\12_INTEGER_TO_ROMAN.test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/clean

CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\git_proj\leetcode E:\git_proj\leetcode E:\git_proj\leetcode\cmake-build-debug E:\git_proj\leetcode\cmake-build-debug E:\git_proj\leetcode\cmake-build-debug\CMakeFiles\12_INTEGER_TO_ROMAN.test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/12_INTEGER_TO_ROMAN.test.dir/depend

