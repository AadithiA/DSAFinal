# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DSAFinal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DSAFinal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DSAFinal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSAFinal.dir/flags.make

CMakeFiles/DSAFinal.dir/main.cpp.obj: CMakeFiles/DSAFinal.dir/flags.make
CMakeFiles/DSAFinal.dir/main.cpp.obj: C:/Users/Aadit/OneDrive/Documents/GitHub/DSAFinal/main.cpp
CMakeFiles/DSAFinal.dir/main.cpp.obj: CMakeFiles/DSAFinal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DSAFinal.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DSAFinal.dir/main.cpp.obj -MF CMakeFiles\DSAFinal.dir\main.cpp.obj.d -o CMakeFiles\DSAFinal.dir\main.cpp.obj -c C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal\main.cpp

CMakeFiles/DSAFinal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/DSAFinal.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal\main.cpp > CMakeFiles\DSAFinal.dir\main.cpp.i

CMakeFiles/DSAFinal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/DSAFinal.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal\main.cpp -o CMakeFiles\DSAFinal.dir\main.cpp.s

# Object files for target DSAFinal
DSAFinal_OBJECTS = \
"CMakeFiles/DSAFinal.dir/main.cpp.obj"

# External object files for target DSAFinal
DSAFinal_EXTERNAL_OBJECTS =

DSAFinal.exe: CMakeFiles/DSAFinal.dir/main.cpp.obj
DSAFinal.exe: CMakeFiles/DSAFinal.dir/build.make
DSAFinal.exe: CMakeFiles/DSAFinal.dir/linkLibs.rsp
DSAFinal.exe: CMakeFiles/DSAFinal.dir/objects1.rsp
DSAFinal.exe: CMakeFiles/DSAFinal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DSAFinal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DSAFinal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSAFinal.dir/build: DSAFinal.exe
.PHONY : CMakeFiles/DSAFinal.dir/build

CMakeFiles/DSAFinal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DSAFinal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DSAFinal.dir/clean

CMakeFiles/DSAFinal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal\cmake-build-debug C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal\cmake-build-debug C:\Users\Aadit\OneDrive\Documents\GitHub\DSAFinal\cmake-build-debug\CMakeFiles\DSAFinal.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DSAFinal.dir/depend

