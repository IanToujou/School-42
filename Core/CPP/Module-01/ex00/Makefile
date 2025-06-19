NAME = Zombie

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
ERASE = \033[2K\r

SRC =	src/main.cpp \
		src/newZombie.cpp \
		src/randomChump.cpp \
		src/Zombie.cpp

OBJ = $(SRC:.c=.o)

CC = c++
CFLAGS = -Wall -Werror -Wextra -Ofast -std=c++98
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

clean-win:
	@$(RM_WIN) "*.o"

fclean: clean
	@$(RM) $(NAME)

fclean-win:	clean-win
	@$(RM_WIN) "$(NAME).exe"

re: fclean all

.PHONY: all clean clean-win fclean fclean-win re