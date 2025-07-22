/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:33:19 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 07:57:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIDTH 1280
# define HEIGHT 720
# define ESC_KEY 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include "errortype.h"

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL,
	TOP
}	t_projection;

typedef enum e_color {
	DEFAULT,
	MAP,
	RAINBOW,
	MONOCHROME,
}	t_color;

typedef struct s_point {
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct s_map
{
	int				**array;
	t_point			**points;
	double			altitude_ratio;
	int				depth;
	int				width;
	int				x_max;
	int				x_min;
	int				y_max;
	int				y_min;
	int				z_max;
	int				z_min;
	double			alpha;
	double			beta;
	double			gamma;
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
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_map	map;
	t_image	image;
}	t_data;

void	init_data(t_data *data);
void	init_parse(t_data *data, const char *file);
void	init_mlx(t_data *data);
void	init_hook(t_data *data);

void	exit_data(t_data *data);
void	exit_array_2d_int(int ***array, int length);
void	exit_array_2d_point(t_point ***array, int length);
void	exit_mlx(t_data *data);

int		event_close(t_data *data);
int		event_keypress(int keycode, t_data *data);

void	gfx_render(t_data *data);

int		util_map_parse_width(const char *filename);
int		util_map_parse_depth(int fd);

#endif