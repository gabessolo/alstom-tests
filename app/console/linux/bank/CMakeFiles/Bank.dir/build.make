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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/Downloads/alstom-tests/app/console/linux/bank

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Downloads/alstom-tests/app/console/linux/bank

# Include any dependencies generated for this target.
include CMakeFiles/Bank.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bank.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bank.dir/flags.make

CMakeFiles/Bank.dir/bank.cpp.o: CMakeFiles/Bank.dir/flags.make
CMakeFiles/Bank.dir/bank.cpp.o: bank.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Downloads/alstom-tests/app/console/linux/bank/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Bank.dir/bank.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Bank.dir/bank.cpp.o -c /root/Downloads/alstom-tests/app/console/linux/bank/bank.cpp

CMakeFiles/Bank.dir/bank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bank.dir/bank.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Downloads/alstom-tests/app/console/linux/bank/bank.cpp > CMakeFiles/Bank.dir/bank.cpp.i

CMakeFiles/Bank.dir/bank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bank.dir/bank.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Downloads/alstom-tests/app/console/linux/bank/bank.cpp -o CMakeFiles/Bank.dir/bank.cpp.s

CMakeFiles/Bank.dir/bank.cpp.o.requires:
.PHONY : CMakeFiles/Bank.dir/bank.cpp.o.requires

CMakeFiles/Bank.dir/bank.cpp.o.provides: CMakeFiles/Bank.dir/bank.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bank.dir/build.make CMakeFiles/Bank.dir/bank.cpp.o.provides.build
.PHONY : CMakeFiles/Bank.dir/bank.cpp.o.provides

CMakeFiles/Bank.dir/bank.cpp.o.provides.build: CMakeFiles/Bank.dir/bank.cpp.o

CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o: CMakeFiles/Bank.dir/flags.make
CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o: /root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Downloads/alstom-tests/app/console/linux/bank/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o"
	/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o -c /root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp

CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.i"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp > CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.i

CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.s"
	/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp -o CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.s

CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o.requires:
.PHONY : CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o.requires

CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o.provides: CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bank.dir/build.make CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o.provides.build
.PHONY : CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o.provides

CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o.provides.build: CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o

# Object files for target Bank
Bank_OBJECTS = \
"CMakeFiles/Bank.dir/bank.cpp.o" \
"CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o"

# External object files for target Bank
Bank_EXTERNAL_OBJECTS =

Bank: CMakeFiles/Bank.dir/bank.cpp.o
Bank: CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o
Bank: CMakeFiles/Bank.dir/build.make
Bank: CMakeFiles/Bank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Bank"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bank.dir/build: Bank
.PHONY : CMakeFiles/Bank.dir/build

CMakeFiles/Bank.dir/requires: CMakeFiles/Bank.dir/bank.cpp.o.requires
CMakeFiles/Bank.dir/requires: CMakeFiles/Bank.dir/root/Downloads/alstom-tests/app/console/linux/common/bankUtils.cpp.o.requires
.PHONY : CMakeFiles/Bank.dir/requires

CMakeFiles/Bank.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bank.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bank.dir/clean

CMakeFiles/Bank.dir/depend:
	cd /root/Downloads/alstom-tests/app/console/linux/bank && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Downloads/alstom-tests/app/console/linux/bank /root/Downloads/alstom-tests/app/console/linux/bank /root/Downloads/alstom-tests/app/console/linux/bank /root/Downloads/alstom-tests/app/console/linux/bank /root/Downloads/alstom-tests/app/console/linux/bank/CMakeFiles/Bank.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bank.dir/depend

