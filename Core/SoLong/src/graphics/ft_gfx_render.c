/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:13:30 by ibour             #+#    #+#             */
/*   Updated: 2024/11/18 10:05:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_characters_to_image(t_gamedata *gamedata, int width, int x, int y)
{
	if (gamedata->map->map[y][x] == '3')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_drug,
			width, y * IMG_WIDTH);
	if (gamedata->map->map[y][x] == '2')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_enemy_1,
			width, y * IMG_WIDTH);
	if (gamedata->map->map[y][x] == '1')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_wall,
			width, y * IMG_WIDTH);
	if (gamedata->map->map[y][x] == '0')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_empty,
			width, y * IMG_WIDTH);
	if (gamedata->map->map[y][x] == 'E') {
		if(gamedata->player->collected >= gamedata->map->amount_collectibles)
			mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_exit_open,
			width, y * IMG_WIDTH);
		else
			mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_exit_closed,
			width, y * IMG_WIDTH);
	}
	if (gamedata->map->map[y][x] == 'P')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_player,
			width, y * IMG_WIDTH);
	if (gamedata->map->map[y][x] == 'C')
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_collectible,
			width, y * IMG_WIDTH);
	if(gamedata->str_collected_part)
		free(gamedata->str_collected_part);
	if(gamedata->str_collected)
		free(gamedata->str_collected);
	gamedata->str_collected_part = ft_itoa(gamedata->player->collected);
	gamedata->str_collected = ft_strjoin("METH: ", gamedata->str_collected_part);
	if(gamedata->str_moves)
		free(gamedata->str_moves);
	if(gamedata->str_moves_part)
		free(gamedata->str_moves_part);
	gamedata->str_moves_part = ft_itoa(gamedata->player->steps);
	gamedata->str_moves = ft_strjoin("MOVES: ", gamedata->str_moves_part);
	mlx_string_put(gamedata->mlx, gamedata->window, 16, 20, 0xffffff, gamedata->str_collected);
	mlx_string_put(gamedata->mlx, gamedata->window, 16, 34, 0xffffff, gamedata->str_moves);
	mlx_string_put(gamedata->mlx, gamedata->window, 16, 48, 0xffff00, gamedata->str_quest);
}

static void	ft_gfx_render_splash(t_gamedata *gamedata)
{
	mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_splash, 0, 0);
}

static void ft_gfx_render_death(t_gamedata *gamedata)
{
	int frame = 0;

	frame = gamedata->image_death->current / 400;
	if (frame == 0)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_0, 0, 0);
	if (frame == 1)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_1, 0, 0);
	if (frame == 2)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_2, 0, 0);
	if (frame == 3)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_3, 0, 0);
	if (frame == 4)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_4, 0, 0);
	if (frame == 5)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_5, 0, 0);
	if (frame == 6)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_6, 0, 0);
	if (frame == 7)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_7, 0, 0);
	if (frame == 8)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_8, 0, 0);
	if (frame == 9)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_9, 0, 0);
	if (frame == 10)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_10, 0, 0);
	if (frame == 11)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_11, 0, 0);
	if (frame == 12)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_12, 0, 0);
	if (frame == 13)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_13, 0, 0);
	if (frame == 14)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_14, 0, 0);
	if (frame == 15)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_15, 0, 0);
	if (frame == 16)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_16, 0, 0);
	if (frame == 17)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_17, 0, 0);
	if (frame == 18)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_18, 0, 0);
	if (frame == 19)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_19, 0, 0);
	if (frame == 20)
		mlx_put_image_to_window(gamedata->mlx, gamedata->window, gamedata->image_death->frame_20, 0, 0);
	gamedata->image_death->current++;
	if (frame > 20)
		gamedata->image_death->current = 0;
}

static void	ft_gfx_render_game(t_gamedata *gamedata)
{
	size_t	x;
	int		y;
	int		width;

	x = 0;
	y = 0;
	width = 0;
	while (gamedata->map->map[y])
	{
		while (gamedata->map->map[y][x] && gamedata->map->map[y][x] != '\n')
		{
			ft_characters_to_image(gamedata, width, x, y);
			width += IMG_WIDTH;
			x++;
		}
		width = 0;
		x = 0;
		y++;
	}
}

int	ft_gfx_render(t_gamedata *gamedata)
{
	if (gamedata->window == NULL || gamedata->mlx == NULL)
		return (-1);
	if (gamedata->window_page == WINDOW_SPLASH)
		ft_gfx_render_splash(gamedata);
	else if (gamedata->window_page == WINDOW_DEATH)
		ft_gfx_render_death(gamedata);
	else
		ft_gfx_render_game(gamedata);
	return (0);
}