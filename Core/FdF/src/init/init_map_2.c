/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:44:34 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 12:45:38 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	parse_color_value(t_data *data,
		char **color_split, int row, int col)
{
	data->map.array[row][col] = (int)util_num_parse(color_split[0]);
	if (ft_strncmp(color_split[1], "0x", 2) == 0
		|| ft_strncmp(color_split[1], "0X", 2) == 0)
		data->map.points[row][col].color
			= util_atoi_base(color_split[1] + 2, "0123456789ABCDEF");
	else
		data->map.points[row][col].color
			= util_atoi_base(color_split[1], "0123456789ABCDEF");
}

static void	parse_array_element(t_data *data, char *element, int row, int col)
{
	char	**color_split;

	if (ft_strchr(element, ','))
	{
		color_split = ft_split(element, ',');
		if (!color_split || !color_split[0] || !color_split[1])
		{
			if (color_split)
				util_array_free((void **) color_split);
			error_throw(ERROR_INIT_PARSE);
		}
		parse_color_value(data, color_split, row, col);
		util_array_free((void **) color_split);
	}
	else
	{
		data->map.array[row][col] = (int)util_num_parse(element);
		data->map.points[row][col].color = 0xFFFFFF;
	}
}

static void	set_point_coordinates(t_data *data, int row, int col)
{
	data->map.points[row][col].x = col;
	data->map.points[row][col].y = row;
	data->map.points[row][col].z = data->map.array[row][col];
}

void	process_line_elements(t_data *data, char **array, int row)
{
	int	i;

	i = 0;
	while (array[i] && i < data->map.width)
	{
		parse_array_element(data, array[i], row, i);
		set_point_coordinates(data, row, i);
		i++;
	}
}
