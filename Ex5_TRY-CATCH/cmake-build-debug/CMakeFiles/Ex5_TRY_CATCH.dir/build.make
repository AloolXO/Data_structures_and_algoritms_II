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
CMAKE_COMMAND = /cygdrive/c/Users/onetw/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/onetw/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ex5_TRY_CATCH.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Ex5_TRY_CATCH.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex5_TRY_CATCH.dir/flags.make

CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.o: CMakeFiles/Ex5_TRY_CATCH.dir/flags.make
CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.o -c /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/main.cpp

CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/main.cpp > CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.i

CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/main.cpp -o CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.s

# Object files for target Ex5_TRY_CATCH
Ex5_TRY_CATCH_OBJECTS = \
"CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.o"

# External object files for target Ex5_TRY_CATCH
Ex5_TRY_CATCH_EXTERNAL_OBJECTS =

Ex5_TRY_CATCH.exe: CMakeFiles/Ex5_TRY_CATCH.dir/main.cpp.o
Ex5_TRY_CATCH.exe: CMakeFiles/Ex5_TRY_CATCH.dir/build.make
Ex5_TRY_CATCH.exe: CMakeFiles/Ex5_TRY_CATCH.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ex5_TRY_CATCH.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ex5_TRY_CATCH.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex5_TRY_CATCH.dir/build: Ex5_TRY_CATCH.exe
.PHONY : CMakeFiles/Ex5_TRY_CATCH.dir/build

CMakeFiles/Ex5_TRY_CATCH.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ex5_TRY_CATCH.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ex5_TRY_CATCH.dir/clean

CMakeFiles/Ex5_TRY_CATCH.dir/depend:
	cd /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/cmake-build-debug /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/cmake-build-debug /cygdrive/c/University/2_course/3_semester/Data_structures_and_algoritms_II/Ex5_TRY-CATCH/cmake-build-debug/CMakeFiles/Ex5_TRY_CATCH.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ex5_TRY_CATCH.dir/depend

