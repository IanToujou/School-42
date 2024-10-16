cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Piscine-Reloaded/ex27/includes/display_file.h
		Piscine-Reloaded/ex27/srcs/ft_string_tools.c
        Piscine-Reloaded/ex27/main.c
)