/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:31:44 by ibour             #+#    #+#             */
/*   Updated: 2024/12/17 09:20:33 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
		ft_error_throw(ERROR_MALLOC); // todo check if fix
		return (-1);
	}
	ft_default_values(map);
	ft_util_parse_dimensions(fd, map);
	close(fd);
	// malloc grid
	data->map = map;
	return (0);
}