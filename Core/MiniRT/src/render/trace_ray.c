/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:40:34 by mpoesy            #+#    #+#             */
/*   Updated: 2025/07/07 18:23:31 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	initialize_hit_data(t_hit_info *closest_hit, t_hit_info *temp_hit)
{
	ft_memset(temp_hit, 0, sizeof(t_hit_info));
	ft_memset(closest_hit, 0, sizeof(t_hit_info));
}

static int	update_closest_hit(t_hit_info *temp_hit,
		t_hit_info *closest_hit, double *closest_t)
{
	if (temp_hit->t < *closest_t && temp_hit->t > 0)
	{
		*closest_t = temp_hit->t;
		*closest_hit = *temp_hit;
		return (1);
	}
	return (0);
}

static int	find_closest_intersection(t_ray *ray, t_scene *scene,
		t_hit_info *closest_hit)
{
	t_object	*obj;
	t_hit_info	temp_hit;
	double		closest_t;
	int			hit_found;

	closest_t = INFINITY;
	hit_found = 0;
	obj = scene->objects;
	initialize_hit_data(closest_hit, &temp_hit);
	while (obj)
	{
		ft_memset(&temp_hit, 0, sizeof(t_hit_info));
		if (intersect(ray, obj, &temp_hit))
		{
			if (update_closest_hit(&temp_hit, closest_hit, &closest_t))
				hit_found = 1;
		}
		obj = obj->next;
	}
	return (hit_found);
}

t_color	trace_ray(t_ray *ray, t_scene *scene)
{
	t_hit_info	closest_hit;
	int			hit_found;

	hit_found = find_closest_intersection(ray, scene, &closest_hit);
	if (!hit_found)
		return ((t_color){135, 206, 235});
	return (calculate_lighting(&closest_hit, scene));
}
