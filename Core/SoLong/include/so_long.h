/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:56:12 by ibour             #+#    #+#             */
/*   Updated: 2024/11/26 00:37:17 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "errortype.h"

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

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

# define WINDOW_SPLASH 0
# define WINDOW_GAME 1

typedef struct s_player
{
	int	position_x;
	int	position_y;
	int	collected;
	int	steps;
}	t_player;

typedef struct s_map
{
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

typedef struct s_gamedata
{
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
}	t_gamedata;

void	ft_throw_error(int error);
void	ft_throw_and_free(t_gamedata *gamedata, int error);

int		ft_init_data(t_gamedata **gamedata);
void	ft_free_data(t_gamedata *gamedata);
void	ft_init_graphics(t_gamedata *gamedata);
void	ft_exit_graphics(const t_gamedata *gamedata);
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
void	ft_event_move(t_gamedata *gd, int k);

int		ft_gfx_render(t_gamedata *gamedata);

int		ft_check_file_format(const char *file);
int		ft_check_characters(t_gamedata *gamedata);
int		ft_check_rectangle(const t_gamedata *gamedata);
int		check_edges(int lines, char **map);

#endif