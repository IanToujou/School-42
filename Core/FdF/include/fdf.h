/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:12:20 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 05:21:08 by ibour            ###   ########.fr       */
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
# include <math.h>

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

typedef struct		s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
}					t_file;

void		ft_throw_error(int error);

t_map		*ft_init_map(void);
t_data		*ft_init_data(t_map *map);
t_camera	*ft_init_camera(const t_data *data);
t_point		ft_init_point(int x, int y, t_map *map);
void		ft_init_hooks(t_data *data);

void		ft_graphics_draw(t_map *map, t_data *data);
t_point		ft_graphics_project(t_point p, const t_data *data);
void		ft_graphics_menu(const t_data *data);

int			ft_event_key_press(int key, void *param);
int			ft_event_close(const void *param);
int			ft_event_mouse_press(int button, int x, int y, void *param);
int			ft_event_mouse_release(int button, int x, int y, void *param);
int			ft_event_mouse_move(int x, int y, void *param);
int			ft_event_close(const void *param);

void		ft_util_stack_to_arrays(t_coord_val **coords_stack, t_map *map);
void		ft_util_stack_push(t_coord_val **coords_stack, t_coord_val *new);
t_coord_val	*ft_util_stack_pop(t_coord_val **coords_stack);
int			ft_util_map_read(int fd, t_coord_val **coords_stack, t_map *map);
int			ft_util_array_index(int x, int y, int width);

int			ft_util_color_default(int z, const t_map *map);
int			ft_util_color_light(int start, int end, double percentage);
int			ft_util_color_get(t_point current, t_point start, t_point end, t_point delta);

double		ft_util_percent(int start, int end, int current);
int			ft_util_isnum(char *str, int base);

char		**ft_util_split(char const *s, char c);
int			ft_util_gnl(int fd, char **line);

void		ft_util_controls_zoom(int key, t_data *data);
void		ft_util_controls_move(int key, t_data *data);
void		ft_util_controls_rotate(int key, t_data *data);
void		ft_util_controls_flatten(int key, t_data *data);
void		ft_util_controls_project(int key, t_data *data);

#endif
