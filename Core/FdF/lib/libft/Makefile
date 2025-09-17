NAME = libft.a

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
ERASE := \033[2K\r
END := \033[0m

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
			src/base/ft_toupper.c \
			src/bonus/ft_lstadd_back_bonus.c \
			src/bonus/ft_lstadd_front_bonus.c \
			src/bonus/ft_lstclear_bonus.c \
			src/bonus/ft_lstdelone_bonus.c \
			src/bonus/ft_lstiter_bonus.c \
			src/bonus/ft_lstlast_bonus.c \
			src/bonus/ft_lstmap_bonus.c \
			src/bonus/ft_lstnew_bonus.c \
			src/bonus/ft_lstsize_bonus.c \
			src/custom/ft_ceil.c \
			src/custom/ft_factorial.c \
			src/custom/ft_floor.c \
			src/custom/ft_hashclear.c \
			src/custom/ft_hashcode.c \
			src/custom/ft_hashdel.c \
			src/custom/ft_hashinsert.c \
			src/custom/ft_hashnew.c \
			src/custom/ft_hashsearch.c \
			src/custom/ft_isblank.c \
			src/custom/ft_isspace.c \
			src/custom/ft_max.c \
			src/custom/ft_memccpy.c \
			src/custom/ft_memdel.c \
			src/custom/ft_min.c \
			src/custom/ft_overflow.c \
			src/custom/ft_pow.c \
			src/custom/ft_putchar.c \
			src/custom/ft_putnbr.c \
			src/custom/ft_putstr.c \
			src/custom/ft_round.c \
			src/custom/ft_strcat.c \
			src/custom/ft_strclr.c \
			src/custom/ft_strcmp.c \
			src/custom/ft_strcpy.c \
			src/custom/ft_strdel.c \
			src/custom/ft_strequ.c \
			src/custom/ft_striter.c \
			src/custom/ft_strmap.c \
			src/custom/ft_strncat.c \
			src/custom/ft_strncpy.c \
			src/custom/ft_strnequ.c \
			src/custom/ft_strnew.c \
			src/custom/ft_strstr.c \
			src/other/printf/ft_print_char.c \
			src/other/printf/ft_print_hex.c \
			src/other/printf/ft_print_num.c \
			src/other/printf/ft_print_num_base.c \
			src/other/printf/ft_print_num_unsigned.c \
			src/other/printf/ft_print_ptr.c \
			src/other/printf/ft_print_str.c \
			src/other/printf/ft_printf.c \
			src/other/getnextline/get_next_line.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -march=native -ffast-math -flto
RM = rm -rf
RM_WIN = del /S /Q
AR = ar rcs
RANLIB = ranlib

OBJS = $(SRC:.c=.o)
TOTAL_FILES = $(words $(SRC))
COMPILED_FILES = 0

$(NAME): $(OBJS)
	$(AR) $@ $^
	$(RANLIB) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES) + 1))))
	@TERM_WIDTH=$$(tput cols); \
	BAR_WIDTH=$$((TERM_WIDTH - 17)); \
	PROGRESS=$$(($(COMPILED_FILES) * BAR_WIDTH / $(TOTAL_FILES))); \
	PERCENTAGE=$$(echo "scale=1; $(COMPILED_FILES) * 100 / $(TOTAL_FILES)" | bc); \
	SPINNER_FRAMES="|/-\\"; \
	SPINNER_INDEX=$$(($(COMPILED_FILES) / 2 % 4)); \
	SPINNER_CHAR=$$(printf "$$SPINNER_FRAMES" | cut -c$$((SPINNER_INDEX + 1))); \
	printf "$(ERASE)2/4 $$SPINNER_CHAR ["; \
	for i in $$(seq 1 $$PROGRESS); do printf "█"; done; \
	for i in $$(seq $$((PROGRESS + 1)) $$BAR_WIDTH); do printf "."; done; \
	printf "] %s%%" "$$PERCENTAGE"

all: $(NAME)

clean:
	$(RM) $(OBJS)

clean-win:
	$(RM_WIN) "*.o"

fclean:	clean
	$(RM) $(NAME)

fclean-win:	clean-win
	$(RM_WIN) "$(NAME)"

re:	fclean all

.PHONY:	all clean clean-win fclean fclean-win re
