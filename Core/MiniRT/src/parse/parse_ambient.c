/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:06:52 by ibour             #+#    #+#             */
/*   Updated: 2025/06/20 13:24:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parse_ambient(t_scene *scene, char **str)
{
	if (util_array_count((void **)str) < 3)
		error_throw(ERROR_PARSE_AMBIENT);
	scene->ambient.ratio = util_num_parse(str[1]);
	if (scene->ambient.ratio <= 0.0)
		error_throw(ERROR_RENDER_AMBIENT_RATIO);
	scene->ambient.color = util_color_parse(str[2]);
}
