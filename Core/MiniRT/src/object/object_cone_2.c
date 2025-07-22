/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cone_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:57:30 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 11:00:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	calculate_cone_quadratic(t_ray *ray, t_cone *cone, double *abc)
{
	t_vec3	axis;
	t_vec3	apex;
	t_vec3	oc;
	double	k;

	axis = vec_normalize(cone->axis);
	apex = vec_add(cone->point, vec_mul(axis, cone->height));
	oc = vec_sub(ray->origin, apex);
	k = (cone->radius * cone->radius) / (cone->height * cone->height);
	abc[0] = vec_dot(ray->direction, ray->direction) - (1 + k)
		* vec_dot(ray->direction, axis) * vec_dot(ray->direction, axis);
	abc[1] = 2 * (vec_dot(ray->direction, oc) - (1 + k)
			* vec_dot(ray->direction, axis) * vec_dot(oc, axis));
	abc[2] = vec_dot(oc, oc) - (1 + k)
		* vec_dot(oc, axis) * vec_dot(oc, axis);
}

int	solve_quadratic_roots(double *abc, double *roots)
{
	double	discriminant;

	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discriminant < 0)
		return (0);
	discriminant = sqrt(discriminant);
	roots[0] = (-abc[1] - discriminant) / (2 * abc[0]);
	roots[1] = (-abc[1] + discriminant) / (2 * abc[0]);
	return (1);
}

int	select_valid_root(double *roots, double *t)
{
	if (roots[0] > 0.001 && roots[1] > 0.001)
		*t = fmin(roots[0], roots[1]);
	else if (roots[0] > 0.001)
		*t = roots[0];
	else if (roots[1] > 0.001)
		*t = roots[1];
	else
		return (0);
	return (1);
}

int	solve_cone_surface(t_ray *ray, t_cone *cone, double *t)
{
	double	abc[3];
	double	roots[2];

	calculate_cone_quadratic(ray, cone, abc);
	if (!solve_quadratic_roots(abc, roots))
		return (0);
	return (select_valid_root(roots, t));
}
