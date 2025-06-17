# Define color codes
RESET = \033[0m
GREEN = \033[32m
BLUE = \033[34m
YELLOW = \033[33m

SRC = ft_strlen.c ft_memset.c ft_bzero.c ft_isalpha.c ft_isdigit.c \
      ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcpy.c ft_memmove.c \
      ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
      ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
      ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
      ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
      ft_strcmp.c ft_isspace.c ft_atof.c ft_ftoa.c ft_is_float.c

NAME = libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default target
all: $(NAME)

# Building the library
$(NAME): $(OBJ) $(FT_PRINTF)
	@echo "$(BLUE)Starting to build libft...$(RESET)"
	@echo "$(BLUE)Adding ft_printf...$(RESET)"
	@cp $(FT_PRINTF) $(NAME)
	@echo "$(BLUE)Archiving libft files...$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)libft BUILT!$(RESET)"

# Building ft_printf
$(FT_PRINTF):
	@echo "$(BLUE)Compiling ft_printf...$(RESET)"
	@make -s -C $(FT_PRINTF_DIR)
	@echo "$(GREEN)ft_printf COMPILED!$(RESET)"

# Object file compilation
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning object files
clean:
	@echo "$(BLUE)Cleaning libft object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(BLUE)Cleaning ft_printf...$(RESET)"
	@make -s -C $(FT_PRINTF_DIR) clean
	@echo "$(GREEN)libft CLEANED!$(RESET)"

# Full cleanup
fclean:
	@echo "$(BLUE)Cleaning libft object files...$(RESET)"
	@rm -f $(OBJ)
	@echo "$(BLUE)Removing libft archive...$(RESET)"
	@rm -f $(NAME)
	@echo "$(BLUE)Cleaning ft_printf archive...$(RESET)"
	@make -s -C $(FT_PRINTF_DIR) fclean
	@echo "$(GREEN)libft FCLEANED!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus

