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

SRCS	= srcs/ft_array.c srcs/ft_atoi.c srcs/ft_atoi_strict.c srcs/ft_dictionary.c srcs/ft_dictionary_io.c srcs/ft_dictionary_sort.c srcs/ft_dictionary_sort_extra.c srcs/ft_file.c srcs/ft_io.c srcs/ft_itow.c srcs/ft_string_utils.c srcs/ft_string_utils_check.c srcs/main.c srcs/ft_string_utils_extra.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= rush-02
CC		= gcc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror

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
