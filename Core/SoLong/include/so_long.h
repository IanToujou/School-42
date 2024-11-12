/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:56:12 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 14:10:33 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "errortype.h"

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
#include <fcntl.h>

# define WINDOW_NAME "BLUE METH DRUG CARTEL SIMULATOR"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define KEY_ESCAPE 27
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

# define IMG_WIDTH 64
# define IMG_HEIGHT 64

# define XPM_SPLASH "./assets/splash.xpm"
# define XPM_PLAYER "./assets/waltuh.xpm"

# define WINDOW_SPLASH 0
# define WINDOW_GAME 1

typedef struct s_player {
	int	position_x;
	int	position_y;
}	t_player;

typedef struct s_map {
	int	size_x;
	int	size_y;
	int	amount_collectibles;
	int	amount_enemies;
	int	amount_players;
}	t_map;

typedef struct s_gamedata {
	void		*mlx;
	void		*window;
	int			window_width;
	int			window_height;
	int			window_page;
	t_player	*player;
	t_map		*map;
	int			image_size;
	void		*image_splash;
	void		*image_player;
}	t_gamedata;

void	ft_throw_error(int error);

int		ft_init_data(t_gamedata **gamedata);
int		ft_init_graphics(t_gamedata *gamedata);
int		ft_init_mlx(t_gamedata *gamedata);
int		ft_init_hooks(t_gamedata *gamedata);
int		ft_init_map(t_gamedata *gamedata, char **argv);

int		ft_event_keypress(int keycode, t_gamedata *gamedata);
int		ft_event_close(t_gamedata *gamedata);

int		ft_gfx_render(t_gamedata *gamedata);

#endif