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

RESET  = \033[0m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
CYAN   = \033[36m
RED    = \033[31m

NAME = philo

SRC =	src/error/ft_throw_error.c \
		src/init/ft_init_data.c \
		src/main/main.c \
		src/util/ft_util_atoi.c \
		src/util/ft_util_str.c \
		src/util/ft_util_validate.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -I/opt/X11/include
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	@echo "$(BLUE)Linking object files to create the executable $(CYAN)$(NAME)$(BLUE)...$(RESET)"
	@$(CC) -o $(NAME) $(OBJ)
	@echo "$(GREEN)Build complete!$(RESET) Run $(CYAN)./$(NAME)$(RESET) to execute."

clean:
	@echo "$(RED)Cleaning up object files...$(RESET)"
	@$(RM) $(OBJ)
	@echo "$(GREEN)Cleanup complete.$(RESET)"

clean-win:
	@echo "$(RED)Cleaning up object files (Windows)...$(RESET)"
	@$(RM_WIN) "*.o"
	@echo "$(GREEN)Cleanup complete (Windows).$(RESET)"

fclean: clean
	@echo "$(RED)Removing the executable $(CYAN)$(NAME)$(RED)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)Full cleanup complete.$(RESET)"

fclean-win: clean-win
	@echo "$(RED)Removing the executable $(CYAN)$(NAME).exe$(RED)...$(RESET)"
	@$(RM_WIN) "$(NAME).exe"
	@echo "$(GREEN)Full cleanup complete (Windows).$(RESET)"

re: fclean all

.PHONY: all clean clean-win fclean fclean-win re