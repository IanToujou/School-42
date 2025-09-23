/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:23:46 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 10:41:05 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void		gfx_render_pixel(const t_data *data, const t_point p)
{
	int		x;
	int		y;

	x = p.x;
	y = p.y;
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
		data->addr[x + y * WIDTH] = p.color;
}

void	gfx_render_point(t_data *data)
{
	t_point	p;

	p.x = data->map.x_offset;
	p.y = data->map.y_offset;
	if (data->map.color == MONOCHROME)
		p.color = 0xFFFFFF;
	else if (data->map.color == ALTITUDE)
		p.color = (data->map.array[0][0] < 0) ? COLOR_SEA : COLOR_LOW;
	else if (data->map.color == RAINBOW)
		p.color = 0xFF0000;
	gfx_render_pixel(data, p);
}