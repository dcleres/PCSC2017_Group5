# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pcsc/Desktop/PCSC2017_Group5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PCSC2017_Group5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PCSC2017_Group5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PCSC2017_Group5.dir/flags.make

CMakeFiles/PCSC2017_Group5.dir/main.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/main.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/main.cpp

CMakeFiles/PCSC2017_Group5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/main.cpp > CMakeFiles/PCSC2017_Group5.dir/main.cpp.i

CMakeFiles/PCSC2017_Group5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/main.cpp -o CMakeFiles/PCSC2017_Group5.dir/main.cpp.s

CMakeFiles/PCSC2017_Group5.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/main.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/main.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/main.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/main.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/main.cpp.o


CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o: ../readFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/readFile.cpp

CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/readFile.cpp > CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.i

CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/readFile.cpp -o CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.s

CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o


CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o: ../FFTtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/FFTtest.cpp

CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/FFTtest.cpp > CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.i

CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/FFTtest.cpp -o CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.s

CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o


CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o: ../FFTreal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/FFTreal.cpp

CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/FFTreal.cpp > CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.i

CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/FFTreal.cpp -o CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.s

CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o


CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o: ../gnuplot_i.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/gnuplot_i.cpp

CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/gnuplot_i.cpp > CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.i

CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/gnuplot_i.cpp -o CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.s

CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o


CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o: ../Lagrange.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/Lagrange.cpp

CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/Lagrange.cpp > CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.i

CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/Lagrange.cpp -o CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.s

CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o


CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o: ../Polynomial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/Polynomial.cpp

CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/Polynomial.cpp > CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.i

CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/Polynomial.cpp -o CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.s

CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o


CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o: ../PieceWise_Continue_Polynomial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/PieceWise_Continue_Polynomial.cpp

CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/PieceWise_Continue_Polynomial.cpp > CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.i

CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/PieceWise_Continue_Polynomial.cpp -o CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.s

CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o


CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o: ../Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/Point.cpp

CMakeFiles/PCSC2017_Group5.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/Point.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/Point.cpp > CMakeFiles/PCSC2017_Group5.dir/Point.cpp.i

CMakeFiles/PCSC2017_Group5.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/Point.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/Point.cpp -o CMakeFiles/PCSC2017_Group5.dir/Point.cpp.s

CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o


CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o: CMakeFiles/PCSC2017_Group5.dir/flags.make
CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o -c /home/pcsc/Desktop/PCSC2017_Group5/Graph.cpp

CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pcsc/Desktop/PCSC2017_Group5/Graph.cpp > CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.i

CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pcsc/Desktop/PCSC2017_Group5/Graph.cpp -o CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.s

CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o.requires:

.PHONY : CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o.requires

CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o.provides: CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o.requires
	$(MAKE) -f CMakeFiles/PCSC2017_Group5.dir/build.make CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o.provides.build
.PHONY : CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o.provides

CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o.provides.build: CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o


# Object files for target PCSC2017_Group5
PCSC2017_Group5_OBJECTS = \
"CMakeFiles/PCSC2017_Group5.dir/main.cpp.o" \
"CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o" \
"CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o" \
"CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o" \
"CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o" \
"CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o" \
"CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o" \
"CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o" \
"CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o" \
"CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o"

# External object files for target PCSC2017_Group5
PCSC2017_Group5_EXTERNAL_OBJECTS =

PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/main.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/build.make
PCSC2017_Group5: CMakeFiles/PCSC2017_Group5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable PCSC2017_Group5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PCSC2017_Group5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PCSC2017_Group5.dir/build: PCSC2017_Group5

.PHONY : CMakeFiles/PCSC2017_Group5.dir/build

CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/main.cpp.o.requires
CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/readFile.cpp.o.requires
CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/FFTtest.cpp.o.requires
CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/FFTreal.cpp.o.requires
CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/gnuplot_i.cpp.o.requires
CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/Lagrange.cpp.o.requires
CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/Polynomial.cpp.o.requires
CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/PieceWise_Continue_Polynomial.cpp.o.requires
CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/Point.cpp.o.requires
CMakeFiles/PCSC2017_Group5.dir/requires: CMakeFiles/PCSC2017_Group5.dir/Graph.cpp.o.requires

.PHONY : CMakeFiles/PCSC2017_Group5.dir/requires

CMakeFiles/PCSC2017_Group5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PCSC2017_Group5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PCSC2017_Group5.dir/clean

CMakeFiles/PCSC2017_Group5.dir/depend:
	cd /home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pcsc/Desktop/PCSC2017_Group5 /home/pcsc/Desktop/PCSC2017_Group5 /home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug /home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug /home/pcsc/Desktop/PCSC2017_Group5/cmake-build-debug/CMakeFiles/PCSC2017_Group5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PCSC2017_Group5.dir/depend

