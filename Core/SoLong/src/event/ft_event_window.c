/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:02:20 by ibour             #+#    #+#             */
/*   Updated: 2024/11/13 08:25:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_event_window(int window, t_gamedata *gamedata)
{
	if(window == WINDOW_GAME)
	{
		gamedata->window_page = WINDOW_GAME;
		mlx_clear_window(gamedata->mlx, gamedata->window);
	}
	return (0);
}