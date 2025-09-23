/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action_altitude.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:28:57 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 09:43:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_action_altitude(const int key, t_data *data)
{
	if (key == KEY_UP)
		data->map.altitude_ratio *= 1 + ALT_INCR;
	else if (key == KEY_DOWN)
		data->map.altitude_ratio *= 1 - ALT_INCR;
	if (!gfx_project(data))
		error_throw(ERROR_RENDER_PROJECTION);
	util_place(data);
}
