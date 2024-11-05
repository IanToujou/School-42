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

NAME = minitalk

SERVER_SRC =	src/server.c
CLIENT_SRC =	src/client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: server client

libft:
	make -C lib/libft custom

server: $(SERVER_OBJ) libft
	$(CC) -o $@ $< -Llib/libft -lft

client: $(CLIENT_OBJ) libft
	$(CC) -o $@ $< -Llib/libft -lft

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C lib/libft clean

fclean: clean
	$(RM) server client
	make -C lib/libft fclean

re: fclean all

.PHONY: all libft clean fclean re
