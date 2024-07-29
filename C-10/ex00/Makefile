SRCS = srcs/main.c srcs/ft_string_tools.c
OBJS = ${SRCS:.c=.o}
INCS = includes
NAME = ft_display_file
CC = clang
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
