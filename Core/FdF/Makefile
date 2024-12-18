# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibour <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 10:29:54 by ibour             #+#    #+#              #
#    Updated: 2024/08/05 10:29:55 by ibour            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =	src/error/ft_error_throw.c \
		src/event/ft_event_close.c \
		src/event/ft_event_keypress.c \
		src/graphics/ft_gfx_render.c \
		src/init/ft_init_data.c \
		src/init/ft_init_hooks.c \
		src/init/ft_init_map.c \
		src/init/ft_init_mlx.c \
		src/main/main.c \
		src/util/ft_util_algo.c \
		src/util/ft_util_draw.c \
		src/util/ft_util_free.c \
		src/util/ft_util_parse.c \
		src/util/ft_util_str.c \

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -I/opt/X11/include
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ) libft mlx
	$(CC) -o $(NAME) $(OBJ) -Llib/libft -lft -Llib/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

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
