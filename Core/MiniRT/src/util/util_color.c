/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:19:26 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 09:41:23 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	free_split_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static int	count_color_values(char **values)
{
	int	i;

	i = 0;
	while (values[i])
		i++;
	return (i);
}

static void	validate_color_range(t_scene *scene, char **array, t_color color, char **values, char *line)
{
	if (color.r < 0 || color.r > 255
		|| color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
	{
		free_split_array(values);
		util_array_free((void **) array);
		free(line);
		exit_data_pre_render(scene);
		error_throw(ERROR_PARSE_COLOR);
	}
}

static t_color	parse_rgb_values(t_scene *scene, char **array, char **values, char *line)
{
	t_color	result;

	result.r = ft_atoi(values[0]);
	result.g = ft_atoi(values[1]);
	result.b = ft_atoi(values[2]);
	validate_color_range(scene, array, result, values, line);
	return (result);
}

t_color	util_color_parse(t_scene *scene, char **array, char *str, char *line)
{
	t_color	result;
	char	**values;
	int		count;
	int		i;

	if (!str)
	{
		util_array_free((void **) array);
		exit_data_pre_render(scene);
		free(line);
		error_throw(ERROR_PARSE_COLOR);
	}
	values = ft_split(str, ',');
	if (!values)
		error_throw(ERROR_MALLOC);
	count = count_color_values(values);
	if (count != 3)
	{
		util_array_free((void **) array);
		exit_data_pre_render(scene);
		free_split_array(values);
		free(line);
		error_throw(ERROR_PARSE_COLOR);
	}
	result = parse_rgb_values(scene, array, values, line);
	i = 0;
	while (values[i])
		free(values[i++]);
	free(values);
	return (result);
}
