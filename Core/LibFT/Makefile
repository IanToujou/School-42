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

SRC =		$(wildcard src/base/*.c)

BONUS =		$(wildcard src/bonus/*.c)

CUSTOM =	$(wildcard src/custom/*.c)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
RM_WIN = del /S /Q
AR = ar crs

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
CUSTOM_OBJS = $(CUSTOM:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(CUSTOM_OBJS)

clean-win:
	$(RM_WIN) "*.o"

fclean:	clean
	$(RM) $(NAME)

fclean-win:	clean-win
	$(RM_WIN) "$(NAME)"

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

custom: $(OBJS) $(BONUS_OBJS) $(CUSTOM_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS) $(CUSTOM_OBJS)

.PHONY:	all clean clean-win fclean fclean-win re bonus custom