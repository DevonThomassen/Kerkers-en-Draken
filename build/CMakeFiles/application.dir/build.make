# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/devonthomassen/CLionProjects/kerkers-en-draken

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/devonthomassen/CLionProjects/kerkers-en-draken/build

# Include any dependencies generated for this target.
include CMakeFiles/application.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/application.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/application.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/application.dir/flags.make

CMakeFiles/application.dir/src/application/GameService.cpp.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/application/GameService.cpp.o: /Users/devonthomassen/CLionProjects/kerkers-en-draken/src/application/GameService.cpp
CMakeFiles/application.dir/src/application/GameService.cpp.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/devonthomassen/CLionProjects/kerkers-en-draken/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/application.dir/src/application/GameService.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/application.dir/src/application/GameService.cpp.o -MF CMakeFiles/application.dir/src/application/GameService.cpp.o.d -o CMakeFiles/application.dir/src/application/GameService.cpp.o -c /Users/devonthomassen/CLionProjects/kerkers-en-draken/src/application/GameService.cpp

CMakeFiles/application.dir/src/application/GameService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/application.dir/src/application/GameService.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/devonthomassen/CLionProjects/kerkers-en-draken/src/application/GameService.cpp > CMakeFiles/application.dir/src/application/GameService.cpp.i

CMakeFiles/application.dir/src/application/GameService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/application.dir/src/application/GameService.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/devonthomassen/CLionProjects/kerkers-en-draken/src/application/GameService.cpp -o CMakeFiles/application.dir/src/application/GameService.cpp.s

# Object files for target application
application_OBJECTS = \
"CMakeFiles/application.dir/src/application/GameService.cpp.o"

# External object files for target application
application_EXTERNAL_OBJECTS =

libapplication.a: CMakeFiles/application.dir/src/application/GameService.cpp.o
libapplication.a: CMakeFiles/application.dir/build.make
libapplication.a: CMakeFiles/application.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/devonthomassen/CLionProjects/kerkers-en-draken/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libapplication.a"
	$(CMAKE_COMMAND) -P CMakeFiles/application.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/application.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/application.dir/build: libapplication.a
.PHONY : CMakeFiles/application.dir/build

CMakeFiles/application.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/application.dir/cmake_clean.cmake
.PHONY : CMakeFiles/application.dir/clean

CMakeFiles/application.dir/depend:
	cd /Users/devonthomassen/CLionProjects/kerkers-en-draken/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/devonthomassen/CLionProjects/kerkers-en-draken /Users/devonthomassen/CLionProjects/kerkers-en-draken /Users/devonthomassen/CLionProjects/kerkers-en-draken/build /Users/devonthomassen/CLionProjects/kerkers-en-draken/build /Users/devonthomassen/CLionProjects/kerkers-en-draken/build/CMakeFiles/application.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/application.dir/depend

