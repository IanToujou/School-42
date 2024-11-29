/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:16:21 by ibour             #+#    #+#             */
/*   Updated: 2024/11/29 10:31:22 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	ft_reset_data(t_engine *engine, int type)
{
	engine->fractal.type = type;
	engine->fractal.zoom = WINDOW_SIZE / 4;
	engine->fractal.mouse_x = 0;
	engine->fractal.mouse_y = 0;
	engine->fractal.offset_x = -2;
	engine->fractal.offset_y = -2;
	engine->fractal.julia_lock = false;
	engine->fractal.color = DEFAULT_COLOR;
	engine->fractal.iterations = MIN_ITERATIONS;
}

int	ft_init_data(t_engine **engine, char *fractal)
{
	if (!*engine || !fractal)
		return (-1);
	ft_reset_data(*engine, MANDELBROT);
	// set fractal type
}