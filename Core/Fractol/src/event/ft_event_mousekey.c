/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_mousekey.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 06:31:39 by ibour             #+#    #+#             */
/*   Updated: 2024/12/03 07:52:07 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	ft_event_mousekey(int key, const int x, const int y, t_engine *engine)
{
	t_fractal	*fr;

	fr = &engine->fractal;
	if (key == MOUSE_SCROLL_DOWN)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.3));
		fr->zoom *= 1.3;
		if (fr->iterations < MAX_ITERATIONS)
			++fr->iterations;
	}
	else if (key == MOUSE_SCROLL_UP)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.3));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.3));
		fr->zoom /= 1.3;
		if (fr->iterations > MIN_ITERATIONS)
			--fr->iterations;
	}
	ft_render_fractal(engine);
}
