/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:01:49 by mpoesy            #+#    #+#             */
/*   Updated: 2025/07/07 18:22:33 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	is_shadow(t_scene *scene, t_vec3 hit_point, t_vec3 light_pos)
{
	t_ray		shadow_ray;
	t_object	*obj;
	t_hit_info	temp_hit;
	double		distance_to_light;

	shadow_ray.origin = hit_point;
	shadow_ray.direction = vec_normalize(vec_sub(light_pos, hit_point));
	distance_to_light = vec_length(vec_sub(light_pos, hit_point));
	ft_memset(&temp_hit, 0, sizeof(t_hit_info));
	obj = scene->objects;
	while (obj)
	{
		if (obj->type != OBJ_LIGHT && intersect(&shadow_ray, obj, &temp_hit))
		{
			if (temp_hit.t > 0.001 && temp_hit.t < distance_to_light)
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}

static t_color	calculate_ambient(const t_hit_info *hit, t_scene *scene)
{
	t_color	ambient;

	ambient = color_scale(hit->color, scene->ambient.ratio);
	ambient = util_color_multiply(ambient, scene->ambient.color);
	return (ambient);
}

static t_color	calculate_diffuse_light(const t_hit_info *hit,
		t_spotlight *light)
{
	t_vec3	light_dir;
	double	diff;
	t_color	diffuse;

	light_dir = vec_normalize(vec_sub(light->position, hit->point));
	diff = fmax(vec_dot(hit->normal, light_dir), 0.0);
	diffuse = color_scale(hit->color, diff * light->diffuse);
	diffuse = util_color_multiply(diffuse, light->color);
	return (diffuse);
}

static t_color	process_light_object(const t_hit_info *hit,
		t_scene *scene, t_object *obj)
{
	t_spotlight	*light;
	t_color		diffuse;

	light = (t_spotlight *)obj->data;
	if (is_shadow(scene, hit->point, light->position))
		return ((t_color){0, 0, 0});
	diffuse = calculate_diffuse_light(hit, light);
	return (diffuse);
}

t_color	calculate_lighting(const t_hit_info *hit, t_scene *scene)
{
	t_color		final_color;
	t_object	*obj;
	t_color		light_contribution;

	final_color = calculate_ambient(hit, scene);
	obj = scene->objects;
	while (obj)
	{
		if (obj->type == OBJ_LIGHT)
		{
			light_contribution = process_light_object(hit, scene, obj);
			final_color = add_color(final_color, light_contribution);
		}
		obj = obj->next;
	}
	return (final_color);
}
