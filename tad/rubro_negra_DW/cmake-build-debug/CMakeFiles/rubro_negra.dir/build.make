# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /usr/local/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rubro_negra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rubro_negra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rubro_negra.dir/flags.make

CMakeFiles/rubro_negra.dir/rubro_negra.cpp.o: CMakeFiles/rubro_negra.dir/flags.make
CMakeFiles/rubro_negra.dir/rubro_negra.cpp.o: ../rubro_negra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rubro_negra.dir/rubro_negra.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rubro_negra.dir/rubro_negra.cpp.o -c /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/rubro_negra.cpp

CMakeFiles/rubro_negra.dir/rubro_negra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rubro_negra.dir/rubro_negra.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/rubro_negra.cpp > CMakeFiles/rubro_negra.dir/rubro_negra.cpp.i

CMakeFiles/rubro_negra.dir/rubro_negra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rubro_negra.dir/rubro_negra.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/rubro_negra.cpp -o CMakeFiles/rubro_negra.dir/rubro_negra.cpp.s

# Object files for target rubro_negra
rubro_negra_OBJECTS = \
"CMakeFiles/rubro_negra.dir/rubro_negra.cpp.o"

# External object files for target rubro_negra
rubro_negra_EXTERNAL_OBJECTS =

librubro_negra.a: CMakeFiles/rubro_negra.dir/rubro_negra.cpp.o
librubro_negra.a: CMakeFiles/rubro_negra.dir/build.make
librubro_negra.a: CMakeFiles/rubro_negra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library librubro_negra.a"
	$(CMAKE_COMMAND) -P CMakeFiles/rubro_negra.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rubro_negra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rubro_negra.dir/build: librubro_negra.a

.PHONY : CMakeFiles/rubro_negra.dir/build

CMakeFiles/rubro_negra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rubro_negra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rubro_negra.dir/clean

CMakeFiles/rubro_negra.dir/depend:
	cd /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug/CMakeFiles/rubro_negra.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rubro_negra.dir/depend
