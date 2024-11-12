/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:14:41 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 13:59:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_init_graphics(t_gamedata *gamedata)
{
	gamedata->image_splash = mlx_xpm_file_to_image(gamedata->mlx, XPM_SPLASH, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_player = mlx_xpm_file_to_image(gamedata->mlx, XPM_PLAYER, &gamedata->image_size, &gamedata->image_size);
	return (0);
}