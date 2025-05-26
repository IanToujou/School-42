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

NAME = minishell

SRC =	src/cmd/exit/ft_cmd_exit.c \
		src/cmd/env/ft_cmd_env.c \
		src/cmd/unset/ft_cmd_unset.c \
		src/cmd/export/ft_cmd_export.c \
		src/cmd/echo/ft_cmd_echo.c \
		src/cmd/cd/ft_cmd_cd.c \
		src/cmd/nya/ft_cmd_nya.c \
		src/cmd/pwd/ft_cmd_pwd.c \
		src/error/ft_error_throw.c \
		src/error/ft_error_check.c \
		src/exit/ft_exit_main.c \
		src/init/ft_init_main.c \
		src/init/ft_init_parse.c \
		src/init/ft_init_quote.c \
		src/init/ft_init_shell.c \
		src/init/ft_init_token.c \
		src/main/main.c \
		src/parse/ft_parse_dollar.c \
		src/parse/ft_parse_env.c \
		src/parse/ft_parse_handle.c \
		src/parse/ft_parse_input.c \
		src/run/ft_run_bin.c \
		src/run/ft_run_cmd.c \
		src/run/ft_run_defined.c \
		src/run/ft_run_token.c \
		src/signal/ft_signal.c \
		src/signal/ft_signal_add.c \
		src/util/ft_util_banner.c \
		src/util/ft_util_cmd.c \
		src/util/ft_util_cmd_2.c \
		src/util/ft_util_cmd_3.c \
		src/util/ft_util_env.c \
		src/util/ft_util_env_2.c \
		src/util/ft_util_env_3.c \
		src/util/ft_util_env_4.c \
		src/util/ft_util_envcase.c \
		src/util/ft_util_num.c \
		src/util/ft_util_quote.c \
		src/util/ft_util_quote2.c \
		src/util/ft_util_redirect.c \
		src/util/ft_util_redirect2.c \
		src/util/ft_util_redirect3.c \
		src/util/ft_util_str.c \
		src/util/ft_util_token.c \
		src/util/ft_util_token_2.c \
		src/util/ft_util_token_3.c \
		src/util/ft_util_token_4.c \
		src/util/ft_util_prompt.c \
		src/util/ft_util_bin.c \
		src/util/ft_util_bin_2.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(OBJ) libft
	$(CC) -o $(NAME) $(OBJ) -Llib/libft -lft -lreadline -lhistory

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

bclean: all clean

.PHONY: all libft clean clean-win fclean fclean-win re bclean
