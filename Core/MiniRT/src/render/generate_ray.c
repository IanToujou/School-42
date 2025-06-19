/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:34:24 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/19 11:56:27 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray generate_ray(int x, int y, t_camera *camera)
{
	t_ray ray;
	double aspect_ratio;
	double px;
	double py;
	t_vec3 horizontal;
	t_vec3 vertical;
	t_vec3 direction;
	double fov_rad;

	aspect_ratio = (double) WIDTH / (double) HEIGHT;
	fov_rad = tan((camera->fov * M_PI) / 360.0);
	px = (2 * ((x + 0.5) / WIDTH) - 1) * aspect_ratio * fov_rad;
	py = (1 - 2 * ((y + 0.5) / HEIGHT)) * fov_rad;
	ray.origin = camera->origin;
	horizontal = vec_mul(camera->right, px);
	vertical = vec_mul(camera->up, py);
	direction = vec_add(camera->forward, vec_add(horizontal, vertical));
	ray.direction = vec_normalize(direction);
	return (ray);
}
