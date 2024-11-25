/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:13:30 by ibour             #+#    #+#             */
/*   Updated: 2024/11/25 20:07:08 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_str_to_image(t_gamedata *gamedata)
{
	mlx_string_put(gamedata->mlx, gamedata->window, 16, 20,
		0xffffff, gamedata->str_collected);
	mlx_string_put(gamedata->mlx, gamedata->window, 16, 34,
		0xffffff, gamedata->str_moves);
	mlx_string_put(gamedata->mlx, gamedata->window, 16, 48,
		0xffff00, gamedata->str_quest);
}

static void	ft_characters_to_image_sub(t_gamedata *gd, int w, int x, int y)
{
	if (gd->map->map[y][x] == 'P')
		mlx_put_image_to_window(gd->mlx, gd->window,
			gd->image_player, w, y * IMG_WIDTH);
	if (gd->map->map[y][x] == 'C')
		mlx_put_image_to_window(gd->mlx, gd->window,
			gd->image_collectible, w, y * IMG_WIDTH);
	if (gd->str_collected_part)
		free(gd->str_collected_part);
	if (gd->str_collected)
		free(gd->str_collected);
	gd->str_collected_part = ft_itoa(gd->player->collected);
	gd->str_collected = ft_strjoin("METH: ",
			gd->str_collected_part);
	if (gd->str_moves)
		free(gd->str_moves);
	if (gd->str_moves_part)
		free(gd->str_moves_part);
	gd->str_moves_part = ft_itoa(gd->player->steps);
	gd->str_moves = ft_strjoin("MOVES: ", gd->str_moves_part);
}

static void	ft_characters_to_image(t_gamedata *gd, int w, int x, int y)
{
	if (gd->map->map[y][x] == '3')
		mlx_put_image_to_window(gd->mlx, gd->window,
			gd->image_drug, w, y * IMG_WIDTH);
	if (gd->map->map[y][x] == '2')
		mlx_put_image_to_window(gd->mlx, gd->window,
			gd->image_enemy_1, w, y * IMG_WIDTH);
	if (gd->map->map[y][x] == '1')
		mlx_put_image_to_window(gd->mlx, gd->window,
			gd->image_wall,
			w, y * IMG_WIDTH);
	if (gd->map->map[y][x] == '0')
		mlx_put_image_to_window(gd->mlx, gd->window,
			gd->image_empty, w, y * IMG_WIDTH);
	if (gd->map->map[y][x] == 'E')
	{
		if (gd->player->collected >= gd->map->amount_collectibles)
			mlx_put_image_to_window(gd->mlx, gd->window,
				gd->image_exit_open, w, y * IMG_WIDTH);
		else
			mlx_put_image_to_window(gd->mlx, gd->window,
				gd->image_exit_closed, w, y * IMG_WIDTH);
	}
	ft_characters_to_image_sub(gd, w, x, y);
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
	ft_str_to_image(gamedata);
}

int	ft_gfx_render(t_gamedata *gamedata)
{
	if (gamedata->window == NULL || gamedata->mlx == NULL)
		return (-1);
	if (gamedata->window_page == WINDOW_SPLASH)
	{
		mlx_put_image_to_window(gamedata->mlx, gamedata->window,
			gamedata->image_splash, 0, 0);
	}
	else
		ft_gfx_render_game(gamedata);
	return (0);
}
