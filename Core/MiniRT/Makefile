NAME = miniRT

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m
ERASE := \033[2K\r
END := \033[0m

SRC =	src/create/create_scene.c \
		src/init/init_parse.c \
		src/parse/parse_ambient.c \
		src/parse/parse_camera.c \
		src/parse/parse_sphere.c \
		src/parse/parse_cylinder.c \
		src/parse/parse_cone.c \
		src/parse/parse_plane.c \
		src/parse/parse_spotlight.c \
		src/main/main.c \
		src/init/init_data.c \
		src/error/error_throw.c \
		src/render/calculate_lighting.c \
		src/render/generate_ray.c \
		src/object/intersect.c \
		src/object/plane.c \
		src/object/sphere.c \
		src/object/object_cylinder.c \
		src/object/object_cylinder_2.c \
		src/object/object_cylinder_3.c \
		src/object/object_cone.c \
		src/render/render.c \
		src/render/trace_ray.c \
		src/util/vec_add.c \
		src/util/vec.c \
		src/util/vec_cross.c \
		src/util/vec_div.c \
		src/util/vec_dot.c \
		src/util/vec_mul.c \
		src/util/vec_normalize.c \
		src/util/vec_sub.c \
		src/util/vec_add_value.c \
		src/util/vec_len.c \
		src/util/add_color.c \
		src/util/color_scale.c \
		src/util/util_num.c \
		src/util/util_color.c \
		src/util/util_array.c \
		src/util/util_vector.c \
		src/init/init_mlx.c \
		src/init/init_hook.c \
		src/event/event_close.c \
		src/event/event_keypress.c \
		src/exit/exit_mlx.c \
		src/util/util_camera.c \
		src/exit/exit_data.c

OBJ = $(SRC:.c=.o)
TOTAL_FILES = $(words $(SRC))
COMPILED_FILES = 0

CC = clang
CFLAGS = -Wall -Werror -Wextra -Ofast -march=native -ffast-math -flto -I.
RM = rm -rf
RM_WIN = del /S /Q

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES) + 1))))
	@TERM_WIDTH=$$(tput cols); \
	BAR_WIDTH=$$((TERM_WIDTH - 13)); \
	PROGRESS=$$(($(COMPILED_FILES) * BAR_WIDTH / $(TOTAL_FILES))); \
	PERCENTAGE=$$(echo "scale=1; $(COMPILED_FILES) * 100 / $(TOTAL_FILES)" | bc); \
	SPINNER_FRAMES="|/-\\"; \
	SPINNER_INDEX=$$(($(COMPILED_FILES) / 2 % 4)); \
	SPINNER_CHAR=$$(printf "$$SPINNER_FRAMES" | cut -c$$((SPINNER_INDEX + 1))); \
	printf "$(ERASE)$$SPINNER_CHAR ["; \
	for i in $$(seq 1 $$PROGRESS); do printf "█"; done; \
	for i in $$(seq $$((PROGRESS + 1)) $$BAR_WIDTH); do printf "."; done; \
	printf "] %s%%" "$$PERCENTAGE"

all: $(OBJ) libft mlx
	@$(CC) -o $(NAME) $(OBJ) -Llib/libft -lft -Llib/mlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -flto
	@echo ""

libft:
	@make -C lib/libft --silent

mlx:
	@make -C lib/mlx --silent

clean:
	@$(RM) $(OBJ)
	@make -C lib/libft clean --silent
	@make -C lib/mlx clean --silent

clean-win:
	@$(RM_WIN) "*.o"
	@make -C lib/libft clean-win --silent

fclean: clean
	@$(RM) $(NAME)
	@make -C lib/libft fclean --silent
	@make -C lib/mlx clean --silent

fclean-win:	clean-win
	@$(RM_WIN) "$(NAME).exe"
	@make -C lib/libft fclean-win --silent

re: fclean all

.PHONY: all libft mlx clean clean-win fclean fclean-win re
