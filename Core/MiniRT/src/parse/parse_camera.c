/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:44:59 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 10:52:54 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	parse_check(char **str)
{
	if (util_array_count((void **)str) < 4)
		return (ERROR_PARSE_CAMERA);
	if (!util_vector_check(str[1]))
		return (ERROR_PARSE_VECTOR);
	if (!util_vector_check(str[2]))
		return (ERROR_PARSE_VECTOR);
	if (!util_num_parse(str[3]))
		return (ERROR_PARSE_NUM);
	return (0);
}

void	parse_camera(t_scene *scene, char **str, char *line, const int fd)
{
	int	error;

	error = parse_check(str);
	if (error != 0)
	{
		util_array_free((void **) str);
		free(line);
		util_array_gnl_free(fd);
		exit_data_pre_render(scene);
		error_throw(error);
	}
	scene->camera.position = util_vector_parse(str[1]);
	scene->camera.direction = vec_normalize(util_vector_parse(str[2]));
	scene->camera.fov = util_num_parse(str[3]);
	scene->camera.fov = fmin(fmax(scene->camera.fov, 0.0), 180.0);
	scene->camera.pitch = asin(-scene->camera.direction.y) * 180.0 / M_PI;
	scene->camera.yaw = atan2(scene->camera.direction.z,
			scene->camera.direction.x) * 180.0 / M_PI;
	scene->camera.up = (t_vec3){0.0, 1.0, 0.0};
	scene->camera.forward = vec_normalize(scene->camera.direction);
	scene->camera.right = vec_normalize(vec_cross(scene->camera.forward,
				scene->camera.up));
	scene->camera.up = vec_normalize(vec_cross(scene->camera.right,
				scene->camera.forward));
	scene->has_camera = 1;
}
