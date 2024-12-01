/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 06:24:15 by ibour             #+#    #+#             */
/*   Updated: 2024/12/01 14:35:46 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	ft_set_color(const int key, t_engine *engine)
{
	if (key == KEY_Q)
		engine->fractal.color += 0x300000;
	else if (key == KEY_W)
		engine->fractal.color += 0x030000;
	else if (key == KEY_E)
		engine->fractal.color += 0x003000;
	else if (key == KEY_R)
		engine->fractal.color += 0x000300;
	else if (key == KEY_T)
		engine->fractal.color += 0x000030;
	else if (key == KEY_Y)
		engine->fractal.color += 0x000003;
	else if (key == KEY_A)
		engine->fractal.color -= 0x300000;
	else if (key == KEY_S)
		engine->fractal.color -= 0x030000;
	else if (key == KEY_D)
		engine->fractal.color -= 0x003000;
	else if (key == KEY_F)
		engine->fractal.color -= 0x000300;
	else if (key == KEY_G)
		engine->fractal.color -= 0x000030;
	else if (key == KEY_H)
		engine->fractal.color -= 0x000003;
}

void	ft_set_color_pixel(t_engine *engine, int x, int y, int color)
{
	int	line_length;
	int	pixel_bits;
	int	offset;

	if (x < 0 || x >= WINDOW_SIZE || y < 0 || y >= WINDOW_SIZE)
		return ;
	line_length = engine->image.line_length;
	pixel_bits = engine->image.pixel_bits;
	offset = (y * line_length) + ((pixel_bits / 8) * x);
	*(unsigned int *)(engine->image.address + offset) = color;
}

void	ft_set_view(const int key, t_engine *engine)
{
	t_fractal	*fractal;

	fractal = &engine->fractal;
	if (key == KEY_LEFT)
		fractal->offset_x -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->offset_x += VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_UP)
		fractal->offset_y -= VIEW_CHANGE_SIZE / fractal->zoom;
	else if (key == KEY_DOWN)
		fractal->offset_y += VIEW_CHANGE_SIZE / fractal->zoom;
}

void	ft_render_fractal(t_engine *engine)
{
	static t_complex	c;
	t_fractal			*fractal;
	int					iter;
	int					x;
	int					y;

	x = -1;
	fractal = &engine->fractal;
	mlx_clear_window(engine->mlx, engine->window);
	while (++x < WINDOW_SIZE)
	{
		y = -1;
		if (fractal->type != JULIA)
			c.r = (x / fractal->zoom) + fractal->offset_x;
		else if (!fractal->julia_lock)
			c.r = (fractal->mouse_x / fractal->zoom) + fractal->offset_x;
		while (++y < WINDOW_SIZE)
		{
			iter = ft_calculate_fractal(fractal, &c, x, y);
			ft_set_color_pixel(engine, x, y, (int)(iter * engine->fractal.color));
		}
	}
	mlx_put_image_to_window(engine->mlx, engine->window, \
							engine->image.mlx_image, 0, 0);
}
