/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:22:29 by ibour             #+#    #+#             */
/*   Updated: 2024/11/25 19:32:55 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_init_map(t_gamedata *gamedata, char **argv)
{
	if (ft_check_file_format(argv[1]) < 0)
		ft_throw_error(ERROR_MAP_FILE_FORMAT);
	gamedata->map->amount_collectibles = 0;
	gamedata->map->amount_exits = 0;
	gamedata->map->amount_players = 0;
	gamedata->map->can_exit = 0;
	gamedata->y = 0;
	gamedata->x = 0;
	gamedata->window_height = gamedata->map->size_y * IMG_WIDTH;
	gamedata->window_width = ((int)ft_strlen(gamedata->map->map[0]))
		* IMG_WIDTH;
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
