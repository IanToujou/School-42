/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:05:32 by ibour             #+#    #+#             */
/*   Updated: 2025/09/15 18:22:34 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	util_place(t_data *data)
{
	double	temp;

	if (data->map.width == 1 && data->map.depth == 1)
	{
		data->map.scale = 1;
		data->map.x_offset = WIDTH / 2;
		data->map.y_offset = HEIGHT / 2;
	}
	else
	{
		data->map.scale = (WIDTH - 2 * MARGIN)
			/ (data->map.x_max - data->map.x_min);
		temp = (HEIGHT - 2 * MARGIN) / (data->map.y_max
				- data->map.y_min);
		data->map.scale = (temp < data->map.scale) ?
			temp : data->map.scale;
		data->map.x_offset = nearbyint((WIDTH - ((data->map.x_max
				- data->map.x_min) * data->map.scale)) / 2
				- data->map.x_min * data->map.scale);
		data->map.y_offset = nearbyint((HEIGHT - ((data->map.y_max
				- data->map.y_min) * data->map.scale)) / 2
				- data->map.y_min * data->map.scale);
	}
}
