/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:56:24 by ibour             #+#    #+#             */
/*   Updated: 2024/12/17 09:39:05 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	ft_util_parse_color(const int fd, t_map *map, char *color)
{
	while (*color == '-')
		color++;
	while (ft_isdigit(*color))
		color++;
	if (*color == ',')
		color++;
	else
		return (0xFFFFFFFF);
	if ((ft_strncmp(color, "0X", 2) && ft_strncmp(color, "0x", 2)))
		ft_error_throw_map(fd, map, ERROR_MAP_INVALID);
	color += 2;
	ft_striteri(color, &ft_util_str_upper);
	return ((ft_atoi_base(color, "0123456789ABCDEF") << 8) | 0xFF);
}

static void	ft_util_parse_column(const int fd, t_map *map, char **tab, const int i)
{
	t_point3d	*point;
	int			x_offset;
	int			y_offset;
	int			j;

	j = -1;
	while (++j < map->cols)
	{
		if (!ft_isdigit(*tab[j]) && *tab[j] != '-')
			ft_error_throw_map(fd, map, ERROR_MAP_INVALID);
		point = &(map->grid3d[i][j]);
		x_offset = (map->cols - 1) * map->interval / 2;
		y_offset = (map->rows - 1) * map->interval / 2;
		point->x = (double)j * (map->interval) - x_offset;
		point->y = (double)i * (map->interval) - y_offset;
		point->z = (double)ft_atoi(tab[j]) * (map->interval);
		map->high = ft_max(map->high, point->z);
		map->low = ft_min(map->low, point->z);
		point->map_color = ft_util_parse_color(fd, map, tab[j]);
	}
}

static int	ft_util_parse_cols(const int fd, t_map *map, char *line)
{
	char	**tab;
	char	*temp;
	int		i;

	temp = ft_strdup(line);
	free(line);
	if (!temp)
		ft_error_throw_map(fd, map, ERROR_MALLOC);
	tab = ft_split(temp, ' ');
	free(temp);
	if (!tab)
	{
		ft_error_throw_map(fd, map, ERROR_MALLOC);
		return (-1);
	}
	i = 0;
	while (tab[i]) {
		map->high = ft_max(map->high, ft_atoi(tab[i]));
		map->low = ft_min(map->low, ft_atoi(tab[i]));
		i++;
	}
	ft_util_free_array((void **) tab, i);
	return (i);
}

void	ft_util_parse_map(int fd, t_map *map)
{
	char	*line;
	char	*temp;
	char	**tab;
	int		i;

	i = -1;
	while (++i < map->rows)
	{
		temp = get_next_line(fd);
		if (!temp)
			ft_error_throw_map(fd, map, ERROR_MALLOC);
		line = ft_strtrim(temp, "\n");
		free(temp);
		if (!line)
			ft_error_throw_map(fd, map, ERROR_MALLOC);
		tab = ft_split(line, ' ');
		free(line);
		if (!tab)
			ft_error_throw_map(fd, map, ERROR_MALLOC);
		ft_util_parse_column(fd, map, tab, i);
		ft_util_free_array((void **) tab, map->cols);
	}
}

void	ft_util_parse_dimensions(const int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error_throw_map(fd, map, ERROR_INIT_MAP);
	map->cols = ft_util_parse_cols(fd, map, line);
	if(map->cols == 0)
		ft_error_throw_map(fd, map, ERROR_INIT_MAP);
	map->rows = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->rows++;
		if (map->cols != ft_util_parse_cols(fd, map, line))
			ft_error_throw_map(fd, map, ERROR_INIT_MAP);
	}
}
