cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		"C-02/ex00/ft_strcpy.c"
		C-00/ex00/ft_putchar.c
		C-00/ex05/ft_print_comb.c
)