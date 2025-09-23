/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:50:54 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 09:49:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	gfx_render_line_low(t_data *data, t_ipos a, t_ipos b)
{
	t_point p;
	int		dx;
	int		dy;
	int		yi;
	int		delta;

	dx = (data->map.points[b.i][b.j].x - data->map.points[a.i][a.j].x) * data->map.scale;
	dy = (data->map.points[b.i][b.j].y - data->map.points[a.i][a.j].y) * data->map.scale;
	yi = (dy < 0) ? -1 : 1;
	dy = (dy < 0) ? -dy : dy;
	delta = 2 * dy - dx;
	p.y = data->map.points[a.i][a.j].y * data->map.scale + data->map.y_offset;
	p.x = data->map.points[a.i][a.j].x * data->map.scale + data->map.x_offset;
	while (p.x <= data->map.points[b.i][b.j].x * data->map.scale + data->map.x_offset)
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

static void	gfx_render_line_high(t_data *data, t_ipos p1, t_ipos p2)
{
	t_point p;
	int		dx;
	int		dy;
	int		xi;
	int		delta;

	dx = (data->map.points[p2.i][p2.j].x - data->map.points[p1.i][p1.j].x) * data->map.scale;
	dy = (data->map.points[p2.i][p2.j].y - data->map.points[p1.i][p1.j].y) * data->map.scale;
	xi = (dx < 0) ? -1 : 1;
	dx = (dx < 0) ? -dx : dx;
	delta = 2 * dx - dy;
	p.y = data->map.points[p1.i][p1.j].y * data->map.scale + data->map.y_offset;
	p.x = data->map.points[p1.i][p1.j].x * data->map.scale + data->map.x_offset;
	while (p.y <= data->map.points[p2.i][p2.j].y * data->map.scale + data->map.y_offset)
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

static void	gfx_render_line(t_data *data, t_ipos a, t_ipos b)
{
	if (fabs(data->map.points[b.i][b.j].y - data->map.points[a.i][a.j].y)
			< fabs(data->map.points[b.i][b.j].x - data->map.points[a.i][a.j].x))
	{
		if (data->map.points[a.i][a.j].x > data->map.points[b.i][b.j].x)
			gfx_render_line_low(data, b, a);
		else
			gfx_render_line_low(data, a, b);
	}
	else
	{
		if (data->map.points[a.i][a.j].y > data->map.points[b.i][b.j].y)
			gfx_render_line_high(data, b, a);
		else
			gfx_render_line_high(data, a, b);
	}
}

void	gfx_render(t_data *data)
{
	t_ipos	p_beg;
	t_ipos	p_end;
	int		i;
	int		j;

	if ((i = -1) && data->map.depth == 1 && data->map.width == 1)
		gfx_render_point(data);
	while (++i < data->map.depth && (j = -1))
		while (++j < data->map.width)
		{
			if (i != data->map.depth - 1)
			{
				p_beg = util_ipos_new(i, j);
				p_end = util_ipos_new(i + 1, j);
				gfx_render_line(data, p_beg, p_end);
			}
			if (j != data->map.width - 1)
			{
				p_beg = util_ipos_new(i, j);
				p_end = util_ipos_new(i, j + 1);
				gfx_render_line(data, p_beg, p_end);
			}
		}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
