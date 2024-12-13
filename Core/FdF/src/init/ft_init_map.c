/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:31:44 by ibour             #+#    #+#             */
/*   Updated: 2024/12/13 12:41:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	ft_default_values(t_map *map)
{
	map->array = NULL;
}

int	ft_init_map(t_data *data, char *arg)
{
	int	fd;
	t_map	*map;

	fd = open(arg, O_RDONLY, 0777);
	if (fd == -1)
		ft_throw_error(ERROR_FILE);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		ft_throw_error(ERROR_MALLOC);
	}
	ft_default_values(map);
	// dimension parse
	close(fd);
	// malloc grid
	data->map = map;
	return (0);
}