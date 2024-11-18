/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:02:43 by ibour             #+#    #+#             */
/*   Updated: 2024/11/18 10:00:15 by ibour            ###   ########.fr       */
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

void	ft_collect(t_gamedata *gamedata, char direction)
{
	if ((direction == 'd' && gamedata->map->map[gamedata->player->position_y][gamedata->player->position_x + 1] == 'C')
		|| (direction == 'a' && gamedata->map->map[gamedata->player->position_y][gamedata->player->position_x - 1] == 'C')
		|| (direction == 's' && gamedata->map->map[gamedata->player->position_y + 1][gamedata->player->position_x] == 'C')
		|| (direction == 'w' && gamedata->map->map[gamedata->player->position_y - 1][gamedata->player->position_x] == 'C'))
		gamedata->player->collected++;
}

static void	ft_handle_quest(t_gamedata *gamedata)
{
	free(gamedata->str_quest);
	if (gamedata->player->collected >= gamedata->map->amount_collectibles)
		gamedata->str_quest = ft_strjoin("", "DELIVER THE METH TO GUSTAVO FRING");
	else
		gamedata->str_quest = ft_strjoin("", "COLLECT THE METH STOLEN BY THE MEXICAN CARTEL");
}

static int	ft_handle_win(t_gamedata *gamedata)
{
	if (gamedata->map->can_exit == 1)
	{
		// todo just testing
		/*mlx_destroy_window(gamedata->mlx, gamedata->window);
		gamedata->window = NULL;*/
		gamedata->window_page = WINDOW_DEATH;
		return (0);
	}
	return (-1);
}

void	ft_event_move(t_gamedata *gamedata, int keycode)
{
	if (ft_check_next_tile(gamedata, keycode, '1') == 0
		|| (gamedata->map->can_exit == 0 && ft_check_next_tile(gamedata, keycode, 'E') == 0))
		return ;
	gamedata->player->steps++;
	ft_collect(gamedata, keycode);
	if (gamedata->player->collected == gamedata->map->amount_collectibles)
		gamedata->map->can_exit = 1;
	gamedata->map->map[gamedata->player->position_y][gamedata->player->position_x] = '0';
	if (keycode == KEY_D)
		gamedata->player->position_x++;
	else if (keycode == KEY_A)
		gamedata->player->position_x--;
	else if (keycode == KEY_S)
		gamedata->player->position_y++;
	else if (keycode == KEY_W)
		gamedata->player->position_y--;
	ft_handle_quest(gamedata);
	ft_printf("Moves: %d\n", gamedata->player->steps);
	if (gamedata->map->can_exit == 1 && gamedata->map->map[gamedata->player->position_y][gamedata->player->position_x] == 'E')
		ft_handle_win(gamedata);
	gamedata->map->map[gamedata->player->position_y][gamedata->player->position_x] = 'P';
}