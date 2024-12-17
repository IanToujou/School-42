/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:12:20 by ibour             #+#    #+#             */
/*   Updated: 2024/12/17 08:17:04 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "errortype.h"
# include "keys.h"

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

# define WINDOW_NAME "FdF"
# define WINDOW_SIZE 900

# define UINT u_int32_t

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

typedef struct s_map {
	int		cols;
	int		rows;
	int		high;
	int		low;
}	t_map;

typedef struct s_data {
	void	*mlx;
	void	*window;
	int		window_width;
	int		window_height;
	t_map	*map;
}	t_data;

void	ft_throw_error(int error);

int		ft_init_data(t_data **data);
int		ft_init_map(t_data *data, char *arg);
int		ft_init_mlx(t_data *data);
void	ft_init_hooks(t_data *data);

int		ft_event_close(t_data *data);
int		ft_event_keypress(int keycode, t_data *data);

int		ft_gfx_render(t_data *data);

void	ft_util_free(t_data *data);
void	ft_util_parse_dimensions(int fd, t_map *map);

#endif
