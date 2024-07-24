# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibour <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 14:07:11 by ibour             #+#    #+#              #
#    Updated: 2024/07/24 14:07:12 by ibour            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/without_args.c
INCS = includes/
OBJS = ${SRCS:.c=.o}
NAME = ft_cat
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS} ${CFLAGS}

all:	${NAME}

clean: ${RM} ${OBJS}

fclean: ${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re