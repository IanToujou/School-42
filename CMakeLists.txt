cmake_minimum_required(VERSION 3.13)  # CMake version check
project(school_42)                    # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(school_42
		Core/LibFT/libft.h
		Core/LibFT/ft_cos.c
		Core/LibFT/ft_factorial.c
		Core/LibFT/libft.h
		Core/LibFT/ft_sin.c
		Core/LibFT/ft_tan.c
		Core/LibFT/ft_pow.c
		Core/LibFT/main.c
		Core/LibFT/ft_round.c
		Core/LibFT/ft_reduce_angle.c
)