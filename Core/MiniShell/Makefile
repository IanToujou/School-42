# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibour <support@toujoustudios.net>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 10:29:54 by ibour             #+#    #+#              #
#    Updated: 2024/08/05 10:29:55 by ibour            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	src/error/ft_error_throw.c \
		src/exit/ft_exit_main.c \
		src/init/ft_init_main.c \
		src/util/ft_util_banner.c \
		src/parse/ft_parse_env.c \
		src/main/main.c \
		src/util/ft_util_env.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ) libft
	$(CC) -o $(NAME) $(OBJ) -Llib/libft -lft

libft:
	make -C lib/libft custom

clean:
	$(RM) $(OBJ)
	make -C lib/libft clean

clean-win:
	$(RM_WIN) "*.o"
	make -C lib/libft clean-win

fclean: clean
	$(RM) $(NAME)
	make -C lib/libft fclean

fclean-win:	clean-win
	$(RM_WIN) "$(NAME).exe"
	make -C lib/libft fclean-win

re: fclean all

bclean: all clean

.PHONY: all libft clean clean-win fclean fclean-win re bclean
