# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.6.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.6.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/joachim/Documents/alcova/orderbook

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/joachim/Documents/alcova/orderbook

# Include any dependencies generated for this target.
include CMakeFiles/pricer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pricer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pricer.dir/flags.make

CMakeFiles/pricer.dir/src/Book.cpp.o: CMakeFiles/pricer.dir/flags.make
CMakeFiles/pricer.dir/src/Book.cpp.o: src/Book.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joachim/Documents/alcova/orderbook/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pricer.dir/src/Book.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pricer.dir/src/Book.cpp.o -c /Users/joachim/Documents/alcova/orderbook/src/Book.cpp

CMakeFiles/pricer.dir/src/Book.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pricer.dir/src/Book.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joachim/Documents/alcova/orderbook/src/Book.cpp > CMakeFiles/pricer.dir/src/Book.cpp.i

CMakeFiles/pricer.dir/src/Book.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pricer.dir/src/Book.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joachim/Documents/alcova/orderbook/src/Book.cpp -o CMakeFiles/pricer.dir/src/Book.cpp.s

CMakeFiles/pricer.dir/src/Book.cpp.o.requires:

.PHONY : CMakeFiles/pricer.dir/src/Book.cpp.o.requires

CMakeFiles/pricer.dir/src/Book.cpp.o.provides: CMakeFiles/pricer.dir/src/Book.cpp.o.requires
	$(MAKE) -f CMakeFiles/pricer.dir/build.make CMakeFiles/pricer.dir/src/Book.cpp.o.provides.build
.PHONY : CMakeFiles/pricer.dir/src/Book.cpp.o.provides

CMakeFiles/pricer.dir/src/Book.cpp.o.provides.build: CMakeFiles/pricer.dir/src/Book.cpp.o


CMakeFiles/pricer.dir/src/Tick.cpp.o: CMakeFiles/pricer.dir/flags.make
CMakeFiles/pricer.dir/src/Tick.cpp.o: src/Tick.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joachim/Documents/alcova/orderbook/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pricer.dir/src/Tick.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pricer.dir/src/Tick.cpp.o -c /Users/joachim/Documents/alcova/orderbook/src/Tick.cpp

CMakeFiles/pricer.dir/src/Tick.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pricer.dir/src/Tick.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joachim/Documents/alcova/orderbook/src/Tick.cpp > CMakeFiles/pricer.dir/src/Tick.cpp.i

CMakeFiles/pricer.dir/src/Tick.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pricer.dir/src/Tick.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joachim/Documents/alcova/orderbook/src/Tick.cpp -o CMakeFiles/pricer.dir/src/Tick.cpp.s

CMakeFiles/pricer.dir/src/Tick.cpp.o.requires:

.PHONY : CMakeFiles/pricer.dir/src/Tick.cpp.o.requires

CMakeFiles/pricer.dir/src/Tick.cpp.o.provides: CMakeFiles/pricer.dir/src/Tick.cpp.o.requires
	$(MAKE) -f CMakeFiles/pricer.dir/build.make CMakeFiles/pricer.dir/src/Tick.cpp.o.provides.build
.PHONY : CMakeFiles/pricer.dir/src/Tick.cpp.o.provides

CMakeFiles/pricer.dir/src/Tick.cpp.o.provides.build: CMakeFiles/pricer.dir/src/Tick.cpp.o


CMakeFiles/pricer.dir/src/main.cpp.o: CMakeFiles/pricer.dir/flags.make
CMakeFiles/pricer.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joachim/Documents/alcova/orderbook/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pricer.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pricer.dir/src/main.cpp.o -c /Users/joachim/Documents/alcova/orderbook/src/main.cpp

CMakeFiles/pricer.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pricer.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joachim/Documents/alcova/orderbook/src/main.cpp > CMakeFiles/pricer.dir/src/main.cpp.i

CMakeFiles/pricer.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pricer.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joachim/Documents/alcova/orderbook/src/main.cpp -o CMakeFiles/pricer.dir/src/main.cpp.s

CMakeFiles/pricer.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/pricer.dir/src/main.cpp.o.requires

CMakeFiles/pricer.dir/src/main.cpp.o.provides: CMakeFiles/pricer.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/pricer.dir/build.make CMakeFiles/pricer.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/pricer.dir/src/main.cpp.o.provides

CMakeFiles/pricer.dir/src/main.cpp.o.provides.build: CMakeFiles/pricer.dir/src/main.cpp.o


CMakeFiles/pricer.dir/src/parsing.cpp.o: CMakeFiles/pricer.dir/flags.make
CMakeFiles/pricer.dir/src/parsing.cpp.o: src/parsing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/joachim/Documents/alcova/orderbook/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pricer.dir/src/parsing.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pricer.dir/src/parsing.cpp.o -c /Users/joachim/Documents/alcova/orderbook/src/parsing.cpp

CMakeFiles/pricer.dir/src/parsing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pricer.dir/src/parsing.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joachim/Documents/alcova/orderbook/src/parsing.cpp > CMakeFiles/pricer.dir/src/parsing.cpp.i

CMakeFiles/pricer.dir/src/parsing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pricer.dir/src/parsing.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joachim/Documents/alcova/orderbook/src/parsing.cpp -o CMakeFiles/pricer.dir/src/parsing.cpp.s

CMakeFiles/pricer.dir/src/parsing.cpp.o.requires:

.PHONY : CMakeFiles/pricer.dir/src/parsing.cpp.o.requires

CMakeFiles/pricer.dir/src/parsing.cpp.o.provides: CMakeFiles/pricer.dir/src/parsing.cpp.o.requires
	$(MAKE) -f CMakeFiles/pricer.dir/build.make CMakeFiles/pricer.dir/src/parsing.cpp.o.provides.build
.PHONY : CMakeFiles/pricer.dir/src/parsing.cpp.o.provides

CMakeFiles/pricer.dir/src/parsing.cpp.o.provides.build: CMakeFiles/pricer.dir/src/parsing.cpp.o


# Object files for target pricer
pricer_OBJECTS = \
"CMakeFiles/pricer.dir/src/Book.cpp.o" \
"CMakeFiles/pricer.dir/src/Tick.cpp.o" \
"CMakeFiles/pricer.dir/src/main.cpp.o" \
"CMakeFiles/pricer.dir/src/parsing.cpp.o"

# External object files for target pricer
pricer_EXTERNAL_OBJECTS =

pricer: CMakeFiles/pricer.dir/src/Book.cpp.o
pricer: CMakeFiles/pricer.dir/src/Tick.cpp.o
pricer: CMakeFiles/pricer.dir/src/main.cpp.o
pricer: CMakeFiles/pricer.dir/src/parsing.cpp.o
pricer: CMakeFiles/pricer.dir/build.make
pricer: CMakeFiles/pricer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/joachim/Documents/alcova/orderbook/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable pricer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pricer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pricer.dir/build: pricer

.PHONY : CMakeFiles/pricer.dir/build

CMakeFiles/pricer.dir/requires: CMakeFiles/pricer.dir/src/Book.cpp.o.requires
CMakeFiles/pricer.dir/requires: CMakeFiles/pricer.dir/src/Tick.cpp.o.requires
CMakeFiles/pricer.dir/requires: CMakeFiles/pricer.dir/src/main.cpp.o.requires
CMakeFiles/pricer.dir/requires: CMakeFiles/pricer.dir/src/parsing.cpp.o.requires

.PHONY : CMakeFiles/pricer.dir/requires

CMakeFiles/pricer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pricer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pricer.dir/clean

CMakeFiles/pricer.dir/depend:
	cd /Users/joachim/Documents/alcova/orderbook && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/joachim/Documents/alcova/orderbook /Users/joachim/Documents/alcova/orderbook /Users/joachim/Documents/alcova/orderbook /Users/joachim/Documents/alcova/orderbook /Users/joachim/Documents/alcova/orderbook/CMakeFiles/pricer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pricer.dir/depend

