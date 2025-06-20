/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spotlight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:44:50 by ibour             #+#    #+#             */
/*   Updated: 2025/06/20 13:24:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parse_spotlight(t_scene *scene, char **str) {
	t_spotlight	*light;

	if (util_array_count((void **)str) < 4)
		error_throw(ERROR_PARSE_SPOTLIGHT);
	light = malloc(sizeof(t_sphere));
	if (!light)
		error_throw(ERROR_MALLOC);
	light->position = util_vector_parse(str[1]);
	light->diffuse = util_num_parse(str[2]);
	light->color = util_color_parse(str[3]);
	add_object_to_scene(scene, OBJ_LIGHT, light);
}
