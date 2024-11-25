/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:32:26 by ibour             #+#    #+#             */
/*   Updated: 2024/11/25 19:47:35 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_map(t_gamedata *gamedata)
{
	int		y;
	size_t	x;

	y = 0;
	x = 0;
	while (gamedata->map->map[y])
	{
		while (x < ft_strlen(gamedata->map->map[y]) - 1)
		{
			if (ft_strchr("0123CEP", gamedata->map->map[y][x]) == NULL)
				ft_throw_error(ERROR_MAP_OTHER);
			x++;
		}
		x = 0;
		y++;
	}
	if (ft_check_characters(gamedata) == -1)
		ft_throw_error(ERROR_MAP_CHARACTERS);
	if (gamedata->map->amount_players > 1)
		ft_throw_error(ERROR_MAP_PLAYER);
	if (ft_check_rectangle(gamedata) == -1)
		ft_throw_error(ERROR_MAP_RECTANGLE);
	if (check_edges(gamedata->map->size_y, gamedata->map->map) == -1)
		ft_throw_error(ERROR_MAP_EDGES);
	return (0);
}
