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

SRC = main.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS)  $(BONUS_OBJS)

.PHONY:	all clean fclean re bonus