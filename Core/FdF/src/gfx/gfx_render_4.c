/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:05:23 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 13:05:36 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	calc_dx(t_data *data, t_ipos a, t_ipos b)
{
	return ((data->map.points[b.i][b.j].x - data->map.points[a.i][a.j].x)
		* data->map.scale);
}

int	calc_dy(t_data *data, t_ipos a, t_ipos b)
{
	return ((data->map.points[b.i][b.j].y - data->map.points[a.i][a.j].y)
		* data->map.scale);
}
