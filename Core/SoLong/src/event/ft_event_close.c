/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:31:35 by ibour             #+#    #+#             */
/*   Updated: 2024/11/15 14:15:23 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_event_close(t_gamedata *gamedata)
{
	mlx_destroy_window(gamedata->mlx, gamedata->window);
	gamedata->window = NULL;
	return (0);
}