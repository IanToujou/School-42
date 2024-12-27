/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:41:32 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 01:46:04 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_camera	*ft_init_camera(t_data *data)
{
	t_camera	*camera;

	camera = (t_camera *) malloc(sizeof(t_camera));
	if (!camera)
		ft_throw_error(ERROR_INIT_CAMERA);
	camera->zoom = ft_min((WINDOW_WIDTH - MENU_WIDTH) / data->map->width / 2, WINDOW_HEIGHT / data->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
