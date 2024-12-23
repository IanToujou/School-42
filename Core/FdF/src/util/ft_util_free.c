/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:24:49 by ibour             #+#    #+#             */
/*   Updated: 2024/12/23 11:24:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_util_free_array(void **array, const size_t length)
{
	size_t	i;

	i = 0;
	while (i < length && array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_util_free_map(t_map *map)
{
	if (!map) // todo bug here somewhere
		return ;
	if (map->grid2d)
		ft_util_free_array((void **)map->grid2d, map->rows);
	if (map->grid3d)
		ft_util_free_array((void **)map->grid3d, map->rows);
	free(map);
}

void	ft_util_free(t_data *data)
{
	if (!data)
		return ;
	ft_util_free_map(data->map);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}
