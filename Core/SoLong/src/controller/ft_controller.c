/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:21:54 by ibour             #+#    #+#             */
/*   Updated: 2024/11/07 12:51:10 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_move_player(const t_data *data, const char position, const int direction)
{
	if (position == 'y' && direction == UP)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image->player_up,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (position == 'x' && direction == LEFT)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image->player_left,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (position == 'y' && direction == DOWN)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image->player_down,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
	if (position == 'x' && direction == RIGHT)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->image->player_right,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	}
}

static void	ft_collect_player(t_data *data, const char position, const int direction)
{
	data->collected++;
	data->map->map[data->p_y][data->p_x] = '0';
	mlx_put_image_to_window(data->mlx, data->window, data->image->background,
		(data->p_x * IMG_W), (data->p_y * IMG_H));
	ft_move_player(data, position, direction);
}

void	ft_controller_move(t_data *data, const char position, const int direction)
{
	mlx_put_image_to_window(data->mlx, data->window, data->image->background,
			(data->p_x * IMG_W), (data->p_y * IMG_H));
	if (position == 'y' && data->map->map[data->p_y + 1 * direction][data->p_x] != '1'
		&& (data->map->map[data->p_y + 1 * direction][data->p_x] != 'E'
		|| data->collected == data->map->collectibles))
		data->p_y = data->p_y + 1 * direction;
	else if (position == 'x' && data->map->map[data->p_y][data->p_x + 1 * direction] != '1'
		&& (data->map->map[data->p_y][data->p_x + 1 * direction] != 'E'
		|| data->collected == data->map->collectibles))
		data->p_x = data->p_x + 1 * direction;
	else if (position == 'y' && data->map->map[data->p_y + 1 * direction][data->p_x] == 'E'
		&& data->collected != data->map->collectibles)
		printf("Collect all blue math packs before leaving\n");
	else if (position == 'x' && data->map->map[data->p_y][data->p_x + 1 * direction] == 'E'
		&& data->collected != data->map->collectibles)
		printf("Collect all blue math packs before leaving\n");
	ft_move_player(data, position, direction);
	if (data->map->map[data->p_y][data->p_x] == 'C')
		ft_collect_player(data, position, direction);
	mlx_do_sync(data->mlx);
	ft_printf("You moved %d times.\n", ++data->counter);
}
