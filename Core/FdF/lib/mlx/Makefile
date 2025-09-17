INC=/usr/include
UNAME = $(shell uname)

NAME		= libmlx.a
NAME_UNAME	= libmlx_$(UNAME).a

SRC	= mlx_init.c mlx_new_window.c mlx_pixel_put.c mlx_loop.c \
	mlx_mouse_hook.c mlx_key_hook.c mlx_expose_hook.c mlx_loop_hook.c \
	mlx_int_anti_resize_win.c mlx_int_do_nothing.c \
	mlx_int_wait_first_expose.c mlx_int_get_visual.c \
	mlx_flush_event.c mlx_string_put.c mlx_set_font.c \
	mlx_new_image.c mlx_get_data_addr.c \
	mlx_put_image_to_window.c mlx_get_color_value.c mlx_clear_window.c \
	mlx_xpm.c mlx_int_str_to_wordtab.c mlx_destroy_window.c \
	mlx_int_param_event.c mlx_int_set_win_event_mask.c mlx_hook.c \
	mlx_rgb.c mlx_destroy_image.c mlx_mouse.c mlx_screen_size.c \
	mlx_destroy_display.c

OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
CFLAGS	= -O3 -flto -I$(INC) -DGL_GLEXT_PROTOTYPES -fomit-frame-pointer -funroll-loops
DEBUG_FLAGS = -g -O0

OBJS = $(SRC:.c=.o)
TOTAL_FILES = $(words $(SRC))
COMPILED_FILES = 0

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
ERASE := \033[2K\r
END := \033[0m

all	: $(NAME)

debug: CFLAGS = $(DEBUG_FLAGS)
debug: all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR) > /dev/null 2>&1
	@gcc $(CFLAGS) $(IFLAGS) -c $< -o $@ > /dev/null 2>&1
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES) + 1))))
	@TERM_WIDTH=$$(tput cols); \
	BAR_WIDTH=$$((TERM_WIDTH - 17)); \
	PROGRESS=$$(($(COMPILED_FILES) * BAR_WIDTH / $(TOTAL_FILES))); \
	PERCENTAGE=$$(echo "scale=1; $(COMPILED_FILES) * 100 / $(TOTAL_FILES)" | bc); \
	SPINNER_FRAMES="|/-\\"; \
	SPINNER_INDEX=$$(($(COMPILED_FILES) / 2 % 4)); \
	SPINNER_CHAR=$$(printf "$$SPINNER_FRAMES" | cut -c$$((SPINNER_INDEX + 1))); \
	printf "$(ERASE)3/4 $$SPINNER_CHAR ["; \
	for i in $$(seq 1 $$PROGRESS); do printf "█"; done; \
	for i in $$(seq $$((PROGRESS + 1)) $$BAR_WIDTH); do printf "."; done; \
	printf "] %s%%" "$$PERCENTAGE"

$(NAME)	: $(OBJ)
	@ar rcs $(NAME) $(OBJ) > /dev/null 2>&1
	@ranlib $(NAME) > /dev/null 2>&1
	@cp $(NAME) $(NAME_UNAME) > /dev/null 2>&1

check: all
	@./test/run_tests.sh > /dev/null 2>&1
	
show:
	@printf "NAME  		: $(NAME)\n"
	@printf "NAME_UNAME	: $(NAME_UNAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "SRC		:\n	$(SRC)\n"
	@printf "OBJ		:\n	$(OBJ)\n"

clean	:
	@for obj in $(OBJ); do \
		rm -f $$obj; \
		sleep 0.01; \
	done
	@rm -f $(NAME) $(NAME_UNAME)

.PHONY: all check show clean
