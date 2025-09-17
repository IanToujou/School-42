/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:26:56 by ibour             #+#    #+#             */
/*   Updated: 2025/09/18 00:46:58 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../include/fdf.h"

void debug_keycode(int keycode) {
	printf("Key pressed: %d\n", keycode);
}

int	event_keypress(const int k, t_data *data)
{
	debug_keycode(k);
	ft_bzero(data->addr, WIDTH * HEIGHT * 4);
	event_action_move(k, data);
	if (k == KEY_SPACE)
		event_action_reset(data);
	else if (k == KEY_NUMPAD_PLUS || k == KEY_NUMPAD_MINUS)
		event_action_zoom(k, &(data->map.scale));
	/*else if (k == UP_ARROW || k == DOWN_ARROW || k == PAD_1
			|| k == PAD_2 || k == PAD_3 || k == PAD_4 || k == PAD_6
			|| k == PAD_7 || k == PAD_8 || k == PAD_9)
		event_action_altitude_move(k, data);*/
	if (!gfx_project(data))
		error_throw(ERROR_RENDER_PROJECTION);
	util_place(data);
	gfx_render(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	if (k == KEY_ESC)
		event_close(data);
	return (0);
}
