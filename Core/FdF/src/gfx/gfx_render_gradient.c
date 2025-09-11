/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_gradient.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:39:34 by ibour             #+#    #+#             */
/*   Updated: 2025/09/11 11:41:01 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

double	gfx_render_gradient_percent(double current, double start, double end)
{
	return ((current - start) / (end - start));
}

int		gfx_render_gradient_level(int start, int end, double ratio)
{
	return ((int)((1 - ratio) * start + ratio * end));
}

int		gfx_render_gradient(t_data *data, t_point p, t_point a, t_point b)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	ratio = (b.x - a.x > b.y - a.y) ?
		gfx_render_gradient_percent(p.x, a.x * data->map.scale + data->map.x_offset, b.x
				* data->map.scale + data->map.x_offset)
		: gfx_render_gradient_percent(p.y, a.y * data->map.scale + data->map.y_offset, b.y
				* data->map.scale + data->map.y_offset);
	red = gfx_render_gradient_level((a.color >> 16) & 0xFF, (b.color >> 16) & 0xFF, ratio);
	green = gfx_render_gradient_level((a.color >> 8) & 0xFF, (b.color >> 8) & 0xFF, ratio);
	blue = gfx_render_gradient_level(a.color & 0xFF, b.color & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}
