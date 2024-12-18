/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:12:20 by ibour             #+#    #+#             */
/*   Updated: 2024/12/18 13:44:37 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "errortype.h"
# include "keys.h"

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <math.h>
# include <limits.h>

# define WINDOW_NAME "FdF (More like Fdp)"
# define WINDOW_SIZE 900

# define UINT u_int32_t

# define WIDTH				1920
# define HEIGHT				1080
# define TEXT_COLOR			0xEAEAEAFF
# define BACKGROUND			0x22222200
# define MENU_BACKGROUND	0x1E1E1EFF

# define COLOR_TEN			0x9e0142ff
# define COLOR_NINE			0xd53e4fff
# define COLOR_EIGHT		0xf46d43ff
# define COLOR_SEVEN		0xfdae61ff
# define COLOR_SIX			0xfee08bff
# define COLOR_FIVE			0xe6f598ff
# define COLOR_FOUR			0xabdda4ff
# define COLOR_THREE		0x66c2a5ff
# define COLOR_TWO			0x3288bdff
# define COLOR_ONE			0x5e4fa2ff

typedef struct s_point2d {
	int	x;
	int	y;
	int	z;
	int	rgba;
}	t_point2d;

typedef struct s_point3d {
	double	x;
	double	y;
	double	z;
	int		map_color;
	int		z_color;
}	t_point3d;

typedef struct s_map {
	int			cols;
	int			rows;
	int			high;
	int			low;
	bool		use_z_color;
	double		x_offset;
	double		y_offset;
	double		interval;
	double		alpha;
	double		beta;
	double		x_rotate;
	double		y_rotate;
	double		z_rotate;
	double		zoom;
	double		z_scale;
	t_point3d	**grid3d;
	t_point2d	**grid2d;
}	t_map;

typedef struct s_image
{
	int		width;
	int		height;
	void	*mlx_image;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		steep;
}	t_image;

typedef struct s_data {
	void	*mlx;
	void	*window;
	int		window_width;
	int		window_height;
	t_map	*map;
	t_image	*image;
}	t_data;

void	ft_error_throw(int error);
void	ft_error_throw_map(int fd, t_map *map, int error);

int		ft_init_data(t_data **data);
int		ft_init_map(t_data *data, const char *arg);
int		ft_init_mlx(t_data *data);
void	ft_init_hooks(t_data *data);

int		ft_event_close(t_data *data);
int		ft_event_keypress(int keycode, t_data *data);

int		ft_gfx_render(t_data *data);

void	ft_util_parse_dimensions(int fd, t_map *map);
void	ft_util_parse_map(int fd, t_map *map);
void	ft_util_free(t_data *data);
void	ft_util_free_map(t_map *map);
void	ft_util_free_array(void **array, size_t length);
void	ft_util_str_upper(unsigned int i, char *c);
void	ft_util_algo_line(const t_image *image, t_point2d a, t_point2d b);
void	ft_util_draw_image(const t_data *data);
void	ft_util_draw_map(t_map *map, int i, int j);
void	ft_util_draw_reset(const t_image *image);
void	ft_put_pixel(const t_image *image, int x, int y, int color);

#endif
