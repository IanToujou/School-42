/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:19:54 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 10:41:14 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_action_color(const int key, t_data *data)
{
	if (key == KEY_NUM_1)
		data->map.color = MONOCHROME;
	else if (key == KEY_NUM_2)
		data->map.color = ALTITUDE;
	else if (key == KEY_NUM_3)
		data->map.color = RAINBOW;
}