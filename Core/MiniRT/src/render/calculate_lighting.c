/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:01:49 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/19 14:32:34 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color calculate_lighting(const t_hit_info *hit, t_scene *scene)
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
