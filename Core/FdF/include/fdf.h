/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:33:19 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 10:29:47 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIDTH 1280
# define HEIGHT 720
# define MARGIN 200

# define KEY_SPACE 32
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_R 114
# define KEY_I 105
# define KEY_T 116
# define KEY_P 112
# define KEY_NUMPAD_PLUS 65451
# define KEY_NUMPAD_MINUS 65453
# define KEY_NUMPAD_0 65438
# define KEY_NUMPAD_1 65436
# define KEY_NUMPAD_2 65433
# define KEY_NUMPAD_3 65435
# define KEY_NUMPAD_4 65430
# define KEY_NUMPAD_5 65437
# define KEY_NUMPAD_6 65432
# define KEY_NUMPAD_7 65429
# define KEY_NUMPAD_8 65431
# define KEY_NUMPAD_9 65434
# define KEY_NUM_1 49
# define KEY_NUM_2 50
# define KEY_NUM_3 51
# define KEY_NUM_4 52

# define MOUSE_LEFT 1
# define MOUSE_MIDDLE 2
# define MOUSE_RIGHT 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define COLOR_HIGH 0x453100
# define COLOR_MEDIUM 0xf6f172
# define COLOR_LOW 0x005e02
# define COLOR_SHORE 0x64aee5
# define COLOR_SEA 0x2437c3

# define MENU_COLOR 0xDDDDDD
# define MOUSE_ROTATION_COEF 0.005
# define ANGLE_INCR 0.02
# define OFFSET_INCR 10
# define ZOOM_INCR 0.2
# define ALT_INCR 0.1

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include "../lib/ggcollect/include/gg_collect.h"
# include <X11/X.h>
# include <fcntl.h>
# include "errortype.h"
# include <math.h>
# include <stdio.h>

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef enum e_color
{
	ALTITUDE,
	MAP,
	RAINBOW,
	MONOCHROME,
}	t_color;

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
}	t_point;

typedef struct s_map
{
	int				**array;
	t_point			**points;
	double			altitude_ratio;
	int				depth;
	int				width;
	double			x_max;
	double			x_min;
	double			y_max;
	double			y_min;
	double			z_max;
	double			z_min;
	double			alpha;
	double			beta;
	double			gamma;
	double			scale;
	int				x_offset;
	int				y_offset;
	t_projection	projection;
	t_color			color;
}	t_map;

typedef struct s_image
{
	int	bpp;
	int	size_line;
	int	endian;
}	t_image;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_map			map;
	unsigned int	*addr;
	t_image			image;
	t_gg_data		*gg_data;
}	t_data;

typedef struct s_ipos
{
	int		i;
	int		j;
}				t_ipos;

void	init_data(t_data *data);
void	init_parse(t_data *data, const char *file);
void	init_map_array(t_data *data);
void	init_map_read(t_data *data, const char *file);
void	init_mlx(t_data *data);
void	init_hook(t_data *data);

void	exit_data(t_data *data);
void	exit_array_2d_int(int ***array, int length);
void	exit_array_2d_point(t_point ***array, int length);
void	exit_mlx(t_data *data);

int		event_close(t_data *data);
int		event_keypress(int k, t_data *data);
int		event_keyrelease(int keycode, t_data *data);

void	event_action_move(int k, t_data *data);
void	event_action_rotate(int k, t_data *data);
void	event_action_reset(t_data *data);
void	event_action_zoom(int key, double *scale);
void	event_action_altitude(int key, t_data *data);
void	event_action_color(int key, t_data *data);
void	event_action_projection(int key, t_data *data);

void	gfx_render(t_data *data);
void	gfx_render_point(t_data *data);
void	gfx_render_pixel(const t_data *data, t_point p);
int		gfx_render_color(t_data *data, t_ipos a, t_ipos b, t_point p);
double	gfx_render_gradient_percent(double current, double start, double end);
int		gfx_render_gradient_level(int start, int end, double ratio);
int		gfx_render_gradient(t_data *data, t_point p, t_point a, t_point b);
void	gfx_render_ui(const t_data *data);

int		gfx_project(t_data *data);
void	gfx_project_calc_top(const t_data *data, int i, int j);
void	gfx_project_calc_parallel(t_data *data, int i, int j);
void	gfx_project_calc_isometric(t_data *data, int i, int j);

int		util_map_parse_width(const char *filename);
int		util_map_parse_depth(int fd);
double	util_num_parse(char *str);
int		util_atoi_base(const char *str, const char *base);
void	util_array_free(void **array);
void	util_rotation_x(double *y, double *z, double alpha);
void	util_rotation_y(double *x, double *z, double beta);
void	util_rotation_z(double *x, double *y, double gamma);

void	util_color_free_array(char **array);
int		util_color_count(char **values);
void	util_place(t_data *data);
int		util_image(t_data *data);
t_ipos	util_ipos_new(int i, int j);

#endif