/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:50:54 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 13:05:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	gfx_render_line(t_data *data, t_ipos a, t_ipos b)
{
	if (should_use_low_line(data, a, b))
		render_low_line_direction(data, a, b);
	else
		render_high_line_direction(data, a, b);
}

static void	render_vertical_line(t_data *data, int i, int j)
{
	t_ipos	p_beg;
	t_ipos	p_end;

	p_beg = util_ipos_new(i, j);
	p_end = util_ipos_new(i + 1, j);
	gfx_render_line(data, p_beg, p_end);
}

static void	render_horizontal_line(t_data *data, int i, int j)
{
	t_ipos	p_beg;
	t_ipos	p_end;

	p_beg = util_ipos_new(i, j);
	p_end = util_ipos_new(i, j + 1);
	gfx_render_line(data, p_beg, p_end);
}

static void	render_grid_lines(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.depth)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (i != data->map.depth - 1)
				render_vertical_line(data, i, j);
			if (j != data->map.width - 1)
				render_horizontal_line(data, i, j);
			j++;
		}
		i++;
	}
}

void	gfx_render(t_data *data)
{
	if (data->map.depth == 1 && data->map.width == 1)
		gfx_render_point(data);
	else
		render_grid_lines(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
