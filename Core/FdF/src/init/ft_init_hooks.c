/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 02:10:37 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 02:32:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	ft_init_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 0, ft_event_key_press, data);
	mlx_hook(data->win, 17, 0, ft_event_close, data);
	mlx_hook(data->win, 4, 0, ft_event_mouse_press, data);
	mlx_hook(data->win, 5, 0, ft_event_mouse_release, data);
	mlx_hook(data->win, 6, 0, ft_event_mouse_move, data);
}
