/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:51:30 by ibour             #+#    #+#             */
/*   Updated: 2025/07/15 11:45:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	solve_cone_surface(t_ray *ray, t_cone *cone, double *t)
{
	t_vec3	oc;
	t_vec3	axis;
	t_vec3	apex;
	double	k;
	double	a, b, c;
	double	discriminant;
	double	t1, t2;
	double	dot_rd_axis, dot_oa_axis;

	axis = vec_normalize(cone->axis);
	apex = vec_add(cone->point, vec_mul(axis, cone->height));
	oc = vec_sub(ray->origin, apex);
	k = (cone->radius * cone->radius) / (cone->height * cone->height);
	dot_rd_axis = vec_dot(ray->direction, axis);
	dot_oa_axis = vec_dot(oc, axis);
	a = vec_dot(ray->direction, ray->direction) - (1 + k) * dot_rd_axis * dot_rd_axis;
	b = 2 * (vec_dot(ray->direction, oc) - (1 + k) * dot_rd_axis * dot_oa_axis);
	c = vec_dot(oc, oc) - (1 + k) * dot_oa_axis * dot_oa_axis;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	discriminant = sqrt(discriminant);
	t1 = (-b - discriminant) / (2 * a);
	t2 = (-b + discriminant) / (2 * a);
	if (t1 > 0.001 && t2 > 0.001)
		*t = fmin(t1, t2);
	else if (t1 > 0.001)
		*t = t1;
	else if (t2 > 0.001)
		*t = t2;
	else
		return (0);
	return (1);
}

static int	check_cone_height_bounds(t_ray *ray, t_cone *cone, double t)
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

static int	solve_cone_cap(t_ray *ray, t_cone *cone, double *t)
{
	t_vec3	axis;
	t_vec3	cap_center;
	double	denom;
	double	t_hit;
	t_vec3	hit_point;
	double	distance_from_center;

	axis = vec_normalize(cone->axis);
	cap_center = cone->point;
	denom = vec_dot(ray->direction, axis);
	if (fabs(denom) < 1e-6)
		return (0);
	t_hit = vec_dot(vec_sub(cap_center, ray->origin), axis) / denom;
	if (t_hit < 0.001)
		return (0);
	hit_point = vec_add(ray->origin, vec_mul(ray->direction, t_hit));
	distance_from_center = vec_length(vec_sub(hit_point, cap_center));
	if (distance_from_center > cone->radius)
		return (0);
	*t = t_hit;
	return (1);
}

static void	calculate_cone_intersections(t_ray *ray, t_cone *cone, double *t_vals)
{
	double	t_surface;
	double	t_cap;

	t_vals[0] = -1;
	t_vals[1] = -1;
	if (solve_cone_surface(ray, cone, &t_surface) &&
		check_cone_height_bounds(ray, cone, t_surface))
		t_vals[0] = t_surface;
	if (solve_cone_cap(ray, cone, &t_cap))
		t_vals[1] = t_cap;
}

static void	update_cone_surface_hit(t_hit_info *hit, t_ray *ray, t_cone *cone)
{
	t_vec3	axis;
	t_vec3	hit_to_base;
	double	proj_length;
	t_vec3	radial_direction;
	double	slope;

	axis = vec_normalize(cone->axis);
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, hit->t));
	hit_to_base = vec_sub(hit->point, cone->point);
	proj_length = vec_dot(hit_to_base, axis);
	t_vec3 axis_point = vec_add(cone->point, vec_mul(axis, proj_length));
	radial_direction = vec_sub(hit->point, axis_point);
	if (vec_length(radial_direction) > 1e-6)
		radial_direction = vec_normalize(radial_direction);
	else
		radial_direction = (t_vec3){1, 0, 0};
	slope = cone->radius / cone->height;
	hit->normal = vec_add(radial_direction, vec_mul(axis, slope));
	hit->normal = vec_normalize(hit->normal);
}

static void	update_cone_cap_hit(t_hit_info *hit, t_ray *ray, t_cone *cone)
{
	t_vec3	axis;

	axis = vec_normalize(cone->axis);
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, hit->t));
	hit->normal = vec_mul(axis, -1);  // Normal points away from cone interior
}

static int	find_closest_cone_hit(double *t_vals, t_hit_info *hit)
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
