/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:46:36 by ibour             #+#    #+#             */
/*   Updated: 2025/07/17 10:49:10 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static int	parse_depth(const int fd)
{
	char		buffer[4097];
	int			lines;
	int			i;
	ssize_t		j;

	if ((j = read(fd, buffer, 4096)) <= 0)
		return (0);
	buffer[j] = 0;
	lines = 1;
	while (j > 0)
	{
		i = -1;
		while (buffer[++i])
			lines += (buffer[i] == '\n');
		j = read(fd, buffer, 4096);
	}
	return (lines);
}

static int	parse_width(const int fd)
{
	return 10;
}

static void	init_map_array(t_data *data)
{
	int	i;

	data->map.array = (int **) malloc(sizeof(int *) * data->map.depth);
	if (!data->map.array)
		error_throw(ERROR_MALLOC);
	i = -1;
	while (++i < data->map.depth)
	{
		data->map.array[i] = (int *) malloc(sizeof(int) * data->map.width);
		if (!data->map.array[i])
		{
			// free main array
			error_throw(ERROR_MALLOC);
		}
	}
	data->map.points = (t_point **) malloc(sizeof(t_point *) * data->map.depth);
	if (!data->map.points)
		error_throw(ERROR_MALLOC);
	while (++i < data->map.depth)
	{
		data->map.points[i] = (t_point *) malloc(sizeof(t_point) * data->map.width);
		if (!data->map.points[i])
		{
			// free main array
			error_throw(ERROR_MALLOC);
		}
	}
}

void	init_parse(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_throw(ERROR_FILE_INVALID);
	data->map.depth = parse_depth(fd);
	data->map.width = parse_width(fd);
	close(fd);
	if (data->map.depth <= 0 || data->map.width <= 0)
		error_throw(ERROR_FILE_INVALID);
	init_map_array(data);
}
