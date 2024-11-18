/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:14:41 by ibour             #+#    #+#             */
/*   Updated: 2024/11/18 10:17:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_init_graphics(t_gamedata *gamedata)
{
	gamedata->image_splash = mlx_xpm_file_to_image(gamedata->mlx, XPM_SPLASH, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_player = mlx_xpm_file_to_image(gamedata->mlx, XPM_PLAYER, &gamedata->image_size, &gamedata->image_size);
	gamedata->image_empty = mlx_xpm_file_to_image(gamedata->mlx, XPM_EMPTY, &gamedata->image_size, &gamedata->image_size);
	gamedata->image_wall = mlx_xpm_file_to_image(gamedata->mlx, XPM_WALL, &gamedata->image_size, &gamedata->image_size);
	gamedata->image_exit_closed = mlx_xpm_file_to_image(gamedata->mlx, XPM_EXIT_CLOSED, &gamedata->image_size, &gamedata->image_size);
	gamedata->image_exit_open = mlx_xpm_file_to_image(gamedata->mlx, XPM_EXIT_OPEN, &gamedata->image_size, &gamedata->image_size);
	gamedata->image_enemy_1 = mlx_xpm_file_to_image(gamedata->mlx, XPM_ENEMY_1, &gamedata->image_size, &gamedata->image_size);
	gamedata->image_collectible = mlx_xpm_file_to_image(gamedata->mlx, XPM_COLLECTIBLE, &gamedata->image_size, &gamedata->image_size);
	gamedata->image_drug = mlx_xpm_file_to_image(gamedata->mlx, XPM_DRUG, &gamedata->image_size, &gamedata->image_size);
	return (0);
}

int	ft_exit_graphics(t_gamedata *gamedata)
{
	mlx_destroy_image(gamedata->mlx, gamedata->image_splash);
	mlx_destroy_image(gamedata->mlx, gamedata->image_player);
	mlx_destroy_image(gamedata->mlx, gamedata->image_empty);
	mlx_destroy_image(gamedata->mlx, gamedata->image_wall);
	mlx_destroy_image(gamedata->mlx, gamedata->image_exit_open);
	mlx_destroy_image(gamedata->mlx, gamedata->image_exit_closed);
	mlx_destroy_image(gamedata->mlx, gamedata->image_enemy_1);
	mlx_destroy_image(gamedata->mlx, gamedata->image_collectible);
	mlx_destroy_image(gamedata->mlx, gamedata->image_drug);
	return (0);
}