# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Y\CLionProjects\KMeans

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Y\CLionProjects\KMeans\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\KMeans.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\KMeans.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\KMeans.dir\flags.make

CMakeFiles\KMeans.dir\main.c.obj: CMakeFiles\KMeans.dir\flags.make
CMakeFiles\KMeans.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Y\CLionProjects\KMeans\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/KMeans.dir/main.c.obj"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\KMeans.dir\main.c.obj /FdCMakeFiles\KMeans.dir\ /FS -c C:\Users\Y\CLionProjects\KMeans\main.c
<<

CMakeFiles\KMeans.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/KMeans.dir/main.c.i"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\KMeans.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Y\CLionProjects\KMeans\main.c
<<

CMakeFiles\KMeans.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/KMeans.dir/main.c.s"
	C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\KMeans.dir\main.c.s /c C:\Users\Y\CLionProjects\KMeans\main.c
<<

# Object files for target KMeans
KMeans_OBJECTS = \
"CMakeFiles\KMeans.dir\main.c.obj"

# External object files for target KMeans
KMeans_EXTERNAL_OBJECTS =

KMeans.exe: CMakeFiles\KMeans.dir\main.c.obj
KMeans.exe: CMakeFiles\KMeans.dir\build.make
KMeans.exe: CMakeFiles\KMeans.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Y\CLionProjects\KMeans\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable KMeans.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\KMeans.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~3\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\KMeans.dir\objects1.rsp @<<
 /out:KMeans.exe /implib:KMeans.lib /pdb:C:\Users\Y\CLionProjects\KMeans\cmake-build-debug\KMeans.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\KMeans.dir\build: KMeans.exe

.PHONY : CMakeFiles\KMeans.dir\build

CMakeFiles\KMeans.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\KMeans.dir\cmake_clean.cmake
.PHONY : CMakeFiles\KMeans.dir\clean

CMakeFiles\KMeans.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Y\CLionProjects\KMeans C:\Users\Y\CLionProjects\KMeans C:\Users\Y\CLionProjects\KMeans\cmake-build-debug C:\Users\Y\CLionProjects\KMeans\cmake-build-debug C:\Users\Y\CLionProjects\KMeans\cmake-build-debug\CMakeFiles\KMeans.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\KMeans.dir\depend

