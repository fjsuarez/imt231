# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/fjsuarez/imt231/Clase 9"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/fjsuarez/imt231/Clase 9/build"

# Include any dependencies generated for this target.
include CMakeFiles/MiPrograma.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MiPrograma.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MiPrograma.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MiPrograma.dir/flags.make

CMakeFiles/MiPrograma.dir/src/main.cpp.o: CMakeFiles/MiPrograma.dir/flags.make
CMakeFiles/MiPrograma.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/MiPrograma.dir/src/main.cpp.o: CMakeFiles/MiPrograma.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/fjsuarez/imt231/Clase 9/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MiPrograma.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MiPrograma.dir/src/main.cpp.o -MF CMakeFiles/MiPrograma.dir/src/main.cpp.o.d -o CMakeFiles/MiPrograma.dir/src/main.cpp.o -c "/home/fjsuarez/imt231/Clase 9/src/main.cpp"

CMakeFiles/MiPrograma.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiPrograma.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fjsuarez/imt231/Clase 9/src/main.cpp" > CMakeFiles/MiPrograma.dir/src/main.cpp.i

CMakeFiles/MiPrograma.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiPrograma.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fjsuarez/imt231/Clase 9/src/main.cpp" -o CMakeFiles/MiPrograma.dir/src/main.cpp.s

CMakeFiles/MiPrograma.dir/src/Saludo.cpp.o: CMakeFiles/MiPrograma.dir/flags.make
CMakeFiles/MiPrograma.dir/src/Saludo.cpp.o: ../src/Saludo.cpp
CMakeFiles/MiPrograma.dir/src/Saludo.cpp.o: CMakeFiles/MiPrograma.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/fjsuarez/imt231/Clase 9/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MiPrograma.dir/src/Saludo.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MiPrograma.dir/src/Saludo.cpp.o -MF CMakeFiles/MiPrograma.dir/src/Saludo.cpp.o.d -o CMakeFiles/MiPrograma.dir/src/Saludo.cpp.o -c "/home/fjsuarez/imt231/Clase 9/src/Saludo.cpp"

CMakeFiles/MiPrograma.dir/src/Saludo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MiPrograma.dir/src/Saludo.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fjsuarez/imt231/Clase 9/src/Saludo.cpp" > CMakeFiles/MiPrograma.dir/src/Saludo.cpp.i

CMakeFiles/MiPrograma.dir/src/Saludo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MiPrograma.dir/src/Saludo.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fjsuarez/imt231/Clase 9/src/Saludo.cpp" -o CMakeFiles/MiPrograma.dir/src/Saludo.cpp.s

# Object files for target MiPrograma
MiPrograma_OBJECTS = \
"CMakeFiles/MiPrograma.dir/src/main.cpp.o" \
"CMakeFiles/MiPrograma.dir/src/Saludo.cpp.o"

# External object files for target MiPrograma
MiPrograma_EXTERNAL_OBJECTS =

MiPrograma: CMakeFiles/MiPrograma.dir/src/main.cpp.o
MiPrograma: CMakeFiles/MiPrograma.dir/src/Saludo.cpp.o
MiPrograma: CMakeFiles/MiPrograma.dir/build.make
MiPrograma: CMakeFiles/MiPrograma.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/fjsuarez/imt231/Clase 9/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MiPrograma"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MiPrograma.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MiPrograma.dir/build: MiPrograma
.PHONY : CMakeFiles/MiPrograma.dir/build

CMakeFiles/MiPrograma.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MiPrograma.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MiPrograma.dir/clean

CMakeFiles/MiPrograma.dir/depend:
	cd "/home/fjsuarez/imt231/Clase 9/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/fjsuarez/imt231/Clase 9" "/home/fjsuarez/imt231/Clase 9" "/home/fjsuarez/imt231/Clase 9/build" "/home/fjsuarez/imt231/Clase 9/build" "/home/fjsuarez/imt231/Clase 9/build/CMakeFiles/MiPrograma.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MiPrograma.dir/depend

