NAME = Test

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
ERASE := \033[2K\r
END := \033[0m

SRC =	src/main.c

OBJ = $(SRC:.c=.o)
TOTAL_FILES = $(words $(SRC))
COMPILED_FILES = 0

CC = clang
CFLAGS = -Wall -Werror -Wextra -Ofast -I.
RM = rm -rf
RM_WIN = del /S /Q

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
	printf "$(ERASE)2/2 $$SPINNER_CHAR ["; \
	for i in $$(seq 1 $$PROGRESS); do printf "█"; done; \
	for i in $$(seq $$((PROGRESS + 1)) $$BAR_WIDTH); do printf "."; done; \
	printf "] %s%%" "$$PERCENTAGE"

all: $(OBJ) ggcollect
	@$(CC) -o $(NAME) $(OBJ) lib/ggcollect/gg_collect.a
	@echo ""

ggcollect:
	@make -C lib/ggcollect --silent

clean:
	@$(RM) $(OBJ)
	@make -C lib/ggcollect clean --silent

clean-win:
	@$(RM_WIN) "*.o"
	@make -C lib/ggcollect clean-win --silent

fclean: clean
	@$(RM) $(NAME)
	@make -C lib/ggcollect fclean --silent

fclean-win:	clean-win
	@$(RM_WIN) "$(NAME).exe"
	@make -C lib/ggcollect fclean-win --silent

re: fclean all

.PHONY: all ggcollect clean clean-win fclean fclean-win re
