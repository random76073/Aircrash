# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = I:/RareMetalSpace/App/CMake/bin/cmake.exe

# The command to remove a file.
RM = I:/RareMetalSpace/App/CMake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = I:/RareMetalSpace/Aircrash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = I:/RareMetalSpace/Aircrash/build

# Include any dependencies generated for this target.
include CMakeFiles/Aircrash.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Aircrash.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Aircrash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Aircrash.dir/flags.make

CMakeFiles/Aircrash.dir/main.cpp.obj: CMakeFiles/Aircrash.dir/flags.make
CMakeFiles/Aircrash.dir/main.cpp.obj: CMakeFiles/Aircrash.dir/includes_CXX.rsp
CMakeFiles/Aircrash.dir/main.cpp.obj: I:/RareMetalSpace/Aircrash/main.cpp
CMakeFiles/Aircrash.dir/main.cpp.obj: CMakeFiles/Aircrash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:/RareMetalSpace/Aircrash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Aircrash.dir/main.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Aircrash.dir/main.cpp.obj -MF CMakeFiles/Aircrash.dir/main.cpp.obj.d -o CMakeFiles/Aircrash.dir/main.cpp.obj -c I:/RareMetalSpace/Aircrash/main.cpp

CMakeFiles/Aircrash.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aircrash.dir/main.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:/RareMetalSpace/Aircrash/main.cpp > CMakeFiles/Aircrash.dir/main.cpp.i

CMakeFiles/Aircrash.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aircrash.dir/main.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:/RareMetalSpace/Aircrash/main.cpp -o CMakeFiles/Aircrash.dir/main.cpp.s

CMakeFiles/Aircrash.dir/src/glad.cpp.obj: CMakeFiles/Aircrash.dir/flags.make
CMakeFiles/Aircrash.dir/src/glad.cpp.obj: CMakeFiles/Aircrash.dir/includes_CXX.rsp
CMakeFiles/Aircrash.dir/src/glad.cpp.obj: I:/RareMetalSpace/Aircrash/src/glad.cpp
CMakeFiles/Aircrash.dir/src/glad.cpp.obj: CMakeFiles/Aircrash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:/RareMetalSpace/Aircrash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Aircrash.dir/src/glad.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Aircrash.dir/src/glad.cpp.obj -MF CMakeFiles/Aircrash.dir/src/glad.cpp.obj.d -o CMakeFiles/Aircrash.dir/src/glad.cpp.obj -c I:/RareMetalSpace/Aircrash/src/glad.cpp

CMakeFiles/Aircrash.dir/src/glad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aircrash.dir/src/glad.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:/RareMetalSpace/Aircrash/src/glad.cpp > CMakeFiles/Aircrash.dir/src/glad.cpp.i

CMakeFiles/Aircrash.dir/src/glad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aircrash.dir/src/glad.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:/RareMetalSpace/Aircrash/src/glad.cpp -o CMakeFiles/Aircrash.dir/src/glad.cpp.s

CMakeFiles/Aircrash.dir/src/shader.cpp.obj: CMakeFiles/Aircrash.dir/flags.make
CMakeFiles/Aircrash.dir/src/shader.cpp.obj: CMakeFiles/Aircrash.dir/includes_CXX.rsp
CMakeFiles/Aircrash.dir/src/shader.cpp.obj: I:/RareMetalSpace/Aircrash/src/shader.cpp
CMakeFiles/Aircrash.dir/src/shader.cpp.obj: CMakeFiles/Aircrash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:/RareMetalSpace/Aircrash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Aircrash.dir/src/shader.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Aircrash.dir/src/shader.cpp.obj -MF CMakeFiles/Aircrash.dir/src/shader.cpp.obj.d -o CMakeFiles/Aircrash.dir/src/shader.cpp.obj -c I:/RareMetalSpace/Aircrash/src/shader.cpp

CMakeFiles/Aircrash.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aircrash.dir/src/shader.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:/RareMetalSpace/Aircrash/src/shader.cpp > CMakeFiles/Aircrash.dir/src/shader.cpp.i

CMakeFiles/Aircrash.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aircrash.dir/src/shader.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:/RareMetalSpace/Aircrash/src/shader.cpp -o CMakeFiles/Aircrash.dir/src/shader.cpp.s

CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj: CMakeFiles/Aircrash.dir/flags.make
CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj: CMakeFiles/Aircrash.dir/includes_CXX.rsp
CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj: I:/RareMetalSpace/Aircrash/src/stb_image.cpp
CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj: CMakeFiles/Aircrash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:/RareMetalSpace/Aircrash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj -MF CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj.d -o CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj -c I:/RareMetalSpace/Aircrash/src/stb_image.cpp

CMakeFiles/Aircrash.dir/src/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aircrash.dir/src/stb_image.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:/RareMetalSpace/Aircrash/src/stb_image.cpp > CMakeFiles/Aircrash.dir/src/stb_image.cpp.i

CMakeFiles/Aircrash.dir/src/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aircrash.dir/src/stb_image.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:/RareMetalSpace/Aircrash/src/stb_image.cpp -o CMakeFiles/Aircrash.dir/src/stb_image.cpp.s

CMakeFiles/Aircrash.dir/src/texture.cpp.obj: CMakeFiles/Aircrash.dir/flags.make
CMakeFiles/Aircrash.dir/src/texture.cpp.obj: CMakeFiles/Aircrash.dir/includes_CXX.rsp
CMakeFiles/Aircrash.dir/src/texture.cpp.obj: I:/RareMetalSpace/Aircrash/src/texture.cpp
CMakeFiles/Aircrash.dir/src/texture.cpp.obj: CMakeFiles/Aircrash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:/RareMetalSpace/Aircrash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Aircrash.dir/src/texture.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Aircrash.dir/src/texture.cpp.obj -MF CMakeFiles/Aircrash.dir/src/texture.cpp.obj.d -o CMakeFiles/Aircrash.dir/src/texture.cpp.obj -c I:/RareMetalSpace/Aircrash/src/texture.cpp

CMakeFiles/Aircrash.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aircrash.dir/src/texture.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:/RareMetalSpace/Aircrash/src/texture.cpp > CMakeFiles/Aircrash.dir/src/texture.cpp.i

CMakeFiles/Aircrash.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aircrash.dir/src/texture.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:/RareMetalSpace/Aircrash/src/texture.cpp -o CMakeFiles/Aircrash.dir/src/texture.cpp.s

CMakeFiles/Aircrash.dir/src/tools.cpp.obj: CMakeFiles/Aircrash.dir/flags.make
CMakeFiles/Aircrash.dir/src/tools.cpp.obj: CMakeFiles/Aircrash.dir/includes_CXX.rsp
CMakeFiles/Aircrash.dir/src/tools.cpp.obj: I:/RareMetalSpace/Aircrash/src/tools.cpp
CMakeFiles/Aircrash.dir/src/tools.cpp.obj: CMakeFiles/Aircrash.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=I:/RareMetalSpace/Aircrash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Aircrash.dir/src/tools.cpp.obj"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Aircrash.dir/src/tools.cpp.obj -MF CMakeFiles/Aircrash.dir/src/tools.cpp.obj.d -o CMakeFiles/Aircrash.dir/src/tools.cpp.obj -c I:/RareMetalSpace/Aircrash/src/tools.cpp

CMakeFiles/Aircrash.dir/src/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aircrash.dir/src/tools.cpp.i"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E I:/RareMetalSpace/Aircrash/src/tools.cpp > CMakeFiles/Aircrash.dir/src/tools.cpp.i

CMakeFiles/Aircrash.dir/src/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aircrash.dir/src/tools.cpp.s"
	C:/MinGW/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S I:/RareMetalSpace/Aircrash/src/tools.cpp -o CMakeFiles/Aircrash.dir/src/tools.cpp.s

# Object files for target Aircrash
Aircrash_OBJECTS = \
"CMakeFiles/Aircrash.dir/main.cpp.obj" \
"CMakeFiles/Aircrash.dir/src/glad.cpp.obj" \
"CMakeFiles/Aircrash.dir/src/shader.cpp.obj" \
"CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj" \
"CMakeFiles/Aircrash.dir/src/texture.cpp.obj" \
"CMakeFiles/Aircrash.dir/src/tools.cpp.obj"

# External object files for target Aircrash
Aircrash_EXTERNAL_OBJECTS =

Aircrash.exe: CMakeFiles/Aircrash.dir/main.cpp.obj
Aircrash.exe: CMakeFiles/Aircrash.dir/src/glad.cpp.obj
Aircrash.exe: CMakeFiles/Aircrash.dir/src/shader.cpp.obj
Aircrash.exe: CMakeFiles/Aircrash.dir/src/stb_image.cpp.obj
Aircrash.exe: CMakeFiles/Aircrash.dir/src/texture.cpp.obj
Aircrash.exe: CMakeFiles/Aircrash.dir/src/tools.cpp.obj
Aircrash.exe: CMakeFiles/Aircrash.dir/build.make
Aircrash.exe: C:/MinGW/lib/libglfw3.a
Aircrash.exe: CMakeFiles/Aircrash.dir/linkLibs.rsp
Aircrash.exe: CMakeFiles/Aircrash.dir/objects1
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=I:/RareMetalSpace/Aircrash/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Aircrash.exe"
	I:/RareMetalSpace/App/CMake/bin/cmake.exe -E rm -f CMakeFiles/Aircrash.dir/objects.a
	C:/MinGW/bin/ar.exe qc CMakeFiles/Aircrash.dir/objects.a @CMakeFiles/Aircrash.dir/objects1
	C:/MinGW/bin/g++.exe -g -static -Wl,--whole-archive CMakeFiles/Aircrash.dir/objects.a -Wl,--no-whole-archive -o Aircrash.exe -Wl,--out-implib,libAircrash.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Aircrash.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/Aircrash.dir/build: Aircrash.exe
.PHONY : CMakeFiles/Aircrash.dir/build

CMakeFiles/Aircrash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Aircrash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Aircrash.dir/clean

CMakeFiles/Aircrash.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" I:/RareMetalSpace/Aircrash I:/RareMetalSpace/Aircrash I:/RareMetalSpace/Aircrash/build I:/RareMetalSpace/Aircrash/build I:/RareMetalSpace/Aircrash/build/CMakeFiles/Aircrash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Aircrash.dir/depend

