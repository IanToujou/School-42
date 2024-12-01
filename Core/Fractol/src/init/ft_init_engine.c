/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:16:21 by ibour             #+#    #+#             */
/*   Updated: 2024/12/01 14:25:05 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	ft_init_engine(t_engine *engine, char *fractal)
{
	int	pixel_bits;
	int	line_len;
	int	endian;

	if (!engine || !fractal)
		return ;
	ft_engine_reset(engine, MANDELBROT);
	ft_set_fractal(engine, fractal);
	engine->mlx = mlx_init();
	if (!engine->mlx)
		ft_throw_error(ERROR_INIT_MLX);
	engine->window = mlx_new_window(engine->mlx, WINDOW_SIZE, WINDOW_SIZE, \
												"Fractol");
	engine->image.mlx_image = mlx_new_image(engine->mlx, WINDOW_SIZE, WINDOW_SIZE);
	if (!engine->window || !engine->image.mlx_image)
	{
		mlx_destroy_image(engine->mlx, engine->image.mlx_image);
		mlx_destroy_window(engine->mlx, engine->window);
		ft_throw_error(ERROR_INIT_WINDOW);
	}
	engine->image.address = mlx_get_data_addr(engine->image.mlx_image, \
								&pixel_bits, &line_len, &endian);
	engine->image.pixel_bits = pixel_bits;
	engine->image.line_length = line_len;
	engine->image.endian = endian;
}
