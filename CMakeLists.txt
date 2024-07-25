cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		C-10/ex02/srcs/main.c
		C-10/ex02/includes/ft.h
		C-10/ex02/srcs/no_args.c
		C-10/ex02/srcs/print.c
		C-00/ex08/ft_print_combn.c
		C-01/ex08/ft_sort_int_tab.c
)