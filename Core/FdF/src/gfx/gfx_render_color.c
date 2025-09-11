/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:30:02 by ibour             #+#    #+#             */
/*   Updated: 2025/09/11 11:50:24 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	gfx_render_color_z(const double ratio, const int a, const int b)
{
	int		red;
	int		green;
	int		blue;

	red = gfx_render_gradient_level((a >> 16) & 0xFF, (b >> 16) & 0xFF, ratio);
	green = gfx_render_gradient_level((a >> 8) & 0xFF, (b >> 8) & 0xFF, ratio);
	blue = gfx_render_gradient_level(a & 0xFF, b & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}

static int	gfx_render_color_y(const t_point p, const t_point a, const t_point b)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	ratio = gfx_render_gradient_percent(p.y, a.y, b.y);
	red = gfx_render_gradient_level((a.color >> 16) & 0xFF, (b.color >> 16) & 0xFF, ratio);
	green = gfx_render_gradient_level((a.color >> 8) & 0xFF, (b.color >> 8) & 0xFF, ratio);
	blue = gfx_render_gradient_level(a.color & 0xFF, b.color & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}

int			gfx_render_color_alt(t_data *data, double z)
{
	if (data->map.z_max == data->map.z_min)
		return ((z >= 0) ? COLOR_LOW : COLOR_SEA);
	if (z > data->map.z_max / 2)
		return (gfx_render_color_z(gfx_render_gradient_percent(z, data->map.z_max / 2,
		                                                       data->map.z_max), COLOR_MEDIUM, COLOR_HIGH));
	if (z >= 0)
		return (gfx_render_color_z(gfx_render_gradient_percent(z, 0, data->map.z_max / 2),
		                           COLOR_LOW, COLOR_MEDIUM));
	return (gfx_render_color_z(gfx_render_gradient_percent(z, data->map.z_min, 0), COLOR_SEA, COLOR_SHORE));
}

int			gfx_render_color_rainbow(const t_data *data, const t_point p)
{
	t_point	p_max;
	t_point p_min;
	t_point p_moy;

	p_max.y = data->map.y_max * data->map.scale + data->map.y_offset;
	p_max.x = 0;
	p_max.color = 0xFF0000;
	p_min.y = data->map.y_min * data->map.scale + data->map.y_offset;
	p_min.x = 0;
	p_min.color = 0x0000FF;
	p_moy.y = (p_max.y + p_min.y) / 2;
	p_moy.x = 0;
	p_moy.color = 0x00FF00;
	if (p.y >= p_moy.y)
		return (gfx_render_color_y(p, p_moy, p_max));
	else
		return (gfx_render_color_y(p, p_min, p_moy));
}

int	gfx_render_color(t_data *data, t_ipos a, t_ipos b, t_point p)
{
	int	color;

	if (data->map.color == MAP)
		color = gfx_render_gradient(data, p, data->map.points[a.i][a.j],
				data->map.points[b.i][b.j]);
	else if (data->map.color == ALTITUDE)
		color = gfx_render_color_alt(data, data->map.array[a.i][a.j]
				+ gfx_render_gradient_percent(p.y, data->map.points[a.i][a.j].y * data->map.scale
				+ data->map.y_offset, data->map.points[b.i][b.j].y
				* data->map.scale + data->map.y_offset)
				* (data->map.array[b.i][b.j] - data->map.array[a.i][a.j]));
	else if (data->map.color == RAINBOW)
		color = gfx_render_color_rainbow(data, p);
	else
		color = 0xFFFFFF;
	return (color);
}
