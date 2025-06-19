/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:59:27 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/19 11:56:23 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// Plane: point on plane + normal (normalized)
int	intersect_plane(t_ray *ray, t_plane *plane, t_hit_info *hit)
{
	double	denom;
	t_vec3	p;
	double	t_hit;

	denom = vec_dot(plane->normal, ray->direction);
	if (fabs(denom) < 1e-6)
		return (0);
	p = vec_sub(plane->point, ray->origin);
	t_hit = vec_dot(p, plane->normal) / denom;
	if (t_hit < 0)
		return (0);
	hit->t = t_hit;
	hit->point = vec_add(ray->origin, vec_mul(ray->direction, t_hit));
	hit->normal = plane->normal;
	hit->color = plane->color;
	return (1);
}
