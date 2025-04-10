RESET  = \033[0m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
CYAN   = \033[36m
RED    = \033[31m

NAME = cub3d

SRC =	src/main/main.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -I/opt/X11/include
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ) libft mlx
	$(CC) -o $(NAME) $(OBJ) -Llib/libft -lft -Llib/mlx -lmlx -L/usr/lib/X11 -lXext -lX11

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
