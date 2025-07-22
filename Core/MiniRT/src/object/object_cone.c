/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:51:30 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 10:57:57 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec3	calculate_radial_direction(t_vec3 hit_point, t_cone *cone)
{
	t_vec3	axis;
	t_vec3	hit_to_base;
	double	proj_length;
	t_vec3	axis_point;

	axis = vec_normalize(cone->axis);
	hit_to_base = vec_sub(hit_point, cone->point);
	proj_length = vec_dot(hit_to_base, axis);
	axis_point = vec_add(cone->point, vec_mul(axis, proj_length));
	return (vec_sub(hit_point, axis_point));
}

void	update_cone_surface_hit(t_hit_info *hit, t_ray *ray, t_cone *cone)
{
	t_vec3	axis;
	t_vec3	radial_direction;
	double	slope;

	axis = vec_normalize(cone->axis);
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, hit->t));
	radial_direction = calculate_radial_direction(hit->point, cone);
	if (vec_length(radial_direction) > 1e-6)
		radial_direction = vec_normalize(radial_direction);
	else
		radial_direction = (t_vec3){1, 0, 0};
	slope = cone->radius / cone->height;
	hit->normal = vec_add(radial_direction, vec_mul(axis, slope));
	hit->normal = vec_normalize(hit->normal);
}

void	update_cone_cap_hit(t_hit_info *hit, t_ray *ray, t_cone *cone)
{
	t_vec3	axis;

	axis = vec_normalize(cone->axis);
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, hit->t));
	hit->normal = vec_mul(axis, -1);
}

int	find_closest_cone_hit(double *t_vals, t_hit_info *hit)
{
	double	t_min;
	int		hit_type;

	t_min = INFINITY;
	hit_type = -1;
	if (t_vals[0] > 0.001 && t_vals[0] < t_min)
	{
		t_min = t_vals[0];
		hit_type = 0;
	}
	if (t_vals[1] > 0.001 && t_vals[1] < t_min)
	{
		t_min = t_vals[1];
		hit_type = 1;
	}
	hit->t = t_min;
	return (hit_type);
}

int	object_cone_intersect(t_ray *ray, t_cone *cone, t_hit_info *hit)
{
	double	t_vals[2];
	int		hit_type;

	calculate_cone_intersections(ray, cone, t_vals);
	hit->t = INFINITY;
	hit->point = (t_vec3){0, 0, 0};
	hit->normal = (t_vec3){0, 0, 0};
	hit->color = cone->color;
	hit_type = find_closest_cone_hit(t_vals, hit);
	if (hit_type == -1)
		return (0);
	if (hit_type == 0)
		update_cone_surface_hit(hit, ray, cone);
	else if (hit_type == 1)
		update_cone_cap_hit(hit, ray, cone);
	return (1);
}
