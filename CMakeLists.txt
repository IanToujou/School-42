cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Rush-02/srcs/main.c
		Rush-02/includes/ft_num.h
		Rush-02/includes/ft_boolean.h
		Rush-02/includes/ft_io.h
		Rush-02/includes/ft_io.h
		Rush-02/srcs/ft_io.c
		Rush-02/srcs/ft_atoi.c
		Rush-02/srcs/ft_string_utils.c
		Rush-02/includes/ft_string_utils.h
		Rush-02/srcs/ft_atoi_strict.c
		Rush-02/includes/ft_convert.h
)