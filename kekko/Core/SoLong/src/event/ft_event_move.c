/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:02:43 by ibour             #+#    #+#             */
/*   Updated: 2024/11/25 22:58:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_check_next_tile(t_gamedata *gd, char d, char t)
{
	if ((d == KEY_D
			&& gd->map->map[gd->player->position_y][gd->player->position_x
			+ 1] == t) || (d == KEY_A
			&& gd->map->map[gd->player->position_y][gd->player->position_x
			- 1] == t) || (d == KEY_S && gd->map->map[gd->player->position_y
			+ 1][gd->player->position_x] == t) || (d == KEY_W
			&& gd->map->map[gd->player->position_y
			- 1][gd->player->position_x] == t))
		return (0);
	return (-1);
}

void	ft_collect(t_gamedata *gd, char direction)
{
	if ((direction == 'd'
			&& gd->map->map[gd->player->position_y][gd->player->position_x
			+ 1] == 'C') || (direction == 'a'
			&& gd->map->map[gd->player->position_y][gd->player->position_x
			- 1] == 'C') || (direction == 's'
			&& gd->map->map[gd->player->position_y
			+ 1][gd->player->position_x] == 'C') || (direction == 'w'
			&& gd->map->map[gd->player->position_y
			- 1][gd->player->position_x] == 'C'))
		gd->player->collected++;
}

static void	ft_handle_quest(t_gamedata *gamedata)
{
	free(gamedata->str_quest);
	if (gamedata->player->collected >= gamedata->map->amount_collectibles)
		gamedata->str_quest = ft_strjoin("",
				"DELIVER THE METH TO GUSTAVO FRING");
	else
		gamedata->str_quest = ft_strjoin("",
				"COLLECT THE METH STOLEN BY THE MEXICAN CARTEL");
}

static int	ft_handle_win(t_gamedata *gamedata)
{
	if (gamedata->map->can_exit == 1)
	{
		ft_exit_mlx(gamedata);
		return (0);
	}
	return (-1);
}

void	ft_event_move(t_gamedata *gd, int k)
{
	if (ft_check_next_tile(gd, k, '1') == 0
		|| (gd->map->can_exit == 0
			&& ft_check_next_tile(gd, k, 'E') == 0))
		return ;
	gd->player->steps++;
	ft_collect(gd, k);
	if (gd->player->collected == gd->map->amount_collectibles)
		gd->map->can_exit = 1;
	gd->map->map[gd->player->position_y][gd->player->position_x] = '0';
	if (k == KEY_D)
		gd->player->position_x++;
	else if (k == KEY_A)
		gd->player->position_x--;
	else if (k == KEY_S)
		gd->player->position_y++;
	else if (k == KEY_W)
		gd->player->position_y--;
	ft_handle_quest(gd);
	ft_printf("Moves: %d\n", gd->player->steps);
	if (gd->map->can_exit == 1
		&& gd->map->map[gd->player->position_y][gd->player->position_x] == 'E')
		ft_handle_win(gd);
	gd->map->map[gd->player->position_y][gd->player->position_x] = 'P';
}
