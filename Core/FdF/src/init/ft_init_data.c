/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:35:49 by ibour             #+#    #+#             */
/*   Updated: 2024/12/18 13:23:24 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	ft_init_default(t_data *data)
{
	data->window_height = WINDOW_SIZE;
	data->window_width = WINDOW_SIZE;
}

int	ft_init_data(t_data **data) {
	t_map	*map;

	*data = (t_data *) malloc(sizeof(t_data));
	if (!*data)
		return (-1);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (-1);
	(*data)->map = map;
	ft_init_default(*data);
	return (0);
}
