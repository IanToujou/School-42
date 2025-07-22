/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:19:26 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 10:02:59 by ibour            ###   ########.fr       */
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

static void	validate_color_range(t_color color, char **values)
{
	if (color.r < 0 || color.r > 255
		|| color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
	{
		free_split_array(values);
		error_throw(ERROR_PARSE_COLOR);
	}
}

static t_color	parse_rgb_values(char **values)
{
	t_color	result;

	result.r = ft_atoi(values[0]);
	result.g = ft_atoi(values[1]);
	result.b = ft_atoi(values[2]);
	validate_color_range(result, values);
	return (result);
}

int	util_color_check(char *str)
{
	t_color	result;
	char	**values;
	int		count;
	int		i;

	if (!str)
		error_throw(ERROR_PARSE_COLOR);
	values = ft_split(str, ',');
	if (!values)
		error_throw(ERROR_MALLOC);
	count = count_color_values(values);
	if (count != 3)
	{
		free_split_array(values);
		return (0);
	}
	result = parse_rgb_values(values);
	if (result.r < 0 || result.r > 255
		|| result.g < 0 || result.g > 255
		|| result.b < 0 || result.b > 255)
	{
		free_split_array(values);
		return (0);
	}
	i = 0;
	while (values[i])
		free(values[i++]);
	free(values);
	return (1);
}

t_color	util_color_parse(char *str)
{
	t_color	result;
	char	**values;
	int		count;
	int		i;

	if (!str)
		error_throw(ERROR_PARSE_COLOR);
	values = ft_split(str, ',');
	if (!values)
		error_throw(ERROR_MALLOC);
	count = count_color_values(values);
	if (count != 3)
	{
		free_split_array(values);
		error_throw(ERROR_PARSE_COLOR);
	}
	result = parse_rgb_values(values);
	i = 0;
	while (values[i])
		free(values[i++]);
	free(values);
	return (result);
}
