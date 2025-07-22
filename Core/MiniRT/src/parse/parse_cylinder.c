/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:45:22 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 10:37:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	parse_check(char **str)
{
	if (util_array_count((void **)str) < 6)
		return (ERROR_PARSE_CYLINDER);
	if (!util_vector_check(str[1]))
		return (ERROR_PARSE_VECTOR);
	if (!util_vector_check(str[2]))
		return (ERROR_PARSE_VECTOR);
	if (!util_num_check(str[3]))
		return (ERROR_PARSE_NUM);
	if (!util_num_check(str[4]))
		return (ERROR_PARSE_NUM);
	if (!util_color_check(str[5]))
		return (ERROR_PARSE_COLOR);
	return (0);
}

void	parse_cylinder(t_scene *scene, char **str, char *line, const int fd)
{
	t_cylinder	*cylinder;
	int			error;

	error = parse_check(str);
	if (error != 0)
	{
		util_array_free((void **) str);
		free(line);
		util_array_gnl_free(fd);
		exit_data_pre_render(scene);
		error_throw(error);
	}
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		error_throw(ERROR_MALLOC);
	cylinder->point = util_vector_parse(str[1]);
	cylinder->axis = vec_normalize(util_vector_parse(str[2]));
	cylinder->radius = util_num_parse(str[3]) / 2;
	cylinder->height = util_num_parse(str[4]);
	cylinder->color = util_color_parse(str[5]);
	add_object_to_scene(scene, OBJ_CYLINDER, cylinder);
}
