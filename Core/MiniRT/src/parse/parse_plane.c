/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:45:40 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 10:37:35 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	parse_check(char **str)
{
	if (util_array_count((void **)str) < 4)
		return (ERROR_PARSE_PLANE);
	if (!util_vector_check(str[1]))
		return (ERROR_PARSE_VECTOR);
	if (!util_vector_check(str[2]))
		return (ERROR_PARSE_VECTOR);
	if (!util_color_check(str[3]))
		return (ERROR_PARSE_COLOR);
	return (0);
}

void	parse_plane(t_scene *scene, char **str, char *line, const int fd)
{
	t_plane	*plane;
	int		error;

	error = parse_check(str);
	if (error != 0)
	{
		util_array_free((void **) str);
		free(line);
		util_array_gnl_free(fd);
		exit_data_pre_render(scene);
		error_throw(error);
	}
	plane = malloc(sizeof(t_plane));
	if (!plane)
		error_throw(ERROR_MALLOC);
	plane->point = util_vector_parse(str[1]);
	plane->normal = vec_normalize(util_vector_parse(str[2]));
	plane->color = util_color_parse(str[3]);
	add_object_to_scene(scene, OBJ_PLANE, plane);
}
