/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:13:18 by ibour             #+#    #+#             */
/*   Updated: 2025/07/07 18:14:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	check_height_bounds(t_ray *ray, t_cylinder *cy, double t)
{
	t_vec3	hit;
	t_vec3	ca;
	double	proj;

	hit = vec_add(ray->origin, vec_mul(ray->direction, t));
	ca = vec_normalize(cy->axis);
	proj = project_length(vec_sub(hit, cy->point), ca);
	if (proj < 0 || proj > cy->height)
		return (0);
	return (1);
}

int	solve_infinite_cylinder(t_ray *ray, t_cylinder *cy, double *t)
{
	t_vec3	perp_vals[2];
	double	discriminant;
	double	t_hit;

	calc_perp_comp(ray, cy, perp_vals);
	discriminant = calc_disc(perp_vals, cy);
	if (discriminant < 0)
		return (0);
	t_hit = get_valid_cylinder_t(discriminant, perp_vals);
	if (t_hit < 0)
		return (0);
	if (!check_height_bounds(ray, cy, t_hit))
		return (0);
	*t = t_hit;
	return (1);
}

int	solve_cap(t_ray *ray, t_cylinder *cy, t_vec3 cap_center, double *t)
{
	double	denom;
	double	t_hit;
	t_vec3	p;
	t_vec3	normalized_axis;

	normalized_axis = vec_normalize(cy->axis);
	denom = vec_dot(ray->direction, normalized_axis);
	if (fabs(denom) < 1e-6)
		return (0);
	t_hit = vec_dot(vec_sub(cap_center, ray->origin), normalized_axis) / denom;
	if (t_hit < 0.001)
		return (0);
	p = vec_add(ray->origin, vec_mul(ray->direction, t_hit));
	if (vec_length(vec_sub(p, cap_center)) > cy->radius)
		return (0);
	*t = t_hit;
	return (1);
}

void	calculate_intersections(t_ray *ray, t_cylinder *cy, double *t_vals)
{
	t_vec3	normalized_axis;

	normalized_axis = vec_normalize(cy->axis);
	if (!solve_infinite_cylinder(ray, cy, &t_vals[0]))
		t_vals[0] = -1;
	if (!solve_cap(ray, cy, vec_add(cy->point,
				vec_mul(normalized_axis, cy->height)), &t_vals[1]))
		t_vals[1] = -1;
	if (!solve_cap(ray, cy, cy->point, &t_vals[2]))
		t_vals[2] = -1;
}

void	init_hit_info(t_hit_info *hit, t_cylinder *cy)
{
	hit->t = INFINITY;
	hit->point = (t_vec3){0, 0, 0};
	hit->normal = (t_vec3){0, 0, 0};
	hit->color = cy->color;
}
