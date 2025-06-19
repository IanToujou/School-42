NAME = miniRT

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m

SRC =	src/create/create_scene.c \
		src/main/main.c \
		src/render/calculate_lighting.c \
		src/render/generate_ray.c \
		src/object/intersect.c \
		src/object/plane.c \
		src/object/sphere.c \
		src/object/cylinder.c \
		src/render/render.c \
		src/render/trace_ray.c \
		src/utils/vec_add.c \
		src/utils/vec.c \
		src/utils/vec_cross.c \
		src/utils/vec_div.c \
		src/utils/vec_dot.c \
		src/utils/vec_mul.c \
		src/utils/vec_normalize.c \
		src/utils/vec_sub.c \
		src/utils/vec_add_value.c \
		src/utils/vec_len.c \
		src/utils/add_color.c \
		src/utils/color_scale.c

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
