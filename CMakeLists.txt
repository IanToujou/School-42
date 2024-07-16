cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		C-03/ex00/ft_strcmp.c
		C-03/ex01/ft_strncmp.c
		C-03/ex02/ft_strcat.c
		C-02/ex00/ft_strcpy.c
		C-03/ex03/ft_strncat.c
		C-03/ex04/ft_strstr.c
		C-03/ex05/ft_strlcat.c
)