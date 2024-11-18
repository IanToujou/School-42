/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:14:41 by ibour             #+#    #+#             */
/*   Updated: 2024/11/18 10:10:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_exit_animations(t_gamedata *gamedata)
{
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_0);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_1);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_2);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_3);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_4);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_5);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_6);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_7);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_8);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_9);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_10);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_11);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_12);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_13);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_14);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_15);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_16);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_17);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_18);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_19);
	mlx_destroy_image(gamedata->mlx, gamedata->image_death->frame_20);
}

static void	ft_init_animations(t_gamedata *gamedata)
{
	gamedata->image_death->frame_0 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F0, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_1 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F1, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_2 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F2, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_3 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F3, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_4 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F4, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_5 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F5, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_6 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F6, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_7 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F7, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_8 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F8, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_9 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F9, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_10 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F10, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_11 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F11, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_12 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F12, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_13 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F13, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_14 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F14, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_15 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F15, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_16 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F16, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_17 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F17, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_18 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F18, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_19 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F19, &gamedata->window_width, &gamedata->window_height);
	gamedata->image_death->frame_20 = mlx_xpm_file_to_image(gamedata->mlx, XPM_DEATH_F20, &gamedata->window_width, &gamedata->window_height);
}

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
	ft_init_animations(gamedata);
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
	ft_exit_animations(gamedata);
	return (0);
}