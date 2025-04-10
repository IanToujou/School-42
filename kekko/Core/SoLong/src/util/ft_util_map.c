/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:19:43 by ibour             #+#    #+#             */
/*   Updated: 2024/11/25 23:03:25 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_characters(t_gamedata *gamedata)
{
	while (gamedata->map->map[gamedata->y])
	{
		while (gamedata->map->map[gamedata->y][gamedata->x])
		{
			if (gamedata->map->map[gamedata->y][gamedata->x] == 'P')
				gamedata->map->amount_players++;
			else if (gamedata->map->map[gamedata->y][gamedata->x] == 'E')
				gamedata->map->amount_exits++;
			else if (gamedata->map->map[gamedata->y][gamedata->x] == 'C')
				gamedata->map->amount_collectibles++;
			gamedata->x++;
		}
		gamedata->x = 0;
		gamedata->y++;
	}
	if (!gamedata->map->amount_collectibles || !gamedata->map->amount_exits
		|| !gamedata->map->amount_players)
		return (-1);
	return (0);
}

static int	ft_check_edge_rows(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_edges(const int lines, char **map)
{
	int	i;

	i = 1;
	if (ft_check_edge_rows(0, map) == -1
		|| ft_check_edge_rows(lines - 1, map) == -1)
		return (-1);
	while (i < lines)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_rectangle(const t_gamedata *gamedata)
{
	int		y;
	size_t	x;

	y = 0;
	x = 0;
	gamedata->map->size_x = ft_strlen(gamedata->map->map[y]);
	while (gamedata->map->map[y])
	{
		while (gamedata->map->map[y][x] && gamedata->map->map[y][x] != '\n')
			x++;
		if (x != gamedata->map->size_x)
			return (-1);
		x = 0;
		y++;
	}
	return (0);
}

int	ft_check_file_format(const char *file)
{
	int	fd;

	if (open(file, O_DIRECTORY) >= 0)
	{
		fd = open(file, O_DIRECTORY);
		close(fd);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	close(fd);
	if ((file[strlen(file) - 4] != '.'
			&& file[strlen(file) - 3] != 'b'
			&& file[strlen(file) - 2] != 'e'
			&& file[strlen(file) - 1] != 'r') || fd < 0)
		return (-1);
	return (0);
}
