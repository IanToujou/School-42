cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Core/PrintF/ft_printf.c
		Core/PrintF/ft_printf.h
		Core/PrintF/ft_print_char.c
		Core/PrintF/main.c
		Core/PrintF/ft_print_num.c
		Core/PrintF/ft_print_ptr.c
		Core/PrintF/ft_print_str.c
		Core/PrintF/ft_print_hex.c
		Core/PrintF/ft_num_base.c
		Core/PrintF/ft_print_num_unsigned.c
		Core/PrintF/ft_print_num_base.c
		Core/GetNextLine/get_next_line.c
		Core/GetNextLine/get_next_line.h
)