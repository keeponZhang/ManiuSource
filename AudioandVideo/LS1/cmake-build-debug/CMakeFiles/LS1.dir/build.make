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
CMAKE_COMMAND = E:\sofeware\clion\software\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = E:\sofeware\clion\software\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LS1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LS1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LS1.dir/flags.make

CMakeFiles/LS1.dir/main6.c.obj: CMakeFiles/LS1.dir/flags.make
CMakeFiles/LS1.dir/main6.c.obj: ../main6.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LS1.dir/main6.c.obj"
	E:\sofeware\clion\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LS1.dir\main6.c.obj   -c F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1\main6.c

CMakeFiles/LS1.dir/main6.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LS1.dir/main6.c.i"
	E:\sofeware\clion\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1\main6.c > CMakeFiles\LS1.dir\main6.c.i

CMakeFiles/LS1.dir/main6.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LS1.dir/main6.c.s"
	E:\sofeware\clion\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1\main6.c -o CMakeFiles\LS1.dir\main6.c.s

# Object files for target LS1
LS1_OBJECTS = \
"CMakeFiles/LS1.dir/main6.c.obj"

# External object files for target LS1
LS1_EXTERNAL_OBJECTS =

LS1.exe: CMakeFiles/LS1.dir/main6.c.obj
LS1.exe: CMakeFiles/LS1.dir/build.make
LS1.exe: CMakeFiles/LS1.dir/linklibs.rsp
LS1.exe: CMakeFiles/LS1.dir/objects1.rsp
LS1.exe: CMakeFiles/LS1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LS1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LS1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LS1.dir/build: LS1.exe

.PHONY : CMakeFiles/LS1.dir/build

CMakeFiles/LS1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LS1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LS1.dir/clean

CMakeFiles/LS1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1 F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1 F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1\cmake-build-debug F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1\cmake-build-debug F:\codeWorkSpace\ManiuSource\AudioandVideo\LS1\cmake-build-debug\CMakeFiles\LS1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LS1.dir/depend

