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

NAME = libft.a

SRC =		src/base/ft_atoi.c \
			src/base/ft_bzero.c \
			src/base/ft_calloc.c \
			src/base/ft_isalnum.c \
			src/base/ft_isalpha.c \
			src/base/ft_isascii.c \
			src/base/ft_isdigit.c \
			src/base/ft_isprint.c \
			src/base/ft_itoa.c \
			src/base/ft_memchr.c \
			src/base/ft_memcmp.c \
			src/base/ft_memcpy.c \
			src/base/ft_memmove.c \
			src/base/ft_memset.c \
			src/base/ft_putchar_fd.c \
			src/base/ft_putendl_fd.c \
			src/base/ft_putnbr_fd.c \
			src/base/ft_putstr_fd.c \
			src/base/ft_split.c \
			src/base/ft_strchr.c \
			src/base/ft_strdup.c \
			src/base/ft_striteri.c \
			src/base/ft_strjoin.c \
			src/base/ft_strlcat.c \
			src/base/ft_strlcpy.c \
			src/base/ft_strlen.c \
			src/base/ft_strmapi.c \
			src/base/ft_strncmp.c \
			src/base/ft_strnstr.c \
			src/base/ft_strrchr.c \
			src/base/ft_strtrim.c \
			src/base/ft_substr.c \
			src/base/ft_tolower.c \
			src/base/ft_toupper.c

BONUS =		src/bonus/ft_lstadd_back_bonus.c \
			src/bonus/ft_lstadd_front_bonus.c \
			src/bonus/ft_lstclear_bonus.c \
			src/bonus/ft_lstdelone_bonus.c \
			src/bonus/ft_lstiter_bonus.c \
			src/bonus/ft_lstlast_bonus.c \
			src/bonus/ft_lstmap_bonus.c \
			src/bonus/ft_lstnew_bonus.c \
			src/bonus/ft_lstsize_bonus.c

CUSTOM =	$(wildcard src/custom/*.c)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
RM_WIN = del /S /Q
AR = ar crs


OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
CUSTOM_OBJS = $(CUSTOM:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(CUSTOM_OBJS)

clean-win:
	$(RM_WIN) "*.o"

fclean:	clean
	$(RM) $(NAME)

fclean-win:	clean-win
	$(RM_WIN) "$(NAME)"

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

custom: $(OBJS) $(BONUS_OBJS) $(CUSTOM_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS) $(CUSTOM_OBJS)

.PHONY:	all clean clean-win fclean fclean-win re bonus custom# **************************************************************************** #
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

NAME = libft.a

SRC =		src/base/ft_atoi.c \
			src/base/ft_bzero.c \
			src/base/ft_calloc.c \
			src/base/ft_isalnum.c \
			src/base/ft_isalpha.c \
			src/base/ft_isascii.c \
			src/base/ft_isdigit.c \
			src/base/ft_isprint.c \
			src/base/ft_itoa.c \
			src/base/ft_memchr.c \
			src/base/ft_memcmp.c \
			src/base/ft_memcpy.c \
			src/base/ft_memmove.c \
			src/base/ft_memset.c \
			src/base/ft_putchar_fd.c \
			src/base/ft_putendl_fd.c \
			src/base/ft_putnbr_fd.c \
			src/base/ft_putstr_fd.c \
			src/base/ft_split.c \
			src/base/ft_strchr.c \
			src/base/ft_strdup.c \
			src/base/ft_striteri.c \
			src/base/ft_strjoin.c \
			src/base/ft_strlcat.c \
			src/base/ft_strlcpy.c \
			src/base/ft_strlen.c \
			src/base/ft_strmapi.c \
			src/base/ft_strncmp.c \
			src/base/ft_strnstr.c \
			src/base/ft_strrchr.c \
			src/base/ft_strtrim.c \
			src/base/ft_substr.c \
			src/base/ft_tolower.c \
			src/base/ft_toupper.c

BONUS =		src/bonus/ft_lstadd_back_bonus.c \
			src/bonus/ft_lstadd_front_bonus.c \
			src/bonus/ft_lstclear_bonus.c \
			src/bonus/ft_lstdelone_bonus.c \
			src/bonus/ft_lstiter_bonus.c \
			src/bonus/ft_lstlast_bonus.c \
			src/bonus/ft_lstmap_bonus.c \
			src/bonus/ft_lstnew_bonus.c \
			src/bonus/ft_lstsize_bonus.c

CUSTOM =	$(wildcard src/custom/*.c)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
RM_WIN = del /S /Q
AR = ar crs

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
CUSTOM_OBJS = $(CUSTOM:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(CUSTOM_OBJS)

clean-win:
	$(RM_WIN) "*.o"

fclean:	clean
	$(RM) $(NAME)

fclean-win:	clean-win
	$(RM_WIN) "$(NAME)"

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

custom: $(OBJS) $(BONUS_OBJS) $(CUSTOM_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS) $(CUSTOM_OBJS)

.PHONY:	all clean clean-win fclean fclean-win re bonus custom