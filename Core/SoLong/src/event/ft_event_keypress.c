/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_keypress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:27:11 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 09:33:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_event_keypress(const int keycode, t_gamedata *gamedata)
{
	if (keycode == XK_Escape)
	{
		ft_event_close(gamedata);
	}
	else if (keycode == XK_W || keycode == XK_A || keycode == XK_S || keycode == XK_D)
	{
		ft_printf("hi");
	}
	return (0);
}