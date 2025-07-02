/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:00:38 by mpoesy            #+#    #+#             */
/*   Updated: 2025/07/02 09:50:48 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int intersect(t_ray *ray, t_object *obj, t_hit_info *hit)
{
	if (hit)
	{
		hit->t = -1.0;
		hit->point = (t_vec3){0.0, 0.0, 0.0};
		hit->normal = (t_vec3){0.0, 0.0, 1.0};
		hit->color = (t_color){0, 0, 0};
	}
	if (!ray || !obj || !obj->data || !hit)
		return (0);
	if (obj->type == OBJ_SPHERE)
		return (intersect_sphere(ray, (t_sphere *) obj->data, hit));
	else if (obj->type == OBJ_PLANE)
		return (intersect_plane(ray, (t_plane *) obj->data, hit));
	else if (obj->type == OBJ_CYLINDER)
		return (intersect_cylinder(ray, (t_cylinder *) obj->data, hit));
	return (0);
}
