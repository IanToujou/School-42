/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics_project.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:10:43 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 04:21:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	ft_graphics_rotate_x(int *y, int *z, const double alpha)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	ft_graphics_rotate_y(int *x, int *z, const double beta)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void	ft_graphics_rotate_z(int *x, int *y, const double gamma)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

static void	ft_graphics_project_isometric(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point		ft_graphics_project(t_point p, const t_data *data)
{
	p.x *= data->camera->zoom;
	p.y *= data->camera->zoom;
	p.z *= data->camera->zoom / data->camera->z_divisor;
	p.x -= (data->map->width * data->camera->zoom) / 2;
	p.y -= (data->map->height * data->camera->zoom) / 2;
	ft_graphics_rotate_x(&p.y, &p.z, data->camera->alpha);
	ft_graphics_rotate_y(&p.x, &p.z, data->camera->beta);
	ft_graphics_rotate_z(&p.x, &p.y, data->camera->gamma);
	if (data->camera->projection == ISOMETRIC)
		ft_graphics_project_isometric(&p.x, &p.y, p.z);
	p.x += (WINDOW_WIDTH - MENU_WIDTH) / 2 + data->camera->x_offset + MENU_WIDTH;
	p.y += (WINDOW_HEIGHT + data->map->height * data->camera->zoom) / 2
												+ data->camera->y_offset;
	return (p);
}
