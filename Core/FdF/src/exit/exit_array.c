/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 07:55:39 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 07:56:21 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	exit_array_2d_int(int ***array, const int length)
{
	int	i;

	if (*array)
	{
		i = -1;
		while (++i < length)
		{
			free((*array)[i]);
			(*array)[i] = NULL;
		}
	}
	free(*array);
	*array = NULL;
}

void	exit_array_2d_point(t_point ***array, const int length)
{
	int	i;

	if (*array)
	{
		i = -1;
		while (++i < length)
		{
			free((*array)[i]);
			(*array)[i] = NULL;
		}
	}
	free(*array);
	*array = NULL;
}
