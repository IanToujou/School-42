# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibour <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 10:29:54 by ibour             #+#    #+#              #
#    Updated: 2024/07/23 10:29:55 by ibour            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/main.c \
		srcs/ft_string_tools.c

OBJS = ${SRCS:.c=.o}
INCLUDES = includes
NAME = ft_display_file
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) ${CFLAGS} ${OBJS} -o ${NAME}

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus
