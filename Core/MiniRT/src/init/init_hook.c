/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:22:58 by ibour             #+#    #+#             */
/*   Updated: 2025/06/20 07:45:42 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	init_hook(t_scene *scene)
{
	mlx_hook(scene->win_ptr, ClientMessage, LeaveWindowMask,
		event_close, scene);
	mlx_hook(scene->win_ptr, KeyPress, KeyPressMask,
		event_keypress, scene);
	if (scene->mlx_ptr)
		mlx_loop(scene->mlx_ptr);
}
