/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:18:33 by ibour             #+#    #+#             */
/*   Updated: 2024/12/30 07:14:17 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	ft_util_map_free(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static t_coord_val	*ft_util_map_coord(char *s)
{
	t_coord_val	*coord;
	char		**parts;

	if (!(coord = (t_coord_val *) malloc(sizeof(t_coord_val))))
		ft_throw_error(ERROR_MAP_INVALID);
	if (!(parts = ft_util_split(s, ',')))
		ft_throw_error(ERROR_MAP_INVALID);
	if (!ft_util_isnum(parts[0], 10))
		ft_throw_error(ERROR_MAP_INVALID);
	if (parts[1] && !ft_util_isnum(parts[1], 16))
		ft_throw_error(ERROR_MAP_INVALID);
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_util_atoi_base(parts[1], 16) : -1;
	coord->next = NULL;
	ft_util_map_free(parts);
	return (coord);
}

static void	ft_map_parse_line(char **coords_line, t_coord_val **coords_stack, t_map *map)
{
	int	width;

	width = 0;
	int i = 0;
	while (*coords_line)
	{
		ft_util_stack_push(coords_stack, ft_util_map_coord(*(coords_line++)));
		width++;
		i++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width) {
		ft_throw_error(ERROR_MAP_INVALID);
	}
}

int	ft_util_map_read(const int fd, t_coord_val **coords_stack, t_map *map)
{
	char	*line;
	char	**coords_line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		coords_line = ft_util_split(line, ' ');
		if (!coords_line)
			ft_throw_error(ERROR_MAP_INVALID);
		ft_map_parse_line(coords_line, coords_stack, map);
		ft_util_map_free(coords_line);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	if (!(*coords_stack))
		ft_throw_error(ERROR_MAP_INVALID);
	return (0);
}