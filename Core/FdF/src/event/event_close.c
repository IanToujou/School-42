/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:27:03 by ibour             #+#    #+#             */
/*   Updated: 2025/09/10 17:52:22 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	event_close(t_data *data)
{
	exit_mlx(data);
	exit_data(data);
	gg_free_all(data->gg_data);
	exit(0);
}
