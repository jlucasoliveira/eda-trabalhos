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
include CMakeFiles/testao.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testao.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testao.dir/flags.make

CMakeFiles/testao.dir/rubro_negra.cpp.o: CMakeFiles/testao.dir/flags.make
CMakeFiles/testao.dir/rubro_negra.cpp.o: ../rubro_negra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testao.dir/rubro_negra.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testao.dir/rubro_negra.cpp.o -c /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/rubro_negra.cpp

CMakeFiles/testao.dir/rubro_negra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testao.dir/rubro_negra.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/rubro_negra.cpp > CMakeFiles/testao.dir/rubro_negra.cpp.i

CMakeFiles/testao.dir/rubro_negra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testao.dir/rubro_negra.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/rubro_negra.cpp -o CMakeFiles/testao.dir/rubro_negra.cpp.s

CMakeFiles/testao.dir/main.cpp.o: CMakeFiles/testao.dir/flags.make
CMakeFiles/testao.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testao.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testao.dir/main.cpp.o -c /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/main.cpp

CMakeFiles/testao.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testao.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/main.cpp > CMakeFiles/testao.dir/main.cpp.i

CMakeFiles/testao.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testao.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/main.cpp -o CMakeFiles/testao.dir/main.cpp.s

# Object files for target testao
testao_OBJECTS = \
"CMakeFiles/testao.dir/rubro_negra.cpp.o" \
"CMakeFiles/testao.dir/main.cpp.o"

# External object files for target testao
testao_EXTERNAL_OBJECTS =

testao: CMakeFiles/testao.dir/rubro_negra.cpp.o
testao: CMakeFiles/testao.dir/main.cpp.o
testao: CMakeFiles/testao.dir/build.make
testao: CMakeFiles/testao.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable testao"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testao.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testao.dir/build: testao

.PHONY : CMakeFiles/testao.dir/build

CMakeFiles/testao.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testao.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testao.dir/clean

CMakeFiles/testao.dir/depend:
	cd /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug /home/jlucasoliveira/Documentos/development/eda/tad/rubro_negra/cmake-build-debug/CMakeFiles/testao.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testao.dir/depend
