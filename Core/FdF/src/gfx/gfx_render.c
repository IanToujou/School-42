/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:50:54 by ibour             #+#    #+#             */
/*   Updated: 2025/09/10 18:25:57 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
