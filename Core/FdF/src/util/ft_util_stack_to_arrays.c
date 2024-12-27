/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_stack_to_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 02:53:00 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 02:57:45 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_util_stack_to_arrays(t_coord_val **coords_stack, t_map *map)
{
	t_coord_val	*coord;
	ssize_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	map->coords_arr = (int *) malloc(arr_size);
	if (!map->coords_arr)
		ft_throw_error(ERROR_ARRAY_CONVERSION);
	map->colors_arr = (int *) malloc(arr_size);
	if (!map->colors_arr)
		ft_throw_error(ERROR_ARRAY_CONVERSION);
	i = map->width * map->height - 1;
	while (i >= 0)
	{
		coord = ft_util_stack_pop(coords_stack);
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}
