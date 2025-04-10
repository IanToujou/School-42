/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:14:41 by ibour             #+#    #+#             */
/*   Updated: 2024/11/26 09:03:09 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	*ft_load_xpm(t_gamedata *gamedata, char *filename)
{
	return (mlx_xpm_file_to_image(gamedata->mlx, filename,
			&gamedata->window_width, &gamedata->window_height));
}

void	ft_init_graphics(t_gamedata *gamedata)
{
	gamedata->image_splash = ft_load_xpm(gamedata, XPM_SPLASH);
	gamedata->image_player = ft_load_xpm(gamedata, XPM_PLAYER);
	gamedata->image_empty = ft_load_xpm(gamedata, XPM_EMPTY);
	gamedata->image_wall = ft_load_xpm(gamedata, XPM_WALL);
	gamedata->image_exit_closed = ft_load_xpm(gamedata, XPM_EXIT_CLOSED);
	gamedata->image_exit_open = ft_load_xpm(gamedata, XPM_EXIT_OPEN);
	gamedata->image_enemy = ft_load_xpm(gamedata, XPM_ENEMY);
	gamedata->image_collectible = ft_load_xpm(gamedata, XPM_COLLECTIBLE);
}

void	ft_exit_graphics(const t_gamedata *gamedata)
{
	mlx_destroy_image(gamedata->mlx, gamedata->image_splash);
	mlx_destroy_image(gamedata->mlx, gamedata->image_player);
	mlx_destroy_image(gamedata->mlx, gamedata->image_empty);
	mlx_destroy_image(gamedata->mlx, gamedata->image_wall);
	mlx_destroy_image(gamedata->mlx, gamedata->image_exit_open);
	mlx_destroy_image(gamedata->mlx, gamedata->image_exit_closed);
	mlx_destroy_image(gamedata->mlx, gamedata->image_enemy);
	mlx_destroy_image(gamedata->mlx, gamedata->image_collectible);
	mlx_destroy_display(gamedata->mlx);
}
