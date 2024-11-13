/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:02:43 by ibour             #+#    #+#             */
/*   Updated: 2024/11/13 14:59:42 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_check_next_tile(t_gamedata *gamedata, char direction, char tile)
{
	if ((direction == KEY_D && gamedata->map->map[gamedata->player->position_y][gamedata->player->position_x + 1] == tile)
		|| (direction == KEY_A && gamedata->map->map[gamedata->player->position_y][gamedata->player->position_x - 1] == tile)
		|| (direction == KEY_S && gamedata->map->map[gamedata->player->position_y+ 1][gamedata->player->position_x] == tile)
		|| (direction == KEY_W && gamedata->map->map[gamedata->player->position_y - 1][gamedata->player->position_x] == tile)
		)
		return (0);
	return (-1);
}

void	ft_event_move(t_gamedata *gamedata, int keycode)
{
	if (ft_check_next_tile(gamedata, keycode, '1') == 0
		|| (gamedata->map->can_exit == 0 && ft_check_next_tile(gamedata, keycode, 'E') == 0))
		return ;
	gamedata->player->steps++;
	// todo collect meth
	if (gamedata->player->collected == gamedata->map->amount_collectibles)
		gamedata->map->can_exit = 1;
	gamedata->map->map[gamedata->player->position_y][gamedata->player->position_x] = '0';
	if (keycode == 'd')
		gamedata->player->position_x++;
	else if (keycode == 'a')
		gamedata->player->position_x--;
	else if (keycode == 's')
		gamedata->player->position_y++;
	else if (keycode == 'w')
		gamedata->player->position_y--;
	// todo output
	// todo win game
	gamedata->map->map[gamedata->player->position_y][gamedata->player->position_x] = 'P';
}