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

SRC =	ft_printf.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_num.c \
		ft_print_num_base.c \
		ft_print_num_unsigned.c \
		ft_print_ptr.c \
		ft_print_hex.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

OBJS = $(SRC:.c=.o)

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

.PHONY:	all clean fclean re