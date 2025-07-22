/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spotlight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:44:50 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 10:37:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	parse_check(char **str)
{
	if (util_array_count((void **)str) < 4)
		return (ERROR_PARSE_SPOTLIGHT);
	if (!util_vector_check(str[1]))
		return (ERROR_PARSE_VECTOR);
	if (!util_num_check(str[2]))
		return (ERROR_PARSE_NUM);
	if (!util_color_check(str[3]))
		return (ERROR_PARSE_COLOR);
	return (0);
}

void	parse_spotlight(t_scene *scene, char **str, char *line, const int fd)
{
	t_spotlight	*light;
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
	light = malloc(sizeof(t_spotlight));
	if (!light)
		error_throw(ERROR_MALLOC);
	light->position = util_vector_parse(str[1]);
	light->diffuse = util_num_parse(str[2]);
	light->color = util_color_parse(str[3]);
	add_object_to_scene(scene, OBJ_LIGHT, light);
}
