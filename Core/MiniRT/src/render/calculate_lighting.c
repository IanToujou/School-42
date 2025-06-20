/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:01:49 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/20 12:36:53 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	is_shadow(t_scene *scene, t_vec3 hit_point, t_vec3 light_pos)
{
	t_ray	shadow_ray;
	t_object *obj;
	t_hit_info temp_hit;
	double	distance_to_light;

	shadow_ray.origin = hit_point;
	shadow_ray.direction = vec_normalize(vec_sub(light_pos, hit_point));

	distance_to_light = vec_length(vec_sub(light_pos, hit_point));

	obj = scene->objects;
	while (obj)
	{
		if (obj->type != OBJ_LIGHT && intersect(&shadow_ray, obj, &temp_hit))
		{
			if (temp_hit.t > 0.001 && temp_hit.t < distance_to_light)
				return (1); // Shadow
		}
		obj = obj->next;
	}
	return (0); // No shadow
}

static t_color calculate_ambient(const t_hit_info *hit, t_scene *scene)
{
	t_color ambient;
	t_vec3 light_dir;
	double diff;
	t_color diffuse;

	ambient = color_scale(hit->color, scene->ambient.ratio);
	light_dir = vec_normalize(vec_sub(scene->ambient.position, hit->point));
	diff = fmax(vec_dot(hit->normal, light_dir), 0.0);
	diffuse = color_scale(hit->color, diff * scene->ambient.ratio);
	return (add_color(ambient, diffuse));
}

t_color calculate_lighting(const t_hit_info *hit, t_scene *scene)
{
	t_color final_color;
	t_object *obj;
	t_spotlight *light;
	t_vec3 light_dir;
	double diff;
	t_color diffuse;

	// Calculate ambient lighting
	final_color = calculate_ambient(hit, scene);

	// Iterate through all objects to find spotlights
	obj = scene->objects;
	while (obj)
	{
		if (obj->type == OBJ_LIGHT)
		{
			light = (t_spotlight *)obj->data;

			// Check for shadows
			if (!is_shadow(scene, hit->point, light->position))
			{
				// Calculate diffuse lighting from this spotlight
				light_dir = vec_normalize(vec_sub(light->position, hit->point));
				diff = fmax(vec_dot(hit->normal, light_dir), 0.0);

				// Apply light's diffuse factor and color
				diffuse = color_scale(hit->color, diff * light->diffuse);

				// Apply light's color (multiply by light color)
				diffuse = util_color_multiply(diffuse, light->color);

				// Add this light's contribution to final color
				final_color = add_color(final_color, diffuse);
			}
		}
		obj = obj->next;
	}

	return (final_color);
}
