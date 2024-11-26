/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:54:05 by ibour             #+#    #+#             */
/*   Updated: 2024/11/26 21:17:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

/**
 * Initializes the MLX library and creates a new window
 * to work with.
 *
 * @param gamedata The data of the game.
 * @return 0 if the process was successful. -1 if an error occurred.
 */
int	ft_init_mlx(t_engine *engine)
{
	engine->mlx = mlx_init();
	engine->window = mlx_new_window(engine->mlx, engine->window_width,
			engine->window_height, WINDOW_NAME);
	if (!engine->window)
		return (-1);
	return (0);
}

/**
 * Exits the MLX library and closes any existing windows.
 *
 * @param gamedata The data of the game.
 */
void	ft_exit_mlx(t_engine *engine)
{
	mlx_destroy_window(engine->mlx, engine->window);
	engine->window = NULL;
}
