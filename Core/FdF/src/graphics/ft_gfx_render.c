/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:13:30 by ibour             #+#    #+#             */
/*   Updated: 2024/12/18 13:16:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	ft_gfx_render(t_data *data)
{
	if (data->window == NULL || data->mlx == NULL)
		return (-1);
	ft_util_draw_image(data);
	return (0);
}
