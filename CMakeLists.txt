cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Core/LibFT/ft_bzero.c
		Core/LibFT/ft_strtrim.c
		Core/LibFT/ft_memcmp.c
		Core/LibFT/ft_atoi.c
		Core/LibFT/ft_calloc.c
		Core/LibFT/ft_isalnum.c
		Core/LibFT/ft_lstnew.c
		Core/LibFT/ft_pow.c
)