/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:19:26 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 11:17:45 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	util_color_rgb_check(char **values)
{
	t_color	result;

	result.r = ft_atoi(values[0]);
	result.g = ft_atoi(values[1]);
	result.b = ft_atoi(values[2]);
	return (util_color_range_check(result));
}

t_color	util_color_rgb(char **values)
{
	t_color	result;

	result.r = ft_atoi(values[0]);
	result.g = ft_atoi(values[1]);
	result.b = ft_atoi(values[2]);
	util_color_range(result, values);
	return (result);
}

int	util_color_check(char *str)
{
	char	**values;
	int		count;
	int		i;

	if (!str)
		return (0);
	values = ft_split(str, ',');
	count = util_color_count(values);
	if (count != 3 || util_color_rgb_check(values) == 0)
	{
		util_color_free_array(values);
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
	count = util_color_count(values);
	if (count != 3)
	{
		util_color_free_array(values);
		error_throw(ERROR_PARSE_COLOR);
	}
	result = util_color_rgb(values);
	i = 0;
	while (values[i])
		free(values[i++]);
	free(values);
	return (result);
}
