cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		BSQ/ex00/srcs/main.c
		BSQ/ex00/includes/bsq.h
		BSQ/ex00/srcs/parse.c
		BSQ/ex00/srcs/free_grid.c
		BSQ/ex00/srcs/grid.c
		BSQ/ex00/srcs/solution.c
)