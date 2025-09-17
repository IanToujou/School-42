/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:26:56 by ibour             #+#    #+#             */
/*   Updated: 2025/09/17 20:07:36 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	valid_key(const int k)
{
	if (k == KEY_NUMPAD_1 || k == KEY_NUMPAD_2 || k == KEY_NUMPAD_3 || k == KEY_NUMPAD_4
			|| k == KEY_NUMPAD_6 || k == KEY_NUMPAD_7 || k == KEY_NUMPAD_8 || k == KEY_NUMPAD_9
			|| k == KEY_A || k == KEY_W || k == KEY_S || k == KEY_D || k == KEY_SPACE
			|| k == KEY_NUMPAD_PLUS || k == KEY_NUMPAD_MINUS || k == KEY_UP || k == KEY_DOWN
			|| k == KEY_ESC || k == KEY_R)
		return (1);
	return (0);
}

int	event_keypress(const int k, t_data *data)
{
	/*if (!valid_key(k))
		return (0);*/
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
	gfx_render(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	if (k == KEY_ESC)
		event_close(data);
	return (0);
}
