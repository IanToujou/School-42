# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibour <support@toujoustudios.net>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 10:29:54 by ibour             #+#    #+#              #
#    Updated: 2024/08/05 10:29:55 by ibour            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

SRC =	src/Main.cpp \
		src/PhoneBook.cpp \
		src/Contact.cpp

OBJ = $(SRC:.c=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

clean-win:
	$(RM_WIN) "*.o"

fclean: clean
	$(RM) $(NAME)

fclean-win:	clean-win
	$(RM_WIN) "$(NAME).exe"

re: fclean all

.PHONY: all clean clean-win fclean fclean-win re
