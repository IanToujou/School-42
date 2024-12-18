/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:31:44 by ibour             #+#    #+#             */
/*   Updated: 2024/12/18 13:46:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	ft_init_grid(t_map *map)
{
	int	i;

	map->grid3d = malloc(sizeof(t_point3d *) * map->rows);
	map->grid2d = malloc(sizeof(t_point2d *) * map->rows);
	if (!(map->grid2d) || !(map->grid3d))
	{
		ft_util_free_map(map);
		ft_error_throw(ERROR_MALLOC);
	}
	i = -1;
	while (++i < map->rows)
	{
		map->grid3d[i] = malloc(sizeof(t_point3d) * map->cols);
		map->grid2d[i] = malloc(sizeof(t_point2d) * map->cols);
		if (!(map->grid2d[i]) || !(map->grid3d[i]))
		{
			if (i + 1 < map->rows)
			{
				map->grid3d[i + 1] = NULL;
				map->grid2d[i + 1] = NULL;
			}
			ft_util_free_map(map);
			ft_error_throw(ERROR_MALLOC);
		}
	}
}

static void	ft_default_values(t_map *map)
{
	map->alpha = 0.46373398 / 2;
	map->beta = 0.46373398;
	map->x_rotate = 0;
	map->y_rotate = 0;
	map->z_rotate = 0;
	map->x_offset = WIDTH / 2;
	map->y_offset = HEIGHT / 2;
	map->zoom = 1;
	map->z_scale = 1;
	map->use_z_color = false;
	map->high = INT_MIN;
	map->low = INT_MAX;
	map->rows = 0;
	map->cols = 0;
	map->grid2d = NULL;
	map->grid3d = NULL;
}

int	ft_init_map(t_data *data, const char *arg)
{
	int	fd;
	t_map	*map;

	fd = open(arg, O_RDONLY, 0777);
	if (fd == -1)
		ft_error_throw(ERROR_FILE);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		ft_error_throw(ERROR_MALLOC);
		return (-1);
	}
	ft_default_values(map);
	ft_util_parse_dimensions(fd, map);
	close(fd);
	ft_init_grid(map);
	map->interval = ft_min(WIDTH / map->cols, HEIGHT / map->rows) / 2;
	map->interval = ft_max(2, map->interval);
	fd = open(arg, O_RDONLY, 0777);
	ft_util_parse_map(fd, map);
	close(fd);
	// todo color
	data->map = map;
	return (0);
}
