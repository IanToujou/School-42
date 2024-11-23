/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:12:14 by ibour             #+#    #+#             */
/*   Updated: 2024/11/13 08:13:33 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_init_hooks(t_gamedata *gamedata)
{
	mlx_loop_hook(gamedata->mlx, ft_gfx_render, gamedata);
	mlx_hook(gamedata->window, ClientMessage, LeaveWindowMask,
		ft_event_close, gamedata);
	mlx_hook(gamedata->window, KeyPress, KeyPressMask,
		ft_event_keypress, gamedata);
	mlx_loop(gamedata->mlx);
	return (0);
}
