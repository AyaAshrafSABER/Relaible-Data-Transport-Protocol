# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ServerSide.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ServerSide.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ServerSide.dir/flags.make

CMakeFiles/ServerSide.dir/main.cpp.o: CMakeFiles/ServerSide.dir/flags.make
CMakeFiles/ServerSide.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ServerSide.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerSide.dir/main.cpp.o -c /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/main.cpp

CMakeFiles/ServerSide.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerSide.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/main.cpp > CMakeFiles/ServerSide.dir/main.cpp.i

CMakeFiles/ServerSide.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerSide.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/main.cpp -o CMakeFiles/ServerSide.dir/main.cpp.s

CMakeFiles/ServerSide.dir/ServerManager.cpp.o: CMakeFiles/ServerSide.dir/flags.make
CMakeFiles/ServerSide.dir/ServerManager.cpp.o: ../ServerManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ServerSide.dir/ServerManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerSide.dir/ServerManager.cpp.o -c /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/ServerManager.cpp

CMakeFiles/ServerSide.dir/ServerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerSide.dir/ServerManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/ServerManager.cpp > CMakeFiles/ServerSide.dir/ServerManager.cpp.i

CMakeFiles/ServerSide.dir/ServerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerSide.dir/ServerManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/ServerManager.cpp -o CMakeFiles/ServerSide.dir/ServerManager.cpp.s

CMakeFiles/ServerSide.dir/Sender.cpp.o: CMakeFiles/ServerSide.dir/flags.make
CMakeFiles/ServerSide.dir/Sender.cpp.o: ../Sender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ServerSide.dir/Sender.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerSide.dir/Sender.cpp.o -c /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/Sender.cpp

CMakeFiles/ServerSide.dir/Sender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerSide.dir/Sender.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/Sender.cpp > CMakeFiles/ServerSide.dir/Sender.cpp.i

CMakeFiles/ServerSide.dir/Sender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerSide.dir/Sender.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/Sender.cpp -o CMakeFiles/ServerSide.dir/Sender.cpp.s

CMakeFiles/ServerSide.dir/Receiver.cpp.o: CMakeFiles/ServerSide.dir/flags.make
CMakeFiles/ServerSide.dir/Receiver.cpp.o: ../Receiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ServerSide.dir/Receiver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerSide.dir/Receiver.cpp.o -c /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/Receiver.cpp

CMakeFiles/ServerSide.dir/Receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerSide.dir/Receiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/Receiver.cpp > CMakeFiles/ServerSide.dir/Receiver.cpp.i

CMakeFiles/ServerSide.dir/Receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerSide.dir/Receiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/Receiver.cpp -o CMakeFiles/ServerSide.dir/Receiver.cpp.s

CMakeFiles/ServerSide.dir/PacketHandler.cpp.o: CMakeFiles/ServerSide.dir/flags.make
CMakeFiles/ServerSide.dir/PacketHandler.cpp.o: ../PacketHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ServerSide.dir/PacketHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerSide.dir/PacketHandler.cpp.o -c /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/PacketHandler.cpp

CMakeFiles/ServerSide.dir/PacketHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerSide.dir/PacketHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/PacketHandler.cpp > CMakeFiles/ServerSide.dir/PacketHandler.cpp.i

CMakeFiles/ServerSide.dir/PacketHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerSide.dir/PacketHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/PacketHandler.cpp -o CMakeFiles/ServerSide.dir/PacketHandler.cpp.s

CMakeFiles/ServerSide.dir/Utilities.cpp.o: CMakeFiles/ServerSide.dir/flags.make
CMakeFiles/ServerSide.dir/Utilities.cpp.o: ../Utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ServerSide.dir/Utilities.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ServerSide.dir/Utilities.cpp.o -c /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/Utilities.cpp

CMakeFiles/ServerSide.dir/Utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ServerSide.dir/Utilities.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/Utilities.cpp > CMakeFiles/ServerSide.dir/Utilities.cpp.i

CMakeFiles/ServerSide.dir/Utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ServerSide.dir/Utilities.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/Utilities.cpp -o CMakeFiles/ServerSide.dir/Utilities.cpp.s

# Object files for target ServerSide
ServerSide_OBJECTS = \
"CMakeFiles/ServerSide.dir/main.cpp.o" \
"CMakeFiles/ServerSide.dir/ServerManager.cpp.o" \
"CMakeFiles/ServerSide.dir/Sender.cpp.o" \
"CMakeFiles/ServerSide.dir/Receiver.cpp.o" \
"CMakeFiles/ServerSide.dir/PacketHandler.cpp.o" \
"CMakeFiles/ServerSide.dir/Utilities.cpp.o"

# External object files for target ServerSide
ServerSide_EXTERNAL_OBJECTS =

ServerSide: CMakeFiles/ServerSide.dir/main.cpp.o
ServerSide: CMakeFiles/ServerSide.dir/ServerManager.cpp.o
ServerSide: CMakeFiles/ServerSide.dir/Sender.cpp.o
ServerSide: CMakeFiles/ServerSide.dir/Receiver.cpp.o
ServerSide: CMakeFiles/ServerSide.dir/PacketHandler.cpp.o
ServerSide: CMakeFiles/ServerSide.dir/Utilities.cpp.o
ServerSide: CMakeFiles/ServerSide.dir/build.make
ServerSide: CMakeFiles/ServerSide.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ServerSide"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ServerSide.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ServerSide.dir/build: ServerSide

.PHONY : CMakeFiles/ServerSide.dir/build

CMakeFiles/ServerSide.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ServerSide.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ServerSide.dir/clean

CMakeFiles/ServerSide.dir/depend:
	cd /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug /home/saber/CLionProjects/Relaible-Data-Transport-Protocol/ServerSide/cmake-build-debug/CMakeFiles/ServerSide.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ServerSide.dir/depend

