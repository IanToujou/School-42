/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:54:05 by ibour             #+#    #+#             */
/*   Updated: 2024/11/15 14:15:01 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * Initializes the MLX library and creates a new window
 * to work with.
 *
 * @param gamedata
 * @return 0 if the process was successful. -1 if an error occurred.
 */
int	ft_init_mlx(t_gamedata *gamedata)
{
	gamedata->mlx = mlx_init();
	gamedata->window = mlx_new_window(gamedata->mlx, gamedata->window_width, gamedata->window_height, WINDOW_NAME);
	if (!gamedata->window)
		return (-1);
	return (0);
}