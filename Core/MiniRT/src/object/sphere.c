/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:58:37 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/19 11:56:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	intersect_sphere(t_ray *ray, t_sphere *sphere, t_hit_info *hit)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrt_disc;
	double	t1;
	double	t2;
	double	t_hit;

	oc = vec_sub(ray->origin, sphere->center);
	a = vec_dot(ray->direction, ray->direction);
	b = 2.0 * vec_dot(oc, ray->direction);
	c = vec_dot(oc, oc) - sphere->radius * sphere->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	sqrt_disc = sqrt(discriminant);
	t1 = (-b - sqrt_disc) / (2 * a);
	t2 = (-b + sqrt_disc) / (2 * a);
	t_hit = t1;
	if (t_hit < 0)
		t_hit = t2;
	if (t_hit < 0)
		return (0);
	hit->t = t_hit;
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, t_hit));
	hit->normal = vec_normalize(vec_sub(hit->point, sphere->center));
	hit->color = sphere->color;
	return (1);
}
