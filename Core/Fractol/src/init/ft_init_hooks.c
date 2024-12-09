/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 06:26:35 by ibour             #+#    #+#             */
/*   Updated: 2024/12/05 08:19:24 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	ft_init_hooks(t_engine *engine)
{
	mlx_hook(engine->window, ClientMessage, LeaveWindowMask,
		ft_event_close, engine);
	mlx_hook(engine->window, KeyPress, KeyPressMask,
		ft_event_keypress, engine);
	mlx_mouse_hook(engine->window, ft_event_mousekey, engine);
	mlx_hook(engine->window, 6, 1L << 6, ft_event_mousemove, engine);
	mlx_loop(engine->mlx);
}
