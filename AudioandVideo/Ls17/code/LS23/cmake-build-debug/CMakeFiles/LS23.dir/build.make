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
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.2.5\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Administrator\CLionProjects\LS23

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Administrator\CLionProjects\LS23\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LS23.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LS23.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LS23.dir/flags.make

CMakeFiles/LS23.dir/main.c.obj: CMakeFiles/LS23.dir/flags.make
CMakeFiles/LS23.dir/main.c.obj: CMakeFiles/LS23.dir/includes_C.rsp
CMakeFiles/LS23.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\CLionProjects\LS23\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LS23.dir/main.c.obj"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LS23.dir\main.c.obj   -c C:\Users\Administrator\CLionProjects\LS23\main.c

CMakeFiles/LS23.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LS23.dir/main.c.i"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Administrator\CLionProjects\LS23\main.c > CMakeFiles\LS23.dir\main.c.i

CMakeFiles/LS23.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LS23.dir/main.c.s"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Administrator\CLionProjects\LS23\main.c -o CMakeFiles\LS23.dir\main.c.s

CMakeFiles/LS23.dir/include/test1.c.obj: CMakeFiles/LS23.dir/flags.make
CMakeFiles/LS23.dir/include/test1.c.obj: CMakeFiles/LS23.dir/includes_C.rsp
CMakeFiles/LS23.dir/include/test1.c.obj: ../include/test1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\CLionProjects\LS23\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/LS23.dir/include/test1.c.obj"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LS23.dir\include\test1.c.obj   -c C:\Users\Administrator\CLionProjects\LS23\include\test1.c

CMakeFiles/LS23.dir/include/test1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LS23.dir/include/test1.c.i"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Administrator\CLionProjects\LS23\include\test1.c > CMakeFiles\LS23.dir\include\test1.c.i

CMakeFiles/LS23.dir/include/test1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LS23.dir/include/test1.c.s"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Administrator\CLionProjects\LS23\include\test1.c -o CMakeFiles\LS23.dir\include\test1.c.s

# Object files for target LS23
LS23_OBJECTS = \
"CMakeFiles/LS23.dir/main.c.obj" \
"CMakeFiles/LS23.dir/include/test1.c.obj"

# External object files for target LS23
LS23_EXTERNAL_OBJECTS =

../lib/libLS23.a: CMakeFiles/LS23.dir/main.c.obj
../lib/libLS23.a: CMakeFiles/LS23.dir/include/test1.c.obj
../lib/libLS23.a: CMakeFiles/LS23.dir/build.make
../lib/libLS23.a: CMakeFiles/LS23.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Administrator\CLionProjects\LS23\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library ..\lib\libLS23.a"
	$(CMAKE_COMMAND) -P CMakeFiles\LS23.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LS23.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LS23.dir/build: ../lib/libLS23.a

.PHONY : CMakeFiles/LS23.dir/build

CMakeFiles/LS23.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LS23.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LS23.dir/clean

CMakeFiles/LS23.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Administrator\CLionProjects\LS23 C:\Users\Administrator\CLionProjects\LS23 C:\Users\Administrator\CLionProjects\LS23\cmake-build-debug C:\Users\Administrator\CLionProjects\LS23\cmake-build-debug C:\Users\Administrator\CLionProjects\LS23\cmake-build-debug\CMakeFiles\LS23.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LS23.dir/depend

