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
CMAKE_SOURCE_DIR = C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Corrections.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Corrections.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Corrections.dir/flags.make

CMakeFiles/Corrections.dir/kmeans.c.obj: CMakeFiles/Corrections.dir/flags.make
CMakeFiles/Corrections.dir/kmeans.c.obj: CMakeFiles/Corrections.dir/includes_C.rsp
CMakeFiles/Corrections.dir/kmeans.c.obj: ../kmeans.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Corrections.dir/kmeans.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Corrections.dir\kmeans.c.obj   -c C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections\kmeans.c

CMakeFiles/Corrections.dir/kmeans.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Corrections.dir/kmeans.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections\kmeans.c > CMakeFiles\Corrections.dir\kmeans.c.i

CMakeFiles/Corrections.dir/kmeans.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Corrections.dir/kmeans.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections\kmeans.c -o CMakeFiles\Corrections.dir\kmeans.c.s

# Object files for target Corrections
Corrections_OBJECTS = \
"CMakeFiles/Corrections.dir/kmeans.c.obj"

# External object files for target Corrections
Corrections_EXTERNAL_OBJECTS =

Corrections.exe: CMakeFiles/Corrections.dir/kmeans.c.obj
Corrections.exe: CMakeFiles/Corrections.dir/build.make
Corrections.exe: CMakeFiles/Corrections.dir/linklibs.rsp
Corrections.exe: CMakeFiles/Corrections.dir/objects1.rsp
Corrections.exe: CMakeFiles/Corrections.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Corrections.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Corrections.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Corrections.dir/build: Corrections.exe

.PHONY : CMakeFiles/Corrections.dir/build

CMakeFiles/Corrections.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Corrections.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Corrections.dir/clean

CMakeFiles/Corrections.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections\cmake-build-debug C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections\cmake-build-debug C:\Users\Tomer\CLionProjects\kmeans-git\KMeans\Corrections\cmake-build-debug\CMakeFiles\Corrections.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Corrections.dir/depend

