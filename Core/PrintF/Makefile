# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibour <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 10:29:54 by ibour             #+#    #+#              #
#    Updated: 2024/09/07 10:29:55 by ibour            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	src/ft_printf.c \
		src/ft_print_char.c \
		src/ft_print_str.c \
		src/ft_print_num.c \
		src/ft_print_num_base.c \
		src/ft_print_num_unsigned.c \
		src/ft_print_ptr.c \
		src/ft_print_hex.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I .
RM = rm -rf
RM_WIN = del /S /Q
AR = ar crs

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

clean-win:
	$(RM_WIN) "*.o"

fclean:	clean
	$(RM) $(NAME)

fclean-win:	clean-win
	$(RM_WIN) "$(NAME)"

re:	fclean all

.PHONY:	all clean clean-win fclean fclean-win re