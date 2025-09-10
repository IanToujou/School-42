/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:26:56 by ibour             #+#    #+#             */
/*   Updated: 2025/09/10 17:52:46 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	event_keypress(const int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		event_close(data);
	return (0);
}
