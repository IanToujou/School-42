/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:47:03 by ibour             #+#    #+#             */
/*   Updated: 2025/09/18 00:45:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_action_move(const int k, t_data *data)
{
	if (k == KEY_NUMPAD_4) {
		printf("numpad 4\n"); fflush(stdout);
		data->map.beta -= ANGLE_INCR;
		printf("angle is now: %f\n", data->map.beta); fflush(stdout);
	}

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
	if (k == KEY_A)
		data->map.x_offset += OFFSET_INCR;
	if (k == KEY_D)
		data->map.x_offset -= OFFSET_INCR;
	if (k == KEY_S)
		data->map.y_offset -= OFFSET_INCR;
	if (k == KEY_W)
		data->map.y_offset += OFFSET_INCR;
}