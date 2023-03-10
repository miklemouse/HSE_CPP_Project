# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.23.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.23.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/michaelrus/Documents/Studying/cpp/WineShop27-final-clean

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michaelrus/Documents/Studying/cpp/WineShop27-final-clean

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.23.2/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.23.2/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/michaelrus/Documents/Studying/cpp/WineShop27-final-clean/CMakeFiles /Users/michaelrus/Documents/Studying/cpp/WineShop27-final-clean//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/michaelrus/Documents/Studying/cpp/WineShop27-final-clean/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named WineShop

# Build rule for target.
WineShop: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 WineShop
.PHONY : WineShop

# fast build rule for target.
WineShop/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/build
.PHONY : WineShop/fast

#=============================================================================
# Target rules for targets named WineShop_autogen

# Build rule for target.
WineShop_autogen: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 WineShop_autogen
.PHONY : WineShop_autogen

# fast build rule for target.
WineShop_autogen/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop_autogen.dir/build.make CMakeFiles/WineShop_autogen.dir/build
.PHONY : WineShop_autogen/fast

CartFilterModel.o: CartFilterModel.cpp.o
.PHONY : CartFilterModel.o

# target to build an object file
CartFilterModel.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/CartFilterModel.cpp.o
.PHONY : CartFilterModel.cpp.o

CartFilterModel.i: CartFilterModel.cpp.i
.PHONY : CartFilterModel.i

# target to preprocess a source file
CartFilterModel.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/CartFilterModel.cpp.i
.PHONY : CartFilterModel.cpp.i

CartFilterModel.s: CartFilterModel.cpp.s
.PHONY : CartFilterModel.s

# target to generate assembly for a file
CartFilterModel.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/CartFilterModel.cpp.s
.PHONY : CartFilterModel.cpp.s

LogoWidget.o: LogoWidget.cpp.o
.PHONY : LogoWidget.o

# target to build an object file
LogoWidget.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/LogoWidget.cpp.o
.PHONY : LogoWidget.cpp.o

LogoWidget.i: LogoWidget.cpp.i
.PHONY : LogoWidget.i

# target to preprocess a source file
LogoWidget.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/LogoWidget.cpp.i
.PHONY : LogoWidget.cpp.i

LogoWidget.s: LogoWidget.cpp.s
.PHONY : LogoWidget.s

# target to generate assembly for a file
LogoWidget.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/LogoWidget.cpp.s
.PHONY : LogoWidget.cpp.s

MainFilterModel.o: MainFilterModel.cpp.o
.PHONY : MainFilterModel.o

# target to build an object file
MainFilterModel.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/MainFilterModel.cpp.o
.PHONY : MainFilterModel.cpp.o

MainFilterModel.i: MainFilterModel.cpp.i
.PHONY : MainFilterModel.i

# target to preprocess a source file
MainFilterModel.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/MainFilterModel.cpp.i
.PHONY : MainFilterModel.cpp.i

MainFilterModel.s: MainFilterModel.cpp.s
.PHONY : MainFilterModel.s

# target to generate assembly for a file
MainFilterModel.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/MainFilterModel.cpp.s
.PHONY : MainFilterModel.cpp.s

WineShop_autogen/mocs_compilation.o: WineShop_autogen/mocs_compilation.cpp.o
.PHONY : WineShop_autogen/mocs_compilation.o

# target to build an object file
WineShop_autogen/mocs_compilation.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/WineShop_autogen/mocs_compilation.cpp.o
.PHONY : WineShop_autogen/mocs_compilation.cpp.o

WineShop_autogen/mocs_compilation.i: WineShop_autogen/mocs_compilation.cpp.i
.PHONY : WineShop_autogen/mocs_compilation.i

# target to preprocess a source file
WineShop_autogen/mocs_compilation.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/WineShop_autogen/mocs_compilation.cpp.i
.PHONY : WineShop_autogen/mocs_compilation.cpp.i

WineShop_autogen/mocs_compilation.s: WineShop_autogen/mocs_compilation.cpp.s
.PHONY : WineShop_autogen/mocs_compilation.s

# target to generate assembly for a file
WineShop_autogen/mocs_compilation.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/WineShop_autogen/mocs_compilation.cpp.s
.PHONY : WineShop_autogen/mocs_compilation.cpp.s

WineTable.o: WineTable.cpp.o
.PHONY : WineTable.o

# target to build an object file
WineTable.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/WineTable.cpp.o
.PHONY : WineTable.cpp.o

WineTable.i: WineTable.cpp.i
.PHONY : WineTable.i

# target to preprocess a source file
WineTable.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/WineTable.cpp.i
.PHONY : WineTable.cpp.i

WineTable.s: WineTable.cpp.s
.PHONY : WineTable.s

# target to generate assembly for a file
WineTable.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/WineTable.cpp.s
.PHONY : WineTable.cpp.s

cartwindow.o: cartwindow.cpp.o
.PHONY : cartwindow.o

# target to build an object file
cartwindow.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/cartwindow.cpp.o
.PHONY : cartwindow.cpp.o

cartwindow.i: cartwindow.cpp.i
.PHONY : cartwindow.i

# target to preprocess a source file
cartwindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/cartwindow.cpp.i
.PHONY : cartwindow.cpp.i

cartwindow.s: cartwindow.cpp.s
.PHONY : cartwindow.s

# target to generate assembly for a file
cartwindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/cartwindow.cpp.s
.PHONY : cartwindow.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/main.cpp.s
.PHONY : main.cpp.s

mainwindow.o: mainwindow.cpp.o
.PHONY : mainwindow.o

# target to build an object file
mainwindow.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/mainwindow.cpp.o
.PHONY : mainwindow.cpp.o

mainwindow.i: mainwindow.cpp.i
.PHONY : mainwindow.i

# target to preprocess a source file
mainwindow.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/mainwindow.cpp.i
.PHONY : mainwindow.cpp.i

mainwindow.s: mainwindow.cpp.s
.PHONY : mainwindow.s

# target to generate assembly for a file
mainwindow.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/WineShop.dir/build.make CMakeFiles/WineShop.dir/mainwindow.cpp.s
.PHONY : mainwindow.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... WineShop_autogen"
	@echo "... WineShop"
	@echo "... CartFilterModel.o"
	@echo "... CartFilterModel.i"
	@echo "... CartFilterModel.s"
	@echo "... LogoWidget.o"
	@echo "... LogoWidget.i"
	@echo "... LogoWidget.s"
	@echo "... MainFilterModel.o"
	@echo "... MainFilterModel.i"
	@echo "... MainFilterModel.s"
	@echo "... WineShop_autogen/mocs_compilation.o"
	@echo "... WineShop_autogen/mocs_compilation.i"
	@echo "... WineShop_autogen/mocs_compilation.s"
	@echo "... WineTable.o"
	@echo "... WineTable.i"
	@echo "... WineTable.s"
	@echo "... cartwindow.o"
	@echo "... cartwindow.i"
	@echo "... cartwindow.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... mainwindow.o"
	@echo "... mainwindow.i"
	@echo "... mainwindow.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

