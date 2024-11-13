/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:58:53 by ibour             #+#    #+#             */
/*   Updated: 2024/11/13 13:02:24 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int		ft_init_player(t_gamedata *gamedata)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (gamedata->map->map[y]) {
		while (gamedata->map->map[y][x]) {
			if (gamedata->map->map[y][x] == 'P') {
				gamedata->player->position_y = y;
				gamedata->player->position_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}