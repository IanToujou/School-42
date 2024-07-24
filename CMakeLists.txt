cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		C-05/ex05/ft_sqrt.c
		C-10/ex01/srcs/main.c
		C-10/ex01/srcs/without_args.c
		C-10/ex01/includes/ft.h
		C-10/ex01/srcs/ft_putchar.c
		C-10/ex01/srcs/ft_file_read.c
)