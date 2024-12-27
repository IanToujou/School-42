/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:18:33 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 05:22:04 by ibour            ###   ########.fr       */
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

static t_coord_val	*ft_util_map_coord(const char *s)
{
	t_coord_val	*coord;
	char		**parts;

	coord = (t_coord_val *) malloc(sizeof(t_coord_val));
	if (!coord)
		ft_throw_error(ERROR_MAP_INVALID);
	parts = ft_util_split(s, ',');
	if (!parts)
		ft_throw_error(ERROR_MAP_INVALID);
	if (!ft_util_isnum(parts[0], 10))
		ft_throw_error(ERROR_MAP_INVALID);
	if (parts[1] && !ft_util_isnum(parts[1], 16))
		ft_throw_error(ERROR_MAP_INVALID);
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_atoi_base(parts[1], "123456789ABCDEF") : -1;
	coord->next = NULL;
	ft_util_map_free(parts);
	return (coord);
}

static void	ft_map_parse_line(char **coords_line, t_coord_val **coords_stack, t_map *map)
{
	int	width;

	width = 0;
	while (*coords_line)
	{
		printf("%s\n", *coords_line); fflush(stdout);
		ft_util_stack_push(coords_stack, ft_util_map_coord(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width) {
		ft_throw_error(ERROR_MAP_INVALID);
	}
}

int	ft_util_map_read(const int fd,t_coord_val **coords_stack, t_map *map)
{
	char	*line;
	int		result;
	char	**coords_line;

	while ((result = ft_util_gnl(fd, &line)) == 1)
	{
		printf("%s\n", line); fflush(stdout);
		if (!(coords_line = ft_util_split(line, ' ')))
			ft_throw_error(ERROR_MAP_INVALID);
		ft_map_parse_line(coords_line, coords_stack, map);
		ft_util_map_free(coords_line);
		ft_strdel(&line);
		map->height++;
	}
	if (!(*coords_stack))
		ft_throw_error(ERROR_MAP_INVALID);
	return (result);
}