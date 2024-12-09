/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_keypress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 06:30:33 by ibour             #+#    #+#             */
/*   Updated: 2024/12/09 09:20:54 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	ft_event_keypress(int key, t_engine *engine)
{
	if ((key >= KEY_Q && key <= KEY_Y) || (key >= KEY_A && key <= KEY_H))
		ft_set_color(key, engine);
	else if (key >= KEY_LEFT && key <= KEY_DOWN)
		ft_set_view(key, engine);
	else if (key >= KEY_ONE && key <= KEY_FIVE)
		ft_change_fractal(key, engine);
	else if (key == KEY_L && engine->fractal.type == JULIA)
		engine->fractal.julia_lock ^= 1;
	else if (key == KEY_ZERO)
		ft_engine_reset(engine, engine->fractal.type);
	else if (key == KEY_ESC)
		ft_event_close(engine);
	ft_render_fractal(engine);
	return (0);
}
