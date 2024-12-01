/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 06:26:35 by ibour             #+#    #+#             */
/*   Updated: 2024/12/01 06:34:59 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	ft_init_hooks(t_engine *engine)
{
	mlx_key_hook(engine->window, on_key_hook_event, &engine);
	mlx_mouse_hook(engine->window, ft_event_mousekey, &engine);
	mlx_hook(engine->window, 6, 1L << 6, on_mousemove_event, &engine);
	mlx_hook(engine->window, 17, 0, ft_event_close, &engine);
	mlx_loop(engine->mlx);
}