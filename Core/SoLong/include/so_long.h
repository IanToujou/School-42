/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:56:12 by ibour             #+#    #+#             */
/*   Updated: 2024/11/18 09:50:21 by ibour            ###   ########.fr       */
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
# define XPM_WALL "./assets/deepslate.xpm"
# define XPM_EXIT_CLOSED "./assets/gus_angry.xpm"
# define XPM_EXIT_OPEN "./assets/gus_happy.xpm"
# define XPM_ENEMY_1 "./assets/hank.xpm"
# define XPM_ENEMY_2 "./assets/skyler.xpm"
# define XPM_EMPTY "./assets/stone.xpm"
# define XPM_COLLECTIBLE "./assets/meth.xpm"
# define XPM_DRUG "./assets/fentanyl.xpm"

# define XPM_DEATH_F0 "./assets/waltuh_death/waltuh_death_0.xpm"
# define XPM_DEATH_F1 "./assets/waltuh_death/waltuh_death_1.xpm"
# define XPM_DEATH_F2 "./assets/waltuh_death/waltuh_death_2.xpm"
# define XPM_DEATH_F3 "./assets/waltuh_death/waltuh_death_3.xpm"
# define XPM_DEATH_F4 "./assets/waltuh_death/waltuh_death_4.xpm"
# define XPM_DEATH_F5 "./assets/waltuh_death/waltuh_death_5.xpm"
# define XPM_DEATH_F6 "./assets/waltuh_death/waltuh_death_6.xpm"
# define XPM_DEATH_F7 "./assets/waltuh_death/waltuh_death_7.xpm"
# define XPM_DEATH_F8 "./assets/waltuh_death/waltuh_death_8.xpm"
# define XPM_DEATH_F9 "./assets/waltuh_death/waltuh_death_9.xpm"
# define XPM_DEATH_F10 "./assets/waltuh_death/waltuh_death_10.xpm"
# define XPM_DEATH_F11 "./assets/waltuh_death/waltuh_death_11.xpm"
# define XPM_DEATH_F12 "./assets/waltuh_death/waltuh_death_12.xpm"
# define XPM_DEATH_F13 "./assets/waltuh_death/waltuh_death_13.xpm"
# define XPM_DEATH_F14 "./assets/waltuh_death/waltuh_death_14.xpm"
# define XPM_DEATH_F15 "./assets/waltuh_death/waltuh_death_15.xpm"
# define XPM_DEATH_F16 "./assets/waltuh_death/waltuh_death_16.xpm"
# define XPM_DEATH_F17 "./assets/waltuh_death/waltuh_death_17.xpm"
# define XPM_DEATH_F18 "./assets/waltuh_death/waltuh_death_18.xpm"
# define XPM_DEATH_F19 "./assets/waltuh_death/waltuh_death_19.xpm"
# define XPM_DEATH_F20 "./assets/waltuh_death/waltuh_death_20.xpm"

# define WINDOW_SPLASH 0
# define WINDOW_GAME 1
# define WINDOW_DEATH 2

typedef struct s_player {
	int	position_x;
	int	position_y;
	int	collected;
	int	steps;
}	t_player;

typedef struct s_image_death {
	int			current;
	void		*frame_0;
	void		*frame_1;
	void		*frame_2;
	void		*frame_3;
	void		*frame_4;
	void		*frame_5;
	void		*frame_6;
	void		*frame_7;
	void		*frame_8;
	void		*frame_9;
	void		*frame_10;
	void		*frame_11;
	void		*frame_12;
	void		*frame_13;
	void		*frame_14;
	void		*frame_15;
	void		*frame_16;
	void		*frame_17;
	void		*frame_18;
	void		*frame_19;
	void		*frame_20;
} t_image_death;

typedef struct s_map {
	int		amount_collectibles;
	int		amount_exits;
	int		amount_players;
	char	**map;
	int		can_exit;
	size_t	size_x;
	int		size_y;
	int		fd;
	char	*path;
}	t_map;

typedef struct s_gamedata {
	void			*mlx;
	void			*window;
	int				window_width;
	int				window_height;
	int				window_page;
	t_player		*player;
	t_map			*map;
	int				image_size;
	void			*image_splash;
	void			*image_player;
	void			*image_empty;
	void			*image_wall;
	void			*image_exit_open;
	void			*image_exit_closed;
	void			*image_collectible;
	void			*image_drug;
	void			*image_enemy_1;
	void			*image_enemy_2;
	int				x;
	int				y;
	char			*str_quest;
	char			*str_collected;
	char			*str_collected_part;
	char			*str_moves;
	char			*str_moves_part;
	t_image_death	*image_death;
}	t_gamedata;

void	ft_throw_error(int error);

int		ft_init_data(t_gamedata **gamedata);
void	ft_free_data(t_gamedata *gamedata);
int		ft_init_graphics(t_gamedata *gamedata);
int		ft_exit_graphics(t_gamedata *gamedata);
int		ft_init_mlx(t_gamedata *gamedata);
void	ft_exit_mlx(t_gamedata *gamedata);
int		ft_init_hooks(t_gamedata *gamedata);
int		ft_init_map(t_gamedata *gamedata, char **argv);
int		ft_exit_map(char **array);
int		ft_init_player(t_gamedata *gamedata);

int		ft_check_map(t_gamedata *gamedata);
int		ft_create_map(t_gamedata *gamedata, char *path);

int		ft_event_keypress(int keycode, t_gamedata *gamedata);
int		ft_event_close(t_gamedata *gamedata);
int		ft_event_window(int window, t_gamedata *gamedata);
void	ft_event_move(t_gamedata *gamedata, int keycode);

int		ft_gfx_render(t_gamedata *gamedata);

#endif