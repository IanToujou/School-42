cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Piscine/C-02/ex09/ft_strcapitalize.c
		Core/LibFT/ft_memset.c
		Core/LibFT/libft.h
		Core/LibFT/ft_bzero.c
		Core/LibFT/ft_memcpy.c
		Core/LibFT/ft_isascii.c
		Core/LibFT/ft_isdigit.c
		Core/LibFT/ft_memccpy.c
		Core/LibFT/ft_memmove.c
)