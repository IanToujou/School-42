/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:22:29 by ibour             #+#    #+#             */
/*   Updated: 2024/11/15 13:59:05 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int ft_check_characters(t_gamedata *gamedata)
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
	if (!gamedata->map->amount_collectibles || !gamedata->map->amount_exits || !gamedata->map->amount_players)
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

static int	check_edges(int line_count, char **map)
{
	int	i;

	i = 1;
	if (ft_check_edge_rows(0, map) == -1
		|| ft_check_edge_rows(line_count-1, map) == -1)
		return (-1);
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_check_rectangle(t_gamedata *gamedata)
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

static int ft_check_file_format(const char *file)
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
	if ((file[strlen(file) - 4] != '.' &&
		file[strlen(file) - 3] != 'b' &&
		file[strlen(file) - 2] != 'e' &&
		file[strlen(file) - 1] != 'r') || fd < 0)
			return (-1);
	return (0);
}

int	ft_check_map(t_gamedata *gamedata)
{
	int		y;
	size_t	x;

	y = 0;
	x = 0;
	while (gamedata->map->map[y])
	{
		while (x < ft_strlen(gamedata->map->map[y]) - 1)
		{
			if (ft_strchr("0123CEP", gamedata->map->map[y][x]) == NULL)
				ft_throw_error(ERROR_MAP_OTHER);
			x++;
		}
		x = 0;
		y++;
	}
	if (ft_check_characters(gamedata) == -1)
		ft_throw_error(ERROR_MAP_CHARACTERS);
	if (gamedata->map->amount_players > 1)
		ft_throw_error(ERROR_MAP_PLAYER);
	if (ft_check_rectangle(gamedata) == -1)
		ft_throw_error(ERROR_MAP_RECTANGLE);
	if (check_edges(gamedata->map->size_y, gamedata->map->map) == -1)
		ft_throw_error(ERROR_MAP_EDGES);
	return (0);
}

int	ft_init_map(t_gamedata *gamedata, char **argv)
{
	if(ft_check_file_format(argv[1]) < 0)
		ft_throw_error(ERROR_MAP_FILE_FORMAT);
	gamedata->map->amount_collectibles = 0;
	gamedata->map->amount_exits = 0;
	gamedata->map->amount_players = 0;
	gamedata->map->can_exit = 0;
	gamedata->y = 0;
	gamedata->x = 0;
	gamedata->window_height = gamedata->map->size_y * IMG_WIDTH;
	gamedata->window_width = (ft_strlen(gamedata->map->map[0])) * IMG_WIDTH;
	return (0);
}

static int	ft_line_count(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_throw_error(ERROR_FILE);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

int	ft_exit_map(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
	return (0);
}

static int	ft_put_map(int row, int column, int i, t_gamedata *gamedata)
{
	char	*line;

	line = get_next_line(gamedata->map->fd);
	while (line != NULL)
	{
		gamedata->map->map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!gamedata->map->map[row])
			return (ft_exit_map(gamedata->map->map));
		while (line[i] != '\0' && line[i] != '\n')
			gamedata->map->map[row][column++] = line[i++];
		gamedata->map->map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(gamedata->map->fd);
	}
	gamedata->map->map[row] = NULL;
	return (0);
}

int	ft_create_map(t_gamedata *data, char *path)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->map->size_y = ft_line_count(path);
	data->map->path = path;
	data->map->map = ft_calloc(data->map->size_y + 1, sizeof(char *));
	if (!(data->map->map))
		return (-1);
	data->map->fd = open(path, O_RDONLY);
	if (data->map->fd < 0)
		ft_throw_error(ERROR_FILE);
	else
	{
		ft_put_map(row, column, i, data);
		close(data->map->fd);
	}
	return (0);
}