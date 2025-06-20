/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:45:40 by ibour             #+#    #+#             */
/*   Updated: 2025/06/20 13:24:22 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/**
 * Parses a plane description from a string array and adds it to the scene.
 *
 * @param scene Pointer to the scene object where the plane will be added.
 * @param str Array of strings containing the plane description.
 *
 * @throws ERROR_PARSE_CAMERA if the input array does not contain exactly four elements.
 * @throws ERROR_MALLOC if memory allocation for the plane fails.
 */
void	parse_plane(t_scene *scene, char **str)
{
	t_plane	*plane;

	if (util_array_count((void **)str) < 4)
		error_throw(ERROR_PARSE_PLANE);
	plane = malloc(sizeof(t_plane));
	if (!plane)
		error_throw(ERROR_MALLOC);
	plane->point = util_vector_parse(str[1]);
	plane->normal = util_vector_parse(str[2]);
	plane->color = util_color_parse(str[3]);
	add_object_to_scene(scene, OBJ_PLANE, plane);
}
