/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:54:05 by ibour             #+#    #+#             */
/*   Updated: 2024/11/25 22:39:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_init_values(t_gamedata **gamedata)
{
	(*gamedata)->image_size = 64;
	(*gamedata)->window_width = 900;
	(*gamedata)->window_height = 600;
	(*gamedata)->window_page = WINDOW_SPLASH;
	(*gamedata)->str_quest = ft_strjoin("", "USE WASD TO MOVE");
	(*gamedata)->str_moves = ft_strjoin("", "");
	(*gamedata)->str_collected = ft_strjoin("", "");
	(*gamedata)->str_moves_part = ft_strjoin("", "");
	(*gamedata)->str_collected_part = ft_strjoin("", "");
	(*gamedata)->player->position_x = 0;
	(*gamedata)->player->position_y = 0;
	(*gamedata)->player->collected = 0;
	(*gamedata)->player->steps = 0;
}

int	ft_init_data(t_gamedata **gamedata)
{
	t_map		*map;
	t_player	*player;

	*gamedata = (t_gamedata *) malloc(sizeof(t_gamedata));
	if (!*gamedata)
		return (-1);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (-1);
	player = (t_player *) malloc(sizeof(t_player));
	if (!player)
		return (-1);
	(*gamedata)->map = map;
	(*gamedata)->player = player;
	ft_init_values(gamedata);
	return (0);
}

void	ft_free_data(t_gamedata *gamedata)
{
	ft_exit_graphics(gamedata);
	ft_exit_map(gamedata->map->map);
	free(gamedata->str_quest);
	free(gamedata->str_collected);
	free(gamedata->str_moves);
	free(gamedata->str_collected_part);
	free(gamedata->str_moves_part);
	free(gamedata->mlx);
	free(gamedata->player);
	free(gamedata->map);
	free(gamedata);
}
