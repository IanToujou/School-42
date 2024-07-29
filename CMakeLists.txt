cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		C-10/ex02/srcs/main.c
		C-10/ex02/includes/ft_tail.h
		C-10/ex02/srcs/string_utils.c
		C-10/ex02/srcs/ft_file_read.c
)