/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:32:28 by ibour             #+#    #+#             */
/*   Updated: 2024/12/12 14:47:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_init_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, ft_gfx_render, data);
	mlx_hook(data->window, ClientMessage, LeaveWindowMask,
		ft_event_close, data);
	mlx_hook(data->window, KeyPress, KeyPressMask,
		ft_event_keypress, data);
	mlx_loop(data->mlx);
}
