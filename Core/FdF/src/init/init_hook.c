/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:48:05 by ibour             #+#    #+#             */
/*   Updated: 2025/07/17 09:48:36 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init_hook(t_data *data)
{
	mlx_hook(data->win_ptr, ClientMessage, LeaveWindowMask,
		event_close, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask,
		event_keypress, data);
	if (data->mlx_ptr)
		mlx_loop(data->mlx_ptr);
}