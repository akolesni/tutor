# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\workspace\github\tutor\gTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\workspace\github\tutor\gTest\cmake-build-debug

# Include any dependencies generated for this target.
include googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include googletest/googlemock/gtest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include googletest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make

googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: googletest/googlemock/gtest/CMakeFiles/gtest.dir/flags.make
googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: googletest/googlemock/gtest/CMakeFiles/gtest.dir/includes_CXX.rsp
googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: ../googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\workspace\github\tutor\gTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd /d C:\workspace\github\tutor\gTest\cmake-build-debug\googletest\googlemock\gtest && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest.dir\src\gtest-all.cc.obj -c C:\workspace\github\tutor\gTest\googletest\googletest\src\gtest-all.cc

googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /d C:\workspace\github\tutor\gTest\cmake-build-debug\googletest\googlemock\gtest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\workspace\github\tutor\gTest\googletest\googletest\src\gtest-all.cc > CMakeFiles\gtest.dir\src\gtest-all.cc.i

googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /d C:\workspace\github\tutor\gTest\cmake-build-debug\googletest\googlemock\gtest && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\workspace\github\tutor\gTest\googletest\googletest\src\gtest-all.cc -o CMakeFiles\gtest.dir\src\gtest-all.cc.s

googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires:

.PHONY : googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires

googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides: googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires
	$(MAKE) -f googletest\googlemock\gtest\CMakeFiles\gtest.dir\build.make googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides.build
.PHONY : googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides

googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.provides.build: googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj


# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

googletest/googlemock/gtest/libgtestd.a: googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
googletest/googlemock/gtest/libgtestd.a: googletest/googlemock/gtest/CMakeFiles/gtest.dir/build.make
googletest/googlemock/gtest/libgtestd.a: googletest/googlemock/gtest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\workspace\github\tutor\gTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtestd.a"
	cd /d C:\workspace\github\tutor\gTest\cmake-build-debug\googletest\googlemock\gtest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd /d C:\workspace\github\tutor\gTest\cmake-build-debug\googletest\googlemock\gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googletest/googlemock/gtest/CMakeFiles/gtest.dir/build: googletest/googlemock/gtest/libgtestd.a

.PHONY : googletest/googlemock/gtest/CMakeFiles/gtest.dir/build

googletest/googlemock/gtest/CMakeFiles/gtest.dir/requires: googletest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj.requires

.PHONY : googletest/googlemock/gtest/CMakeFiles/gtest.dir/requires

googletest/googlemock/gtest/CMakeFiles/gtest.dir/clean:
	cd /d C:\workspace\github\tutor\gTest\cmake-build-debug\googletest\googlemock\gtest && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : googletest/googlemock/gtest/CMakeFiles/gtest.dir/clean

googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\workspace\github\tutor\gTest C:\workspace\github\tutor\gTest\googletest\googletest C:\workspace\github\tutor\gTest\cmake-build-debug C:\workspace\github\tutor\gTest\cmake-build-debug\googletest\googlemock\gtest C:\workspace\github\tutor\gTest\cmake-build-debug\googletest\googlemock\gtest\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : googletest/googlemock/gtest/CMakeFiles/gtest.dir/depend
