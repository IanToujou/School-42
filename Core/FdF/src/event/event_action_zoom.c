/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action_zoom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:28:08 by ibour             #+#    #+#             */
/*   Updated: 2025/09/17 19:45:19 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_action_zoom(const int key, double *scale)
{
	if (key == KEY_NUMPAD_PLUS || key == MOUSE_SCROLL_UP)
		*scale *= 1 + ZOOM_INCR;
	else if (key == KEY_NUMPAD_MINUS || key == MOUSE_SCROLL_DOWN)
		*scale *= 1 - ZOOM_INCR;
}
