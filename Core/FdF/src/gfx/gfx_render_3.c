/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:01:20 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 13:04:57 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	gfx_render_line_high(t_data *data, t_ipos p1, t_ipos p2)
{
	t_point	p;
	int		dx;
	int		dy;
	int		xi;
	int		delta;

	dx = calc_dx(data, p1, p2);
	dy = calc_dy(data, p1, p2);
	xi = get_xi_and_adjust_dx(&dx);
	delta = 2 * dx - dy;
	init_line_high_point(data, p1, &p);
	while (p.y <= data->map.points[p2.i][p2.j].y
			* data->map.scale + data->map.y_offset)
	{
		p.color = gfx_render_color(data, p1, p2, p);
		gfx_render_pixel(data, p);
		if (delta > 0)
		{
			p.x += xi;
			delta -= 2 * dy;
		}
		delta += 2 * dx;
		p.y++;
	}
}

int	should_use_low_line(t_data *data, t_ipos a, t_ipos b)
{
	double	y_diff;
	double	x_diff;

	y_diff = fabs(data->map.points[b.i][b.j].y - data->map.points[a.i][a.j].y);
	x_diff = fabs(data->map.points[b.i][b.j].x - data->map.points[a.i][a.j].x);
	return (y_diff < x_diff);
}

void	render_low_line_direction(t_data *data, t_ipos a, t_ipos b)
{
	if (data->map.points[a.i][a.j].x > data->map.points[b.i][b.j].x)
		gfx_render_line_low(data, b, a);
	else
		gfx_render_line_low(data, a, b);
}

void	render_high_line_direction(t_data *data, t_ipos a, t_ipos b)
{
	if (data->map.points[a.i][a.j].y > data->map.points[b.i][b.j].y)
		gfx_render_line_high(data, b, a);
	else
		gfx_render_line_high(data, a, b);
}

void	init_line_high_point(t_data *data, t_ipos p1, t_point *p)
{
	p->y = data->map.points[p1.i][p1.j].y
		* data->map.scale + data->map.y_offset;
	p->x = data->map.points[p1.i][p1.j].x
		* data->map.scale + data->map.x_offset;
}
