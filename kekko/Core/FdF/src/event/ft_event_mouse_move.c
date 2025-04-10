/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_mouse_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 02:41:58 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 02:46:50 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int			ft_event_mouse_move(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *) param;
	data->mouse->previous_x = data->mouse->x;
	data->mouse->previous_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->is_pressed)
	{
		data->camera->beta += (x - data->mouse->previous_x) * 0.002;
		data->camera->alpha += (y - data->mouse->previous_y) * 0.002;
		ft_graphics_draw(data->map, data);
	}
	return (0);
}
