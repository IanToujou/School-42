INC=/usr/include
##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:41:20 2007 Olivier Crouzet
##

## Please use configure script



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
CFLAGS	= -O3 -flto -I$(INC)
DEBUG_FLAGS = -g -O0

ERASE   := \033[2K\r
BLUE    := \033[34m
END     := \033[0m

all	: $(NAME)

debug: CFLAGS = $(DEBUG_FLAGS)
debug: all

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ > /dev/null 2>&1
	@printf "$(ERASE)$(BLUE)> Compilation : <$(END) $<"

$(NAME)	: $(OBJ)
	@llvm-ar-12 rcs $(NAME) $(OBJ) > /dev/null 2>&1
	@llvm-ranlib-12 $(NAME) > /dev/null 2>&1
	@cp $(NAME) $(NAME_UNAME) > /dev/null 2>&1
	@printf "$(ERASE)$(BLUE)> $@ made <$(END)\n"

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
		rm -f $$obj && printf "$(ERASE)$(BLUE)> Removed $$obj <$(END)"; \
		sleep 0.01; \
	done
	@rm -f $(NAME) $(NAME_UNAME)

.PHONY: all check show clean