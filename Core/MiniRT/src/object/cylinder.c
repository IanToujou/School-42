/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:14:27 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/20 13:49:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double project_length(t_vec3 v, t_vec3 axis)
{
	return (vec_dot(v, axis));
}

t_vec3 project_vector(t_vec3 v, t_vec3 axis)
{
	return (vec_mul(axis, vec_dot(v, axis)));
}

int solve_infinite_cylinder(t_ray *ray, t_cylinder *cy, double *t)
{
	t_vec3 d_proj;
	t_vec3 oc_proj;
	t_vec3 d_perp;
	t_vec3 oc_perp;
	double sqrt_disc;
	double t0;
	double t1;
	t_vec3 hit;
	double proj;
	t_vec3 d, oc, ca;
	double a, b, c, discriminant;

	ca = vec_normalize(cy->axis);
	d = ray->direction;
	oc = vec_sub(ray->origin, cy->point);
	d_proj = project_vector(d, ca);
	oc_proj = project_vector(oc, ca);
	d_perp = vec_sub(d, d_proj);
	oc_perp = vec_sub(oc, oc_proj);
	a = vec_dot(d_perp, d_perp);

	// Handle degenerate case where ray is parallel to cylinder axis
	if (fabs(a) < 1e-9)
		return (0);

	b = 2 * vec_dot(d_perp, oc_perp);
	c = vec_dot(oc_perp, oc_perp) - cy->radius * cy->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	sqrt_disc = sqrt(discriminant);
	t0 = (-b - sqrt_disc) / (2 * a);
	t1 = (-b + sqrt_disc) / (2 * a);

	// Choose the closest positive intersection
	if (t0 > 0.001 && t1 > 0.001)
		*t = fmin(t0, t1);
	else if (t0 > 0.001)
		*t = t0;
	else if (t1 > 0.001)
		*t = t1;
	else
		return (0);

	hit = vec_add(ray->origin, vec_mul(d, *t));
	proj = project_length(vec_sub(hit, cy->point), ca);
	if (proj < 0 || proj > cy->height)
		return (0);
	return (1);
}

int solve_cap(t_ray *ray, t_cylinder *cy, t_vec3 cap_center, double *t)
{
	double denom;
	double t_hit;
	t_vec3 p;
	t_vec3 normalized_axis;

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

int intersect_cylinder(t_ray *ray, t_cylinder *cy, t_hit_info *hit)
{
	double t_min = INFINITY;
	double t_body, t_top, t_bot;
	int hit_body, hit_top, hit_bot;
	t_vec3 normalized_axis;

	normalized_axis = vec_normalize(cy->axis);
	hit_body = solve_infinite_cylinder(ray, cy, &t_body);
	hit_top = solve_cap(ray, cy, vec_add(cy->point, vec_mul(normalized_axis, cy->height)), &t_top);
	hit_bot = solve_cap(ray, cy, cy->point, &t_bot);

	// Initialize hit info to avoid uninitialized values
	hit->t = INFINITY;
	hit->point = (t_vec3){0, 0, 0};
	hit->normal = (t_vec3){0, 0, 0};
	hit->color = cy->color;

	if (hit_body && t_body < t_min && t_body > 0.001)
	{
		t_min = t_body;
		hit->t = t_body;
		hit->point = vec_add(ray->origin, vec_mul(ray->direction, t_body));

		// Calculate normal for cylinder body
		t_vec3 hit_to_axis = vec_sub(hit->point, cy->point);
		t_vec3 projected = project_vector(hit_to_axis, normalized_axis);
		hit->normal = vec_normalize(vec_sub(hit_to_axis, projected));
	}
	if (hit_top && t_top < t_min && t_top > 0.001)
	{
		t_min = t_top;
		hit->t = t_top;
		hit->point = vec_add(ray->origin, vec_mul(ray->direction, t_top));
		hit->normal = normalized_axis;
	}
	if (hit_bot && t_bot < t_min && t_bot > 0.001)
	{
		t_min = t_bot;
		hit->t = t_bot;
		hit->point = vec_add(ray->origin, vec_mul(ray->direction, t_bot));
		hit->normal = vec_mul(normalized_axis, -1);
	}

	if (t_min < INFINITY)
	{
		return (1);
	}
	return (0);
}
