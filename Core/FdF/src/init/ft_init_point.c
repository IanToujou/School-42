/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:13:53 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 04:15:48 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_point	ft_init_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = ft_util_array_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	point.color = (map->colors_arr[index] == -1) ?
			ft_util_color_default(point.z, map) : map->colors_arr[index];
	return (point);
}
