/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_keypress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:27:11 by ibour             #+#    #+#             */
/*   Updated: 2024/11/13 14:02:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_event_keypress(const int keycode, t_gamedata *gamedata)
{
	if (keycode == XK_Escape)
		ft_event_close(gamedata);
	else if (keycode == KEY_W && gamedata->window_page == WINDOW_SPLASH)
		ft_event_window(WINDOW_GAME, gamedata);
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		ft_event_move(gamedata, keycode);
	return (0);
}
