/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:56:12 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 12:01:04 by ibour            ###   ########.fr       */
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
	t_player	*player;
	t_map		*map;
}	t_gamedata;

void	ft_throw_error(int error);

int		ft_init_data(t_gamedata **gamedata);
int		ft_init_mlx(t_gamedata *gamedata);
int		ft_init_hooks(t_gamedata *gamedata);
int		ft_init_map(t_gamedata *gamedata, char **argv);

int		ft_event_keypress(int keycode, t_gamedata *gamedata);
int		ft_event_close(t_gamedata *gamedata);

#endif