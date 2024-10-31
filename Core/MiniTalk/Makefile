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

HEADERS = include/minitalk.h

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
LDFLAGS = -Lft_printf -lft_printf
RM = rm -rf
RM_WIN = del /S /Q

FTPRINTF = lib/ft_printf/libftprintf.a
FTPRINTF_PATH = lib/ft_printf/

SERVER_OBJS = $(SERVER_SRC:src/%.c=%.o)
CLIENT_OBJS = $(CLIENT_SRC:src/%.c=%.o)

%.o: src/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

all: ft_printf server client

ft_printf:
	$(MAKE) -C $(FTPRINTF_PATH)

server: $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) $(LDFLAGS) -o server

client: $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) $(LDFLAGS) -o client

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(MAKE) clean -C $(FTPRINTF_PATH)

clean-win:
	$(RM_WIN) "*.o"
	$(MAKE) clean-win -C $(FTPRINTF_PATH)

fclean:	clean
	$(RM) client server
	$(MAKE) fclean -C $(FTPRINTF_PATH)

fclean-win:	clean-win
	$(RM_WIN) client server
	$(MAKE) fclean-win -C $(FTPRINTF_PATH)

re:	fclean all

.PHONY:	all printf server client bonus clean clean-win fclean fclean-win re