SRCS = ./srcs/main.c ./srcs/ft_putstr.c ./srcs/without_args.c ./srcs/ft_putchar.c ./srcs/ft_file_read.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = ft_cat
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
