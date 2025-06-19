/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:40:34 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/19 11:56:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	trace_ray(t_ray *ray, t_scene *scene)
{
	double		closest_t;
	t_object	*obj;
	t_hit_info	closest_hit;
	int			hit_found;
	t_hit_info	temp_hit;

	closest_t = INFINITY;
	obj = scene->objects;
	hit_found = 0;
	while (obj)
	{
		if (intersect(ray, obj, &temp_hit))
		{
			if (temp_hit.t < closest_t && temp_hit.t > 0)
			{
				closest_t = temp_hit.t;
				closest_hit = temp_hit;
				hit_found = 1;
			}
		}
		obj = obj->next;
	}
	if (!hit_found)
		return ((t_color){135, 206, 235});
	return (calculate_lighting(&closest_hit, scene));
}
