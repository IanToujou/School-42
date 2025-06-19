/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:19:26 by ibour             #+#    #+#             */
/*   Updated: 2025/06/19 14:24:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void free_split_array(char **array)
{
	int i;

	if (!array)
		return;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

t_color	util_color_parse(char *str)
{
	t_color	result;
	char	**values;
	int		i;

	if (!str)
		error_throw(ERROR_PARSE_COLOR);
	values = ft_split(str, ',');
	if (!values)
		error_throw(ERROR_MALLOC);
	i = 0;
	while (values[i])
		i++;
	if (i != 3)
	{
		free_split_array(values);
		error_throw(ERROR_PARSE_COLOR);
	}
	result.r = ft_atoi(values[0]);
	result.g = ft_atoi(values[1]);
	result.b = ft_atoi(values[2]);
	if (result.r < 0 || result.r > 255 ||
		result.g < 0 || result.g > 255 ||
		result.b < 0 || result.b > 255)
	{
		free_split_array(values);
		error_throw(ERROR_PARSE_COLOR);
	}
	i = 0;
	while (values[i])
		free(values[i++]);
	free(values);
	return (result);
}
