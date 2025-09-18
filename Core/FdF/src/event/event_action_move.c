/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:47:03 by ibour             #+#    #+#             */
/*   Updated: 2025/09/18 04:36:17 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_action_move(const int k, t_data *data)
{
	if (k == KEY_A)
		data->map.x_offset += OFFSET_INCR;
	if (k == KEY_D)
		data->map.x_offset -= OFFSET_INCR;
	if (k == KEY_S)
		data->map.y_offset -= OFFSET_INCR;
	if (k == KEY_W)
		data->map.y_offset += OFFSET_INCR;
}
