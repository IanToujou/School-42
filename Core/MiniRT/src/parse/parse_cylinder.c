/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:45:22 by ibour             #+#    #+#             */
/*   Updated: 2025/06/20 13:23:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parse_cylinder(t_scene *scene, char **str) {
	t_cylinder	*cylinder;

	if (util_array_count((void **)str) < 6)
		error_throw(ERROR_PARSE_CYLINDER);
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		error_throw(ERROR_MALLOC);
	cylinder->point = util_vector_parse(str[1]);
	cylinder->axis = util_vector_parse(str[2]);
	cylinder->radius = util_num_parse(str[3]) / 2;
	cylinder->height = util_num_parse(str[4]);
	cylinder->color = util_color_parse(str[5]);
	add_object_to_scene(scene, OBJ_CYLINDER, cylinder);
}
