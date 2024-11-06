# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibour <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 10:29:54 by ibour             #+#    #+#              #
#    Updated: 2024/08/05 10:29:55 by ibour            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	src/main/main.c \
		src/main/push_swap.c \
		src/main/ft_atoi_check_valid.c \
		src/handler/ft_handle_error.c \
		src/util/ft_util_check_ab.c \
		src/util/ft_util_check_ba.c \
		src/stack/ft_stack_add_back.c \
        src/stack/ft_stack_check_duplicate.c \
        src/stack/ft_stack_check_sort.c \
        src/stack/ft_stack_free.c \
        src/stack/ft_stack_index.c \
        src/stack/ft_stack_last.c \
        src/stack/ft_stack_max.c \
        src/stack/ft_stack_min.c \
        src/stack/ft_stack_new.c \
        src/stack/ft_stack_place.c \
        src/stack/ft_stack_size.c \
        src/stack/ft_stack_sort.c \
        src/stack/ft_stack_sort_mini.c \
        src/algo/ft_algo_pa.c \
        src/algo/ft_algo_pb.c \
        src/algo/ft_algo_ra.c \
        src/algo/ft_algo_rb.c \
        src/algo/ft_algo_rotate.c \
        src/algo/ft_algo_rotate_push.c \
        src/algo/ft_algo_rr.c \
        src/algo/ft_algo_rra.c \
        src/algo/ft_algo_rrb.c \
        src/algo/ft_algo_rrr.c \
        src/algo/ft_algo_sa.c \
        src/algo/ft_algo_sb.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ) libft
	$(CC) -o $(NAME) $(OBJ) -Llib/libft -lft

libft:
	make -C lib/libft custom

clean:
	$(RM) $(OBJ)
	make -C lib/libft clean

clean-win:
	$(RM_WIN) "*.o"
	make -C lib/libft clean-win

fclean: clean
	$(RM) $(NAME)
	make -C lib/libft fclean

fclean-win:	clean-win
	$(RM_WIN) "$(NAME).exe"
	make -C lib/libft fclean-win

re: fclean all

.PHONY: all libft clean clean-win fclean fclean-win re
