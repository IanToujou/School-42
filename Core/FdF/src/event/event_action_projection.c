/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action_projection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:23:37 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 10:29:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_action_projection(const int key, t_data *data)
{
	if (key == KEY_P)
		data->map.projection = PARALLEL;
	else if (key == KEY_I)
		data->map.projection = ISOMETRIC;
	data->map.altitude_ratio = 1;
	data->map.alpha = 0;
	data->map.beta = 0;
	data->map.gamma = 0;
	data->map.scale = 0;
	if (!gfx_project(data))
		error_throw(ERROR_RENDER_PROJECTION);
	util_place(data);
}
