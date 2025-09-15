/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:52:24 by ibour             #+#    #+#             */
/*   Updated: 2025/09/15 18:20:19 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	init_map_read_line(t_data *data, const char *line)
{
	char	**array;
	char	**color_split;
	int		i;
	static int	current_row = 0;

	if (line[0] == 0 || line[0] == '\n')
		error_throw(ERROR_INIT_PARSE);
	array = ft_split(line, ' ');
	if (!array)
		error_throw(ERROR_MALLOC);
	i = 0;
	while (array[i] && i < data->map.width)
	{
		if (ft_strchr(array[i], ','))
		{
			color_split = ft_split(array[i], ',');
			if (!color_split || !color_split[0] || !color_split[1])
			{
				util_array_free((void **) array);
				if (color_split)
					util_array_free((void **) color_split);
				error_throw(ERROR_INIT_PARSE);
			}
			data->map.array[current_row][i] = (int)util_num_parse(color_split[0]);
			if (ft_strncmp(color_split[1], "0x", 2) == 0 ||
				ft_strncmp(color_split[1], "0X", 2) == 0)
				data->map.points[current_row][i].color = util_atoi_base(color_split[1] + 2, "0123456789ABCDEF");
			else
				data->map.points[current_row][i].color = util_atoi_base(color_split[1], "0123456789ABCDEF");
			util_array_free((void **) color_split);
		}
		else
		{
			data->map.array[current_row][i] = (int)util_num_parse(array[i]);
			data->map.points[current_row][i].color = 0xFFFFFF;
		}
		data->map.points[current_row][i].x = i;
		data->map.points[current_row][i].y = current_row;
		data->map.points[current_row][i].z = data->map.array[current_row][i];
		i++;
	}

	current_row++;
	util_array_free((void **) array);
}

void	init_map_array(t_data *data)
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
	data->map.points = (t_point **) malloc(sizeof(t_point *) * data->map.depth);
	if (!data->map.points)
		error_throw(ERROR_MALLOC);
	i = -1;
	while (++i < data->map.depth)
	{
		data->map.points[i] = (t_point *) calloc(data->map.width, sizeof(t_point));
		if (!data->map.points[i])
		{
			exit_array_2d_point(&data->map.points, i);
			error_throw(ERROR_MALLOC);
		}
	}
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
