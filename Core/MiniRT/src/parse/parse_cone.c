/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:45:17 by ibour             #+#    #+#             */
/*   Updated: 2025/07/15 11:42:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parse_cone(t_scene *scene, char **str)
{
	t_cone	*cone;

	if (util_array_count((void **)str) < 6)
		error_throw(ERROR_PARSE_CYLINDER);
	cone = malloc(sizeof(t_cone));
	if (!cone)
		error_throw(ERROR_MALLOC);
	cone->point = util_vector_parse(str[1]);
	cone->axis = vec_normalize(util_vector_parse(str[2]));
	cone->radius = util_num_parse(str[3]) / 2;
	cone->height = util_num_parse(str[4]);
	cone->color = util_color_parse(str[5]);
	add_object_to_scene(scene, OBJ_CONE, cone);
}
