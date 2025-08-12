NAME = gg_collect.a

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
ERASE := \033[2K\r
END := \033[0m

SRC =	src/gg_free.c \
		src/gg_init.c \
		src/gg_malloc.c

OBJ = $(SRC:.c=.o)
TOTAL_FILES = $(words $(SRC))
COMPILED_FILES = 0

CC = clang
CFLAGS = -Wall -Werror -Wextra -Ofast -I.
RM = rm -rf
RM_WIN = del /S /Q
AR = ar crs

$(NAME): $(OBJ)
	@$(AR) $@ $^

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
	printf "$(ERASE)1/1 $$SPINNER_CHAR ["; \
	for i in $$(seq 1 $$PROGRESS); do printf "█"; done; \
	for i in $$(seq $$((PROGRESS + 1)) $$BAR_WIDTH); do printf "."; done; \
	printf "] %s%%" "$$PERCENTAGE"

all: $(NAME)
	@echo ""

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
