cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Piscine-Reloaded/ex11/ft_div_mod.c
		Piscine-Reloaded/ex12/ft_iterative_factorial.c
		Piscine-Reloaded/ex13/ft_recursive_factorial.c
		Piscine-Reloaded/ex14/ft_sqrt.c
		Piscine-Reloaded/ex15/ft_putstr.c
		Piscine-Reloaded/ex16/ft_strlen.c
		Piscine-Reloaded/ex17/ft_strcmp.c
		Piscine-Reloaded/ex18/ft_print_params.c
		Piscine-Reloaded/ex19/ft_sort_params.c
		Piscine/C-06/ex03/ft_sort_params.c
		Piscine-Reloaded/ex20/ft_strdup.c
		Piscine-Reloaded/ex21/ft_range.c
		Piscine-Reloaded/ex22/ft_abs.h
		Piscine-Reloaded/ex23/ft_point.h
		Piscine-Reloaded/ex25/ft_foreach.c
		Piscine-Reloaded/ex26/ft_count_if.c
		Piscine-Reloaded/ex27/includes/display_file.h
)