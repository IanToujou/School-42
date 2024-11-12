/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:13:30 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 14:11:09 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_gfx_render(t_gamedata *gamedata)
{
	if (gamedata->window_page == WINDOW_SPLASH)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_splash, 0, 0);
	else {
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_player, 0, 0);
	}
	return (0);
}