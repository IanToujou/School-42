/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:54:05 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 12:04:55 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_init_data(t_gamedata **gamedata)
{
	t_map		*map;
	t_player	*player;

	*gamedata = (t_gamedata *) malloc(sizeof(t_gamedata));
	if (!*gamedata)
		return (-1);
	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (-1);
	player = (t_player *) malloc(sizeof(t_player));
	if (!player)
		return (-1);
	(*gamedata)->map = map;
	(*gamedata)->player = player;
	return (0);
}