cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Core/LibFT/ft_memccpy.c
		Core/LibFT/ft_isblank.c
		Core/LibFT/ft_isspace.c
		Core/PrintF/ft_printf.c
		Core/LibFT/ft_hashcode.c
		Core/LibFT/ft_hashnew.c
		Core/LibFT/ft_hashinsert.c
		Core/LibFT/ft_strdup.c
		Core/LibFT/ft_hashsearch.c
		Core/LibFT/ft_hashdel.c
		Core/LibFT/ft_hashclear.c
		Core/LibFT/main.c
		Core/LibFT/ft_strcmp.c
		Core/LibFT/ft_strlen.c
		Core/LibFT/ft_memcpy.c
)