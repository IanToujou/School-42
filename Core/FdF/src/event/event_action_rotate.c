/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 00:55:41 by ibour             #+#    #+#             */
/*   Updated: 2025/09/18 04:36:22 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_action_rotate(const int k, t_data *data)
{
	if (k == KEY_NUMPAD_4)
		data->map.beta -= ANGLE_INCR;
	if (k == KEY_NUMPAD_8)
		data->map.alpha += ANGLE_INCR;
	if (k == KEY_NUMPAD_6)
		data->map.beta += ANGLE_INCR;
	if (k == KEY_NUMPAD_2)
		data->map.alpha -= ANGLE_INCR;
	if (k == KEY_NUMPAD_7 || k == KEY_NUMPAD_9)
		data->map.gamma += ANGLE_INCR;
	if (k == KEY_NUMPAD_1 || k == KEY_NUMPAD_3)
		data->map.gamma -= ANGLE_INCR;
	if (!gfx_project(data))
		error_throw(ERROR_RENDER_PROJECTION);
	util_place(data);
}
