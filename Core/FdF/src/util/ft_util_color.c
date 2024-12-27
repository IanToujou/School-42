/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 04:16:06 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 04:25:18 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	ft_util_color_default(const int z, const t_map *map)
{
	double	percentage;

	percentage = ft_util_percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	if (percentage < 0.8)
		return (COLOR_JAFFA);
	return (COLOR_SAFFRON);
}

int	ft_util_color_light(const int start, const int end, const double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	ft_util_color_get(const t_point current, const t_point start, const t_point end, const t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = ft_util_percent(start.x, end.x, current.x);
	else
		percentage = ft_util_percent(start.y, end.y, current.y);
	red = ft_util_color_light((start.color >> 16) & 0xFF,
					(end.color >> 16) & 0xFF,
					percentage);
	green = ft_util_color_light((start.color >> 8) & 0xFF,
					(end.color >> 8) & 0xFF,
					percentage);
	blue = ft_util_color_light(start.color & 0xFF,
					end.color & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}
