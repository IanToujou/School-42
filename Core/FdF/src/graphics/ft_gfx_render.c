/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:13:30 by ibour             #+#    #+#             */
/*   Updated: 2024/12/12 14:43:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	ft_gfx_render(t_data *data)
{
	(void)data; // todo do function
	if (data->window == NULL || data->mlx == NULL)
		return (-1);
	return (0);
}
