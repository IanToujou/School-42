/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:01:14 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 13:05:14 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	get_yi_and_adjust_dy(int *dy)
{
	int	yi;

	if (*dy < 0)
	{
		yi = -1;
		*dy = -*dy;
	}
	else
		yi = 1;
	return (yi);
}

void	init_line_low_point(t_data *data, t_ipos a, t_point *p)
{
	p->y = data->map.points[a.i][a.j].y * data->map.scale + data->map.y_offset;
	p->x = data->map.points[a.i][a.j].x * data->map.scale + data->map.x_offset;
}

void	gfx_render_line_low(t_data *data, t_ipos a, t_ipos b)
{
	t_point	p;
	int		dx;
	int		dy;
	int		yi;
	int		delta;

	dx = calc_dx(data, a, b);
	dy = calc_dy(data, a, b);
	yi = get_yi_and_adjust_dy(&dy);
	delta = 2 * dy - dx;
	init_line_low_point(data, a, &p);
	while (p.x <= data->map.points[b.i][b.j].x
		* data->map.scale + data->map.x_offset)
	{
		p.color = gfx_render_color(data, a, b, p);
		gfx_render_pixel(data, p);
		if (delta > 0)
		{
			p.y += yi;
			delta -= 2 * dx;
		}
		delta += 2 * dy;
		p.x++;
	}
}

int	get_xi_and_adjust_dx(int *dx)
{
	int	xi;

	if (*dx < 0)
	{
		xi = -1;
		*dx = -*dx;
	}
	else
	{
		xi = 1;
	}
	return (xi);
}
