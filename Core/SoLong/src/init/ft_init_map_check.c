/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:32:26 by ibour             #+#    #+#             */
/*   Updated: 2024/11/26 09:07:09 by ibour            ###   ########.fr       */
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
			if (ft_strchr("01CEP", gamedata->map->map[y][x]) == NULL)
				ft_throw_and_free(gamedata, ERROR_MAP_OTHER, 1);
			x++;
		}
		x = 0;
		y++;
	}
	if (ft_check_characters(gamedata) == -1)
		ft_throw_and_free(gamedata, ERROR_MAP_CHARACTERS, 1);
	if (gamedata->map->amount_players > 1)
		ft_throw_and_free(gamedata, ERROR_MAP_PLAYER, 1);
	if (ft_check_rectangle(gamedata) == -1)
		ft_throw_and_free(gamedata, ERROR_MAP_RECTANGLE, 1);
	if (check_edges(gamedata->map->size_y, gamedata->map->map) == -1)
		ft_throw_and_free(gamedata, ERROR_MAP_EDGES, 1);
	return (0);
}
