/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:01:49 by mpoesy            #+#    #+#             */
/*   Updated: 2025/07/15 10:44:08 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static t_color	apply_checkerboard_pattern(t_vec3 hit_point, t_color base_color)
{
	double	scale = 0.1; // Size of the checkerboard squares
	int		x_check = (int)floor(hit_point.x * scale);
	int		y_check = (int)floor(hit_point.y * scale);
	int		z_check = (int)floor(hit_point.z * scale);

	// Create checkerboard pattern using XOR
	int		is_odd = (x_check + y_check + z_check) % 2;

	if (is_odd)
		return (base_color);
	else
		return ((t_color){base_color.r * 0.3, base_color.g * 0.3, base_color.b * 0.3}); // Darker version
}

static t_color	calculate_specular_light(const t_hit_info *hit,
		t_spotlight *light, t_vec3 view_dir)
{
	t_vec3	light_dir;
	t_vec3	reflect_dir;
	double	spec;
	t_color	specular;

	light_dir = vec_normalize(vec_sub(light->position, hit->point));
	reflect_dir = vec_reflect(vec_negate(light_dir), hit->normal);
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), SHININESS);
	specular = color_scale((t_color){255, 255, 255}, spec * light->diffuse);
	return (specular);
}

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
	t_color	pattern_color;

	// Apply checkerboard pattern to the base color
	pattern_color = apply_checkerboard_pattern(hit->point, hit->color);

	ambient = color_scale(pattern_color, scene->ambient.ratio);
	ambient = util_color_multiply(ambient, scene->ambient.color);
	return (ambient);
}

static t_color	calculate_diffuse_light(const t_hit_info *hit,
		t_spotlight *light)
{
	t_vec3	light_dir;
	double	diff;
	t_color	diffuse;
	t_color	pattern_color;

	// Apply checkerboard pattern to the base color
	pattern_color = apply_checkerboard_pattern(hit->point, hit->color);

	light_dir = vec_normalize(vec_sub(light->position, hit->point));
	diff = fmax(vec_dot(hit->normal, light_dir), 0.0);
	diffuse = color_scale(pattern_color, diff * light->diffuse);
	diffuse = util_color_multiply(diffuse, light->color);
	return (diffuse);
}

static t_color	process_light_object(const t_hit_info *hit,
		t_scene *scene, t_object *obj, t_vec3 view_dir)
{
	t_spotlight	*light;
	t_color		diffuse;
	t_color		specular;

	light = (t_spotlight *)obj->data;
	if (is_shadow(scene, hit->point, light->position))
		return ((t_color){0, 0, 0});
	diffuse = calculate_diffuse_light(hit, light);
	specular = calculate_specular_light(hit, light, view_dir);
	return (add_color(diffuse, specular));
}

t_color	calculate_lighting(const t_hit_info *hit, t_scene *scene)
{
	t_color		final_color;
	t_object	*obj;
	t_color		light_contribution;
	t_vec3		view_dir;

	final_color = calculate_ambient(hit, scene);
	obj = scene->objects;
	view_dir = vec_normalize(vec_sub(scene->camera.position, hit->point));
	while (obj)
	{
		if (obj->type == OBJ_LIGHT)
		{
			light_contribution = process_light_object(hit, scene, obj, view_dir);
			final_color = add_color(final_color, light_contribution);
		}
		obj = obj->next;
	}
	return (final_color);
}
