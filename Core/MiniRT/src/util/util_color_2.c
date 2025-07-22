/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_color_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:49:02 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 11:15:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	util_color_free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

int	util_color_count(char **values)
{
	int	i;

	i = 0;
	while (values[i])
		i++;
	return (i);
}

void	util_color_range(t_color color, char **values)
{
	if (color.r < 0 || color.r > 255
		|| color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
	{
		util_color_free_array(values);
		error_throw(ERROR_PARSE_COLOR);
	}
}

int	util_color_range_check(t_color color)
{
	if (color.r < 0 || color.r > 255
		|| color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255)
	{
		return (0);
	}
	return (1);
}
