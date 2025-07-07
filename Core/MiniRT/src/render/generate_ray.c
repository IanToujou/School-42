/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:34:24 by mpoesy            #+#    #+#             */
/*   Updated: 2025/07/07 18:24:49 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	calculate_pixel_coordinates(int x, int y,
		t_camera *camera, double *coords)
{
	double	aspect_ratio;
	double	fov_rad;

	aspect_ratio = (double) WIDTH / (double) HEIGHT;
	fov_rad = tan((camera->fov * M_PI) / 360.0);
	coords[0] = (2 * ((x + 0.5) / WIDTH) - 1) * aspect_ratio * fov_rad;
	coords[1] = (1 - 2 * ((y + 0.5) / HEIGHT)) * fov_rad;
}

static t_vec3	calculate_ray_direction(t_camera *camera, double *coords)
{
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	direction;

	horizontal = vec_mul(camera->right, coords[0]);
	vertical = vec_mul(camera->up, coords[1]);
	direction = vec_add(camera->forward, vec_add(horizontal, vertical));
	return (vec_normalize(direction));
}

t_ray	generate_ray(int x, int y, t_camera *camera)
{
	t_ray	ray;
	double	coords[2];

	calculate_pixel_coordinates(x, y, camera, coords);
	ray.origin = camera->position;
	ray.direction = calculate_ray_direction(camera, coords);
	return (ray);
}
