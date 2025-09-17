/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action_reset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:26:15 by ibour             #+#    #+#             */
/*   Updated: 2025/09/17 19:27:55 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_action_reset(t_data *data)
{
	data->map.color = MAP;
	data->map.altitude_ratio = 1;
	data->map.alpha = 0;
	data->map.beta = 0;
	data->map.gamma = 0;
	if (!gfx_project(data))
		error_throw(ERROR_RENDER_PROJECTION);
	util_place(data);
}
