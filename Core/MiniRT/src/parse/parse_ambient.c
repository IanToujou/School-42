/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:06:52 by ibour             #+#    #+#             */
/*   Updated: 2025/07/22 10:17:22 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	parse_check(const t_scene *scene, char **str)
{
	if (util_array_count((void **)str) < 3)
		return (ERROR_PARSE_AMBIENT);
	if (util_num_check(str[1]))
		return (ERROR_PARSE_NUM);
	if (util_color_check(str[2]))
		return (ERROR_PARSE_COLOR);
	if (scene->ambient.ratio <= 0.0)
		return (ERROR_RENDER_AMBIENT_RATIO);
	return (0);
}

void	parse_ambient(t_scene *scene, char **str, char *line, const int fd)
{
	int error;

	error = parse_check(scene, str);
	if (error != 0)
	{
		util_array_free((void **) str);
		free(line);
		util_array_gnl_free(fd);
		exit_data_pre_render(scene);
		error_throw(error);
	}
	scene->ambient.ratio = util_num_parse(str[1]);
	scene->ambient.color = util_color_parse(str[2]);
}
