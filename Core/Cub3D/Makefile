# Define color codes
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m


CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Iminilibx-linux -Ilibft
LDFLAGS = -Lminilibx-linux -lmlx -lm -lX11 -lXext -Llibft -lft -lm
SRC =	create/create_scene.c \
	main.c \
	render/calculate_lighting.c \
	render/generate_ray.c \
	render/intersect/intersect.c \
	render/intersect/plane.c \
	render/intersect/sphere.c \
	render/intersect/cylinder.c \
	render/render.c \
	render/trace_ray.c \
	utils/vec_add.c \
	utils/vec.c \
	utils/vec_cross.c \
	utils/vec_div.c \
	utils/vec_dot.c \
	utils/vec_mul.c \
	utils/vec_normalize.c \
	utils/vec_sub.c \
	utils/vec_add_value.c \
	utils/vec_len.c \
	utils/add_color.c \
	utils/color_scale.c

OBJ = $(SRC:.c=.o)
NAME = miniRT

MLX_DIR = minilibx-linux
LIBFT_DIR = libft

all: $(NAME)

$(MLX_DIR)/libmlx.a:
	@echo "$(BLUE)Compiling MinilibX...$(RESET)"
	@cd $(MLX_DIR) && make -s && cd ..
	@echo "$(GREEN)MinilibX COMPILED!$(RESET)"

$(LIBFT_DIR)/libft.a:
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@cd $(LIBFT_DIR) && make -s && cd ..
	@echo "$(GREEN)libft COMPILED!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MLX_DIR)/libmlx.a $(LIBFT_DIR)/libft.a
	@echo "$(BLUE)Linking the project...$(RESET)"
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)Project LINKED!$(RESET)"

clean:
	@echo "$(BLUE)Cleaning miniRT object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(BLUE)Cleaning MiniLibX object files...$(RESET)"
	@make -s -C $(MLX_DIR) clean
	@echo "$(BLUE)Cleaning libft object files...$(RESET)"
	@make -s -C $(LIBFT_DIR) clean
	@echo "$(GREEN)miniRT CLEANED!$(RESET)"

fclean:
	@echo "$(BLUE)Cleaning miniRT object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(BLUE)Cleaning MiniLibX object files...$(RESET)"
	@make -s -C $(MLX_DIR) clean
	@echo "$(BLUE)Removing libft archive...$(RESET)"
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(BLUE)Removing miniRT executable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)fract_ol FCLEANED!$(RESET)"

re: fclean all

.phony : clean fclean re
