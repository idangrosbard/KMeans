# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\home\KMeans

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\home\KMeans\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KMeans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KMeans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KMeans.dir/flags.make

CMakeFiles/KMeans.dir/main.c.obj: CMakeFiles/KMeans.dir/flags.make
CMakeFiles/KMeans.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\home\KMeans\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/KMeans.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\KMeans.dir\main.c.obj   -c C:\home\KMeans\main.c

CMakeFiles/KMeans.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/KMeans.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\home\KMeans\main.c > CMakeFiles\KMeans.dir\main.c.i

CMakeFiles/KMeans.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/KMeans.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\home\KMeans\main.c -o CMakeFiles\KMeans.dir\main.c.s

# Object files for target KMeans
KMeans_OBJECTS = \
"CMakeFiles/KMeans.dir/main.c.obj"

# External object files for target KMeans
KMeans_EXTERNAL_OBJECTS =

KMeans.exe: CMakeFiles/KMeans.dir/main.c.obj
KMeans.exe: CMakeFiles/KMeans.dir/build.make
KMeans.exe: CMakeFiles/KMeans.dir/linklibs.rsp
KMeans.exe: CMakeFiles/KMeans.dir/objects1.rsp
KMeans.exe: CMakeFiles/KMeans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\home\KMeans\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable KMeans.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\KMeans.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KMeans.dir/build: KMeans.exe

.PHONY : CMakeFiles/KMeans.dir/build

CMakeFiles/KMeans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\KMeans.dir\cmake_clean.cmake
.PHONY : CMakeFiles/KMeans.dir/clean

CMakeFiles/KMeans.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\home\KMeans C:\home\KMeans C:\home\KMeans\cmake-build-debug C:\home\KMeans\cmake-build-debug C:\home\KMeans\cmake-build-debug\CMakeFiles\KMeans.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KMeans.dir/depend

