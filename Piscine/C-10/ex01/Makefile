SRCS 	= ./srcs/main.c ./srcs/ft_putstr.c ./srcs/without_args.c ./srcs/ft_putchar.c ./srcs/ft_file_read.c
OBJS	= ${SRCS:.c=.o}
INCS	= includes
NAME	= ft_cat
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

norm :
	norminette */*.[ch]

find_sources :
	@find srcs -type f -name "*.c" | xargs -I{} echo ./{} | tr '\n' ' '

re : fclean all

.PHONY: all clean fclean re .c.o