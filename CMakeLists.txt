cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Rush-01/ex00/rush-01.c
		Rush-01/ex00/str_tools.c
		C-07/ex00/ft_strdup.c
		C-07/ex01/ft_range.c
		C-00/ex07/ft_putnbr.c
)