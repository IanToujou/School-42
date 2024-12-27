/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:12:20 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 03:19:04 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "errortype.h"
# include "keys.h"
# include "color.h"

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define FT_ULONG_MAX	((unsigned long)(~0L))
# define FT_LONG_MAX	((long)(FT_ULONG_MAX >> 1))
# define FT_LONG_MIN	((long)(~FT_LONG_MAX))

# define FT_UINT_MAX	((unsigned)(~0L))
# define FT_INT_MAX		((int)(FT_UINT_MAX >> 1))
# define FT_INT_MIN		((int)(~FT_INT_MAX))

# define WINDOW_NAME "FdF"
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MENU_WIDTH 250

typedef enum
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef struct s_coord_val
{
	int					z;
	int					color;
	struct s_coord_val	*next;
}	t_coord_val;

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}	t_point;

typedef struct s_camera
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}	t_camera;

typedef struct s_map
{
	int	width;
	int	height;
	int	*coords_arr;
	int	*colors_arr;
	int	z_min;
	int	z_max;
	int	z_range;
}	t_map;

typedef struct s_mouse
{
	char	is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_camera	*camera;
	t_map		*map;
	t_mouse		*mouse;
}	t_data;

void	ft_throw_error(int error);

t_map		*ft_init_map(void);
t_data		*ft_init_data(t_map *map);
t_camera	*ft_init_camera(t_data *data);

void		ft_graphics_draw(t_map *map, t_data *data);

int			ft_event_key_press(int key, void *param);
int			ft_event_close(const void *param);
int			ft_event_mouse_press(int button, int x, int y, void *param);
int			ft_event_mouse_move(int x, int y, void *param);

void		ft_util_stack_to_arrays(t_coord_val **coords_stack, t_map *map);
void		ft_util_stack_push(t_coord_val **coords_stack, t_coord_val *new);
t_coord_val	*ft_util_stack_pop(t_coord_val **coords_stack);
int			ft_util_map_read(int fd, t_coord_val **coords_stack, t_map *map);

#endif
