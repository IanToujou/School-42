/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:14:27 by mpoesy            #+#    #+#             */
/*   Updated: 2025/07/07 18:17:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	update_body_hit(t_hit_info *hit, t_ray *ray, t_cylinder *cy)
{
	t_vec3	normalized_axis;
	t_vec3	hit_to_axis;
	t_vec3	projected;

	normalized_axis = vec_normalize(cy->axis);
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, hit->t));
	hit_to_axis = vec_sub(hit->point, cy->point);
	projected = project_vector(hit_to_axis, normalized_axis);
	hit->normal = vec_normalize(vec_sub(hit_to_axis, projected));
}

static void	update_cap_hit(t_hit_info *hit, t_ray *ray, int is_top)
{
	t_vec3	normalized_axis;

	hit->point = vec_add(ray->origin, vec_mul(ray->direction, hit->t));
	normalized_axis = vec_normalize(((t_cylinder *)hit)->axis);
	if (is_top)
		hit->normal = normalized_axis;
	else
		hit->normal = vec_mul(normalized_axis, -1);
}

static int	find_closest_hit(double *t_vals, t_hit_info *hit)
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
	if (t_vals[2] > 0.001 && t_vals[2] < t_min)
	{
		t_min = t_vals[2];
		hit_type = 2;
	}
	hit->t = t_min;
	return (hit_type);
}

int	object_cylinder_intersect(t_ray *ray, t_cylinder *cy, t_hit_info *hit)
{
	double	t_vals[3];
	int		hit_type;

	calculate_intersections(ray, cy, t_vals);
	init_hit_info(hit, cy);
	hit_type = find_closest_hit(t_vals, hit);
	if (hit_type == -1)
		return (0);
	if (hit_type == 0)
		update_body_hit(hit, ray, cy);
	else if (hit_type == 1)
		update_cap_hit(hit, ray, 1);
	else if (hit_type == 2)
		update_cap_hit(hit, ray, 0);
	return (1);
}
