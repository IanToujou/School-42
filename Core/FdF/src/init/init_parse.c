/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:46:36 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 07:58:43 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

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
		data->map.points[i] = (t_point *) malloc(sizeof(t_point) * data->map.width);
		if (!data->map.points[i])
		{
			exit_array_2d_point(&data->map.points, i);
			error_throw(ERROR_MALLOC);
		}
	}
}

void	init_parse(t_data *data, const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_throw(ERROR_FILE_INVALID);
	data->map.depth = util_map_parse_depth(fd);
	data->map.width = util_map_parse_width(file);
	close(fd);
	if (data->map.depth <= 0 || data->map.width <= 0)
	{
		exit_data(data);
		error_throw(ERROR_FILE_INVALID);
	}
	init_map_array(data);
}
