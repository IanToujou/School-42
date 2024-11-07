/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:21:05 by ibour             #+#    #+#             */
/*   Updated: 2024/11/07 12:52:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_hook_key(const int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_game_lose(data);
	else if (keycode == W)
		ft_controller_move(data, 'y', UP);
	else if (keycode == A)
		ft_controller_move(data, 'x', LEFT);
	else if (keycode == S)
		ft_controller_move(data, 'y', DOWN);
	else if (keycode == D)
		ft_controller_move(data, 'x', RIGHT);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		ft_game_win(data);
	return (0);
}