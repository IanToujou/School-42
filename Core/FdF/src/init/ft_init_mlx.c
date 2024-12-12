/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:32:00 by ibour             #+#    #+#             */
/*   Updated: 2024/12/12 14:48:19 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/**
 * Initializes the MLX library and creates a new window
 * to work with.
 *
 * @param data The data of the game.
 * @return 0 if the process was successful. -1 if an error occurred.
 */
int	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->window_width,
			data->window_height, WINDOW_NAME); // todo fix crash
	if (!data->window)
		return (-1);
	return (0);
}
