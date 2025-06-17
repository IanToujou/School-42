NAME = miniRT

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m

SRC =	create/create_scene.c \
	main.c \
	render/calculate_lighting.c \
	render/generate_ray.c \
	render/intersect/intersect.c \
	render/intersect/plane.c \
	render/intersect/sphere.c \
	render/intersect/cylinder.c \
	render/render.c \
	render/trace_ray.c \
	utils/vec_add.c \
	utils/vec.c \
	utils/vec_cross.c \
	utils/vec_div.c \
	utils/vec_dot.c \
	utils/vec_mul.c \
	utils/vec_normalize.c \
	utils/vec_sub.c \
	utils/vec_add_value.c \
	utils/vec_len.c \
	utils/add_color.c \
	utils/color_scale.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -I/opt/X11/include
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ) libft mlx
	$(CC) -o $(NAME) $(OBJ) -no-pie -Llib/libft -lft -Llib/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

libft:
	make -C lib/libft custom

mlx:
	make -C lib/mlx

clean:
	$(RM) $(OBJ)
	make -C lib/libft clean
	make -C lib/mlx clean

clean-win:
	$(RM_WIN) "*.o"
	make -C lib/libft clean-win

fclean: clean
	$(RM) $(NAME)
	make -C lib/libft fclean
	make -C lib/mlx clean

fclean-win:	clean-win
	$(RM_WIN) "$(NAME).exe"
	make -C lib/libft fclean-win

re: fclean all

.PHONY: all libft mlx clean clean-win fclean fclean-win re
