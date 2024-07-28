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

SRCS = srcs/main.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/without_args.c srcs/ft_file_read.c
INCS = includes/
OBJS = ${SRCS:.c=.o}
NAME = ft_cat
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS} ${CFLAGS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]

.PHONY: all clean fclean re .c.o norm
