/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:52:24 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 12:42:59 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	init_map_read_line(t_data *data, const char *line)
{
	char		**array;
	static int	current_row = 0;

	if (line[0] == 0 || line[0] == '\n')
		error_throw(ERROR_INIT_PARSE);
	array = ft_split(line, ' ');
	if (!array)
		error_throw(ERROR_MALLOC);
	process_line_elements(data, array, current_row);
	current_row++;
	util_array_free((void **) array);
}

void	init_map_array_rows(t_data *data)
{
	int	i;

	data->map.array = (int **) malloc(sizeof(int *) * data->map.depth);
	if (!data->map.array)
		error_throw(ERROR_MALLOC);
	i = -1;
	while (++i < data->map.depth)
	{
		data->map.array[i] = (int *) calloc(data->map.width, sizeof(int));
		if (!data->map.array[i])
		{
			exit_array_2d_int(&data->map.array, i);
			error_throw(ERROR_MALLOC);
		}
	}
}

void	init_map_points_rows(t_data *data)
{
	int	i;

	data->map.points = (t_point **) malloc(sizeof(t_point *) * data->map.depth);
	if (!data->map.points)
		error_throw(ERROR_MALLOC);
	i = -1;
	while (++i < data->map.depth)
	{
		data->map.points[i] = (t_point *) calloc(data->map.width,
				sizeof(t_point));
		if (!data->map.points[i])
		{
			exit_array_2d_point(&data->map.points, i);
			error_throw(ERROR_MALLOC);
		}
	}
}

void	init_map_array(t_data *data)
{
	init_map_array_rows(data);
	init_map_points_rows(data);
}

void	init_map_read(t_data *data, const char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_throw(ERROR_FILE_INVALID);
	line = get_next_line(fd);
	if (!line)
	{
		exit_data(data);
		error_throw(ERROR_FILE_EMPTY);
		return ;
	}
	while (line != NULL)
	{
		if (line[0] != '\n')
			init_map_read_line(data, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
