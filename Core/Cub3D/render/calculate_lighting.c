/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:01:49 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/16 17:16:22 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	calculate_lighting(t_hit_info *hit, t_scene *scene)
{
	double	ambient_intensity;
	t_color	ambient;
	t_vec3	light_dir;
	double	diff;
	t_color	diffuse;

	ambient_intensity = 0.1;
	ambient = color_scale(hit->color, ambient_intensity);
	light_dir = vec_normalize(vec_sub(scene->light.position, hit->point));
	diff = fmax(vec_dot(hit->normal, light_dir), 0.0);
	diffuse = color_scale(hit->color, diff * scene->light.intensity);
	return (add_color(ambient, diffuse));
}
