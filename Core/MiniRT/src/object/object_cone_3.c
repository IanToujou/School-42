/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cone_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:57:36 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 11:00:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	check_cone_height_bounds(t_ray *ray, t_cone *cone, double t)
{
	t_vec3	hit_point;
	t_vec3	axis;
	t_vec3	apex;
	double	proj_length;

	hit_point = vec_add(ray->origin, vec_mul(ray->direction, t));
	axis = vec_normalize(cone->axis);
	apex = vec_add(cone->point, vec_mul(axis, cone->height));
	proj_length = vec_dot(vec_sub(hit_point, apex), vec_mul(axis, -1));
	return (proj_length >= 0 && proj_length <= cone->height);
}

int	check_cap_bounds(t_ray *ray, t_cone *cone, double t_hit, double *t)
{
	t_vec3	hit_point;
	double	distance_from_center;

	hit_point = vec_add(ray->origin, vec_mul(ray->direction, t_hit));
	distance_from_center = vec_length(vec_sub(hit_point, cone->point));
	if (distance_from_center > cone->radius)
		return (0);
	*t = t_hit;
	return (1);
}

int	solve_cone_cap(t_ray *ray, t_cone *cone, double *t)
{
	t_vec3	axis;
	t_vec3	cap_center;
	double	denom;
	double	t_hit;

	axis = vec_normalize(cone->axis);
	cap_center = cone->point;
	denom = vec_dot(ray->direction, axis);
	if (fabs(denom) < 1e-6)
		return (0);
	t_hit = vec_dot(vec_sub(cap_center, ray->origin), axis) / denom;
	if (t_hit < 0.001)
		return (0);
	return (check_cap_bounds(ray, cone, t_hit, t));
}

void	calculate_cone_intersections(t_ray *ray, t_cone *cone, double *t_vals)
{
	double	t_surface;
	double	t_cap;

	t_vals[0] = -1;
	t_vals[1] = -1;
	if (solve_cone_surface(ray, cone, &t_surface)
		&& check_cone_height_bounds(ray, cone, t_surface))
		t_vals[0] = t_surface;
	if (solve_cone_cap(ray, cone, &t_cap))
		t_vals[1] = t_cap;
}
