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
CMAKE_SOURCE_DIR = F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LS5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LS5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LS5.dir/flags.make

CMakeFiles/LS5.dir/main.c.obj: CMakeFiles/LS5.dir/flags.make
CMakeFiles/LS5.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LS5.dir/main.c.obj"
	E:\sofeware\clion\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LS5.dir\main.c.obj   -c F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4\main.c

CMakeFiles/LS5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LS5.dir/main.c.i"
	E:\sofeware\clion\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4\main.c > CMakeFiles\LS5.dir\main.c.i

CMakeFiles/LS5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LS5.dir/main.c.s"
	E:\sofeware\clion\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4\main.c -o CMakeFiles\LS5.dir\main.c.s

# Object files for target LS5
LS5_OBJECTS = \
"CMakeFiles/LS5.dir/main.c.obj"

# External object files for target LS5
LS5_EXTERNAL_OBJECTS =

LS5.exe: CMakeFiles/LS5.dir/main.c.obj
LS5.exe: CMakeFiles/LS5.dir/build.make
LS5.exe: CMakeFiles/LS5.dir/linklibs.rsp
LS5.exe: CMakeFiles/LS5.dir/objects1.rsp
LS5.exe: CMakeFiles/LS5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LS5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LS5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LS5.dir/build: LS5.exe

.PHONY : CMakeFiles/LS5.dir/build

CMakeFiles/LS5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LS5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LS5.dir/clean

CMakeFiles/LS5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4 F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4 F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4\cmake-build-debug F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4\cmake-build-debug F:\codeWorkSpace\ManiuSource\AudioandVideo\LS4\cmake-build-debug\CMakeFiles\LS5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LS5.dir/depend
