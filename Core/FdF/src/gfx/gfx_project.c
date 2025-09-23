/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:44:20 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 10:30:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	gfx_project_init(t_data *data)
{
	if (data->map.projection == PARALLEL)
	{
		data->map.x_max = cos(M_PI / 4) * data->map.depth;
		data->map.x_min = data->map.x_max;
		data->map.y_max = -(data->map.array[0][0]
				+ sin(M_PI / 4) * data->map.depth);
		data->map.y_min = data->map.y_max;
	}
	if (data->map.projection == ISOMETRIC)
	{
		data->map.x_max = 0;
		data->map.x_min = 0;
		data->map.y_max = -data->map.array[0][0] * data->map.width / 2;
		data->map.y_min = data->map.y_max;
	}
}

static void	gfx_project_parallel(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map.depth)
	{
		j = -1;
		while (++j < data->map.width)
			gfx_project_calc_parallel(data, i, j);
	}
}

static void	gfx_project_isometric(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map.depth)
	{
		j = -1;
		while (++j < data->map.width)
			gfx_project_calc_isometric(data, i, j);
	}
}

int	gfx_project(t_data *data)
{
	gfx_project_init(data);
	if (data->map.projection == ISOMETRIC)
		gfx_project_isometric(data);
	else if (data->map.projection == PARALLEL)
		gfx_project_parallel(data);
	else
		return (0);
	return (1);
}
