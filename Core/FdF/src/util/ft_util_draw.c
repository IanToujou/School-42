/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:52:32 by ibour             #+#    #+#             */
/*   Updated: 2024/12/18 13:27:46 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_put_pixel(const t_image *image, const int x, const int y, const int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * image->bpp / 8) + (y * image->size_line);

		image->data_addr[i] = color;
		image->data_addr[++i] = color >> 8;
		image->data_addr[++i] = color >> 16;
	}
}

static void	ft_util_draw_line(const t_data *data, const int x, const int y)
{
	if (y == 0 && x == 0)
		ft_util_draw_map(data->map, y, x);
	if (y + 1 < data->map->rows)
	{
		ft_util_draw_map(data->map, y + 1, x);
		ft_util_algo_line(data->image, data->map->grid2d[y][x],
			data->map->grid2d[y + 1][x]);
	}
	if (x + 1 < data->map->cols)
	{
		if (y == 0)
			ft_util_draw_map(data->map, y, x + 1);
		ft_util_algo_line(data->image, data->map->grid2d[y][x],
			data->map->grid2d[y][x + 1]);
	}
}

void	ft_util_draw_map(t_map *map, const int i, const int j)
{
	t_point3d	*previous;
	t_point3d	temp;
	t_point2d	*new;

	(void)i;
	(void)j;
	(void)map;
	(void)previous;
	(void)temp;
	(void)new;

	previous = &(map->grid3d[i][j]);
	new = &(map->grid2d[i][j]);
	temp.x = previous->x;
	temp.y = previous->y;
	temp.z = previous->z * map->z_scale;
	/*ft_util_rotate_z(&temp.x, &temp.y, map->z_rotate);
	ft_util_rotate_x(&temp.y, &temp.z, map->x_rotate);
	ft_util_rotate_y(&temp.x, &temp.z, map->y_rotate);*/
	new->x = (int)((temp.x * map->zoom - temp.y * map->zoom)
			* cos(map->alpha) + map->x_offset);
	new->y = (int)(-temp.z * map->zoom
			+ (temp.x * map->zoom + temp.y * map->zoom)
			* sin(map->beta) + map->y_offset);
	if (map->use_z_color)
		new->rgba = previous->z_color;
	else
		new->rgba = previous->map_color;
}

void	ft_util_draw_image(const t_data *data)
{
	int	i;
	int	j;

	ft_util_draw_reset(data->image);
	i = -1;
	while (++i < data->map->rows)
	{
		j = -1;
		while (++j < data->map->cols)
			ft_util_draw_line(data, j, i);
	}
}

void	ft_util_draw_reset(const t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			ft_put_pixel(image, j, i, BACKGROUND);
			j++;
		}
		i++;
	}
}
