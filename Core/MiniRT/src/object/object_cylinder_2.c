/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:13:05 by ibour             #+#    #+#             */
/*   Updated: 2025/07/07 18:13:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	project_length(t_vec3 v, t_vec3 axis)
{
	return (vec_dot(v, axis));
}

t_vec3	project_vector(t_vec3 v, t_vec3 axis)
{
	return (vec_mul(axis, vec_dot(v, axis)));
}

void	calc_perp_comp(t_ray *ray, t_cylinder *cy, t_vec3 *perp_vals)
{
	t_vec3	ca;
	t_vec3	oc;

	ca = vec_normalize(cy->axis);
	oc = vec_sub(ray->origin, cy->point);
	perp_vals[0] = vec_sub(ray->direction, project_vector(ray->direction, ca));
	perp_vals[1] = vec_sub(oc, project_vector(oc, ca));
}

double	calc_disc(t_vec3 *perp_vals, t_cylinder *cy)
{
	double	a;
	double	b;
	double	c;

	a = vec_dot(perp_vals[0], perp_vals[0]);
	if (fabs(a) < 1e-9)
		return (-1);
	b = 2 * vec_dot(perp_vals[0], perp_vals[1]);
	c = vec_dot(perp_vals[1], perp_vals[1]) - cy->radius * cy->radius;
	return (b * b - 4 * a * c);
}

double	get_valid_cylinder_t(double discriminant, t_vec3 *perp_vals)
{
	double	a;
	double	sqrt_disc;
	double	t0;
	double	t1;

	if (discriminant < 0)
		return (-1);
	a = vec_dot(perp_vals[0], perp_vals[0]);
	sqrt_disc = sqrt(discriminant);
	t0 = (-2 * vec_dot(perp_vals[0], perp_vals[1]) - sqrt_disc) / (2 * a);
	t1 = (-2 * vec_dot(perp_vals[0], perp_vals[1]) + sqrt_disc) / (2 * a);
	if (t0 > 0.001 && t1 > 0.001)
		return (fmin(t0, t1));
	else if (t0 > 0.001)
		return (t0);
	else if (t1 > 0.001)
		return (t1);
	return (-1);
}
