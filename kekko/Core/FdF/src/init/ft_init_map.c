/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:06:12 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 03:04:36 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_map		*ft_init_map(void)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		ft_throw_error(ERROR_MALLOC);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = FT_INT_MAX;
	map->z_max = FT_INT_MIN;
	map->z_range = 0;
	return (map);
}
