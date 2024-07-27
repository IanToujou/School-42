cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Rush-02/srcs/main.c
		Rush-02/srcs/handle_error.c
		Rush-02/srcs/ft_putchar.c
		Rush-02/srcs/ft_putstr.c
		Rush-02/includes/rush.h
)