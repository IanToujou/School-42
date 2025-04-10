/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_key_press.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 02:32:42 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 04:45:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	ft_event_key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *) param;
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_NUMPAD_PLUS || key == KEY_PLUS
		|| key == KEY_NUMPAD_MINUS || key == KEY_MINUS)
		ft_util_controls_zoom(key, data);
	else if (key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_UP || key == KEY_DOWN)
		ft_util_controls_move(key, data);
	else if (key == KEY_NUMPAD_ONE || key == KEY_ONE
		|| key == KEY_NUMPAD_TWO || key == KEY_TWO
		|| key == KEY_NUMPAD_THREE || key == KEY_THREE
		|| key == KEY_NUMPAD_FOUR || key == KEY_FOUR
		|| key == KEY_NUMPAD_SIX || key == KEY_SIX
		|| key == KEY_NUMPAD_SEVEN || key == KEY_SEVEN
		|| key == KEY_NUMPAD_EIGHT || key == KEY_EIGHT
		|| key == KEY_NUMPAD_NINE || key == KEY_NINE)
		ft_util_controls_rotate(key, data);
	else if (key == KEY_C || key == KEY_V)
		ft_util_controls_flatten(key, data);
	else if (key == KEY_P || key == KEY_I)
		ft_util_controls_project(key, data);
	return (0);
}
