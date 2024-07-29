SRCS = ./srcs/main.c ./srcs/string_utils.c ./srcs/ft_file_read.c
INCS = includes/
OBJS = ${SRCS:.c=.o}
NAME = ft_tail
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

.PHONY:	all clean fclean re .c.o
