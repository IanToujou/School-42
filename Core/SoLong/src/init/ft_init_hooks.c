/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:12:14 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 09:38:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_init_hooks(const t_gamedata *gamedata)
{
	mlx_hook(gamedata->window, KeyPress, KeyPressMask, ft_event_keypress, &gamedata);
	return (0);
}