/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_project_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:54:31 by ibour             #+#    #+#             */
/*   Updated: 2025/09/10 17:34:49 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	gfx_project_calc_parallel(t_data *data, int i, int j)
{
	double	x;
	double	y;
	double	z;

	x = i;
	y = j;
	z = data->map.array[i][j];
	data->map.points[i][j].z = data->map.array[i][j];
	util_rotation_x(&y, &z, data->map.alpha);
	util_rotation_y(&x, &z, data->map.beta);
	util_rotation_z(&x, &y, data->map.gamma);
	if ((data->map.points[i][j].x = y + cos(M_PI / 4) * (data->map.depth - x)) > data->map.x_max)
		data->map.x_max = data->map.points[i][j].x;
	data->map.x_min = (data->map.points[i][j].x < data->map.x_min) ? data->map.points[i][j].x : data->map.x_min;
	if ((data->map.points[i][j].y = -(z * data->map.altitude_ratio + sin(M_PI / 4)
					* (data->map.depth - x))) > data->map.y_max)
		data->map.y_max = data->map.points[i][j].y;
	data->map.y_min = (data->map.points[i][j].y < data->map.y_min) ? data->map.points[i][j].y : data->map.y_min;
}

void	gfx_project_calc_isometric(t_data *data, const int i, const int j)
{
	double	x;
	double	y;
	double	z;

	x = i;
	y = j;
	z = data->map.array[i][j];
	data->map.points[i][j].z = data->map.array[i][j];
	util_rotation_x(&y, &z, data->map.alpha);
	util_rotation_y(&x, &z, data->map.beta);
	util_rotation_z(&x, &y, data->map.gamma);
	if ((data->map.points[i][j].x = (x + y) * cos(M_PI / 6) * data->map.depth / 2)
			> data->map.x_max)
		data->map.x_max = data->map.points[i][j].x;
	data->map.x_min = (data->map.points[i][j].x < data->map.x_min) ? data->map.points[i][j].x : data->map.x_min;
	if ((data->map.points[i][j].y = (x - y) * sin(M_PI / 6) * data->map.width / 2 - z
				* data->map.width / 2 * data->map.altitude_ratio) > data->map.y_max)
		data->map.y_max = data->map.points[i][j].y;
	data->map.y_min = (data->map.points[i][j].y < data->map.y_min) ? data->map.points[i][j].y : data->map.y_min;
}

void gfx_project_calc_top(const t_data *data, const int i, const int j) {
	double	x;
	double	y;
	double	z;

	x = i;
	y = j;
	z = data->map.array[i][j];
	data->map.points[i][j].z = data->map.array[i][j];
	util_rotation_x(&y, &z, data->map.alpha);
	util_rotation_y(&x, &z, data->map.beta);
	util_rotation_z(&x, &y, data->map.gamma);
	data->map.points[i][j].x = y;
	data->map.points[i][j].y = x;
}