/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:40:10 by ibour             #+#    #+#             */
/*   Updated: 2025/09/18 00:58:43 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init_data(t_data *data)
{
	data->map.altitude_ratio = 1;
	data->map.projection = ISOMETRIC;
	data->map.color = ALTITUDE;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->map.points = NULL;
	data->map.alpha = 0;
	data->map.beta = 0;
	data->map.gamma = 0;
	data->map.scale = 0;
	data->map.x_offset = 0;
	data->map.y_offset = 0;
	data->map.x_max = 0;
	data->map.x_min = 0;
	data->map.y_max = 0;
	data->map.y_min = 0;
	data->map.z_max = 0;
	data->map.z_min = 0;
}
