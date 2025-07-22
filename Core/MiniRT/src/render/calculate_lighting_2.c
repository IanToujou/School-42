/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:00:54 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 11:01:38 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	apply_checkerboard_pattern(t_vec3 hit_point, t_color base_color)
{
	int		x_check;
	int		y_check;
	int		z_check;
	int		is_odd;

	x_check = (int)floor(hit_point.x * 0.1);
	y_check = (int)floor(hit_point.y * 0.1);
	z_check = (int)floor(hit_point.z * 0.1);
	is_odd = (x_check + y_check + z_check) % 2;
	if (is_odd)
		return (base_color);
	return ((t_color){base_color.r * 0.3, base_color.g
		* 0.3, base_color.b * 0.3});
}

t_color	calculate_specular_light(const t_hit_info *hit,
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
