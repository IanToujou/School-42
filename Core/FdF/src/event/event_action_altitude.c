/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_action_altitude.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:28:57 by ibour             #+#    #+#             */
/*   Updated: 2025/09/17 19:57:49 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	event_action_altitude(const int key, double *alt_ratio)
{
	if (key == KEY_UP)
		*alt_ratio *= 1 + ALT_INCR;
	else if (key == KEY_DOWN)
		*alt_ratio *= 1 - ALT_INCR;
}

