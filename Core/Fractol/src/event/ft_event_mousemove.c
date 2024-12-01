/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_mousemove.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 06:31:30 by ibour             #+#    #+#             */
/*   Updated: 2024/12/01 06:34:47 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	ft_event_mousemove(const int x, const int y, t_engine *engine)
{
	if (engine->fractal.type != JULIA || engine->fractal.julia_lock)
		return ;
	engine->fractal.mouse_x = x;
	engine->fractal.mouse_y = y;
	ft_render_fractal(engine);
}
