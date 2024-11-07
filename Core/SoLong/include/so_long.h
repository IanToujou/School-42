/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:56:12 by ibour             #+#    #+#             */
/*   Updated: 2024/11/07 13:18:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
#include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/include/libft.h"

# define IMG_W 64
# define IMG_H 64
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

typedef struct s_map {
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		collectibles;
}	t_map;

typedef struct s_image {
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*background;
}	t_image;

typedef struct s_data {
	void	*mlx;
	void	*window;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	t_map	*map;
	t_image	*image;
}	t_data;

void	ft_handle_error(const char *error);

void	ft_init(t_data *data, t_map *map);
void	ft_parse_map(const t_data *data, char **argv, int argc);

int		ft_game_lose(const t_data *data);
int		ft_game_win(const t_data *data);

void	ft_controller_move(t_data *data, char position, int direction);

void	ft_render_window(t_data *data, char **argv);
void	ft_render_map(t_data *data);
void	ft_render_background(const t_data *data);
void	ft_render_object(const t_data *data, char *path);
void	ft_render_player(t_data *data);

int		ft_hook_key(const int keycode, t_data *data);

#endif