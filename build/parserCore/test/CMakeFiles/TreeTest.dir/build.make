# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build

# Include any dependencies generated for this target.
include parserCore/test/CMakeFiles/TreeTest.dir/depend.make

# Include the progress variables for this target.
include parserCore/test/CMakeFiles/TreeTest.dir/progress.make

# Include the compile flags for this target's objects.
include parserCore/test/CMakeFiles/TreeTest.dir/flags.make

parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o: parserCore/test/CMakeFiles/TreeTest.dir/flags.make
parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o: ../parserCore/test/treeTest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o"
	cd /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build/parserCore/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TreeTest.dir/treeTest.cpp.o -c /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/parserCore/test/treeTest.cpp

parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TreeTest.dir/treeTest.cpp.i"
	cd /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build/parserCore/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/parserCore/test/treeTest.cpp > CMakeFiles/TreeTest.dir/treeTest.cpp.i

parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TreeTest.dir/treeTest.cpp.s"
	cd /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build/parserCore/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/parserCore/test/treeTest.cpp -o CMakeFiles/TreeTest.dir/treeTest.cpp.s

parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o.requires:
.PHONY : parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o.requires

parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o.provides: parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o.requires
	$(MAKE) -f parserCore/test/CMakeFiles/TreeTest.dir/build.make parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o.provides.build
.PHONY : parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o.provides

parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o.provides.build: parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o

# Object files for target TreeTest
TreeTest_OBJECTS = \
"CMakeFiles/TreeTest.dir/treeTest.cpp.o"

# External object files for target TreeTest
TreeTest_EXTERNAL_OBJECTS =

parserCore/test/TreeTest: parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o
parserCore/test/TreeTest: parserCore/test/CMakeFiles/TreeTest.dir/build.make
parserCore/test/TreeTest: parserCore/libParserCore.a
parserCore/test/TreeTest: gmock/libgmock_main.a
parserCore/test/TreeTest: parserCore/test/CMakeFiles/TreeTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable TreeTest"
	cd /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build/parserCore/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TreeTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
parserCore/test/CMakeFiles/TreeTest.dir/build: parserCore/test/TreeTest
.PHONY : parserCore/test/CMakeFiles/TreeTest.dir/build

parserCore/test/CMakeFiles/TreeTest.dir/requires: parserCore/test/CMakeFiles/TreeTest.dir/treeTest.cpp.o.requires
.PHONY : parserCore/test/CMakeFiles/TreeTest.dir/requires

parserCore/test/CMakeFiles/TreeTest.dir/clean:
	cd /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build/parserCore/test && $(CMAKE_COMMAND) -P CMakeFiles/TreeTest.dir/cmake_clean.cmake
.PHONY : parserCore/test/CMakeFiles/TreeTest.dir/clean

parserCore/test/CMakeFiles/TreeTest.dir/depend:
	cd /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/parserCore/test /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build/parserCore/test /home/mainak/Documents/Course_CzechRepublic/SecureCodingAndPractises_PA193/project/Project-Part2/MimeParser-master/build/parserCore/test/CMakeFiles/TreeTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : parserCore/test/CMakeFiles/TreeTest.dir/depend
