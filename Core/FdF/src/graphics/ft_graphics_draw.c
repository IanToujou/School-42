/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:40:51 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 02:29:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static void	ft_graphic_draw_pixel(t_data *data, int x, int y, int color)
{
	int		i;

	if (x >= MENU_WIDTH && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		i = (x * data->bits_per_pixel / 8) + (y * data->size_line);
		data->data_addr[i] = color;
		data->data_addr[++i] = color >> 8;
		data->data_addr[++i] = color >> 16;
	}
}

static void	ft_graphics_draw_line(t_point f, t_point s, t_data *data)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		ft_graphic_draw_pixel(data, cur.x, cur.y, get_color(cur, f, s, delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

static void	ft_graphics_draw_background(t_data *data)
{
	int	*image;
	int	i;

	ft_bzero(data->data_addr, WINDOW_WIDTH * WINDOW_HEIGHT * (data->bits_per_pixel / 8));
	image = (int *)(data->data_addr);
	i = 0;
	while (i < WINDOW_HEIGHT * WINDOW_WIDTH)
	{
		image[i] = (i % WINDOW_WIDTH < MENU_WIDTH) ? MENU_BACKGROUND_COLOR : BACKGROUND_COLOR;
		i++;
	}
}

void	ft_graphics_draw(t_map *map, t_data *data)
{
	int		x;
	int		y;

	ft_graphics_draw_background(data);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != data->map->width - 1)
				ft_graphics_draw_line(project(new_point(x, y, map), data),
					project(new_point(x + 1, y, map), data), data);
			if (y != data->map->height - 1)
				ft_graphics_draw_line(project(new_point(x, y, map), data),
					project(new_point(x, y + 1, map), data), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	print_menu(data);
}
