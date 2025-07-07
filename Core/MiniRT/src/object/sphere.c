/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:58:37 by mpoesy            #+#    #+#             */
/*   Updated: 2025/07/07 18:04:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static double	calculate_discriminant(t_ray *ray, t_sphere *sphere)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = vec_sub(ray->origin, sphere->center);
	a = vec_dot(ray->direction, ray->direction);
	b = 2.0 * vec_dot(oc, ray->direction);
	c = vec_dot(oc, oc) - sphere->radius * sphere->radius;
	return (b * b - 4 * a * c);
}

static double	get_valid_t(double discriminant, double a, double b)
{
	double	sqrt_disc;
	double	t1;
	double	t2;

	sqrt_disc = sqrt(discriminant);
	t1 = (-b - sqrt_disc) / (2 * a);
	t2 = (-b + sqrt_disc) / (2 * a);
	if (t1 > 0 && t2 > 0)
		return (fmin(t1, t2));
	else if (t1 > 0)
		return (t1);
	else if (t2 > 0)
		return (t2);
	return (-1);
}

static void	fill_hit_info(t_hit_info *hit, t_ray *ray, t_sphere *sphere)
{
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, hit->t));
	hit->normal = vec_normalize(vec_sub(hit->point, sphere->center));
	hit->color = sphere->color;
}

int	intersect_sphere(t_ray *ray, t_sphere *sphere, t_hit_info *hit)
{
	double	discriminant;
	double	a;
	double	b;
	double	t_hit;

	discriminant = calculate_discriminant(ray, sphere);
	if (discriminant < 0)
		return (0);
	a = vec_dot(ray->direction, ray->direction);
	b = 2.0 * vec_dot(vec_sub(ray->origin, sphere->center), ray->direction);
	t_hit = get_valid_t(discriminant, a, b);
	if (t_hit <= 0)
		return (0);
	hit->t = t_hit;
	fill_hit_info(hit, ray, sphere);
	return (1);
}
