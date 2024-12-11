/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:35:49 by ibour             #+#    #+#             */
/*   Updated: 2024/12/11 17:39:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	ft_init_data(t_data **data) {
	t_map	*map;

	*data = (t_data *) malloc(sizeof(t_data));
	if (!*data)
		return (-1);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (-1);
	(*data)->map = map;
	return (0);
}
