/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:44:59 by ibour             #+#    #+#             */
/*   Updated: 2025/06/20 13:35:24 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parse_camera(t_scene *scene, char **str)
{
	if (util_array_count((void **)str) < 4)
		error_throw(ERROR_PARSE_CAMERA);
	scene->camera.position = util_vector_parse(str[1]);
	scene->camera.direction = vec_normalize(util_vector_parse(str[2]));
	scene->camera.fov = util_num_parse(str[3]);
	scene->camera.fov = fmin(fmax(scene->camera.fov, 0.0), 180.0);
	scene->camera.up = (t_vec3){0.0, 1.0, 0.0};
	scene->camera.forward = vec_normalize(scene->camera.direction);
	scene->camera.right = vec_normalize(vec_cross(scene->camera.forward,
												  scene->camera.up));
}
