/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:29:54 by ibour             #+#    #+#             */
/*   Updated: 2025/06/20 07:30:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	util_camera_update_vec(t_camera *cam)
{
	cam->forward = vec_normalize(cam->direction);
	cam->right = vec_normalize(vec_cross(cam->forward, (t_vec3){0, 1, 0}));
	cam->up = vec_cross(cam->right, cam->forward);
}

void	util_camera_update_vec_dir(t_camera *cam)
{
	double yaw_rad;
	double pitch_rad;
	double len;

	yaw_rad = cam->yaw * M_PI / 180.0;
	pitch_rad = cam->pitch * M_PI / 180.0;
	cam->direction.x = cos(pitch_rad) * cos(yaw_rad);
	cam->direction.y = sin(pitch_rad);
	cam->direction.z = cos(pitch_rad) * sin(yaw_rad);
	len = sqrt(cam->direction.x * cam->direction.x + cam->direction.y
			   * cam->direction.y + cam->direction.z * cam->direction.z);
	cam->direction.x /= len;
	cam->direction.y /= len;
	cam->direction.z /= len;
}
