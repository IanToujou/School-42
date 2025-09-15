/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:33:19 by ibour             #+#    #+#             */
/*   Updated: 2025/09/15 14:21:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIDTH 1280
# define HEIGHT 720
# define MARGIN 200
# define ESC_KEY 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define COLOR_HIGH 0x453100
# define COLOR_MEDIUM 0xf6f172
# define COLOR_LOW 0x005e02
# define COLOR_SHORE 0x64aee5
# define COLOR_SEA 0x2437c3

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include "../lib/ggcollect/include/gg_collect.h"
# include <X11/X.h>
# include <fcntl.h>
# include "errortype.h"
# include <math.h>

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL,
	TOP
}	t_projection;

typedef enum e_color {
	ALTITUDE,
	MAP,
	RAINBOW,
	MONOCHROME,
}	t_color;

typedef struct s_point {
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

typedef struct	s_ipos
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
int		event_keypress(int keycode, t_data *data);
int		event_keyrelease(int keycode, t_data *data);

void	gfx_render(t_data *data);
void	gfx_render_point(t_data *data);
void	gfx_render_pixel(const t_data *data, t_point p);
int		gfx_render_color(t_data *data, t_ipos a, t_ipos b, t_point p);
double	gfx_render_gradient_percent(double current, double start, double end);
int		gfx_render_gradient_level(int start, int end, double ratio);
int		gfx_render_gradient(t_data *data, t_point p, t_point a, t_point b);

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