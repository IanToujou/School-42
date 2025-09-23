/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:13:27 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 10:43:47 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int	util_image(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img_ptr)
		return (0);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img_ptr,
			&(data->image.bpp),
			&(data->image.size_line), &(data->image.endian));
	if (!data->addr)
		return (0);
	return (1);
}
