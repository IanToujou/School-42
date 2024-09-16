cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Core/GetNextLine/get_next_line.c
		Core/GetNextLine/get_next_line.h
		Core/GetNextLine/get_next_line_utils.c
		Core/GetNextLine/main.c
)