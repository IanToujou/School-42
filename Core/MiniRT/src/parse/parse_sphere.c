/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:45:15 by ibour             #+#    #+#             */
/*   Updated: 2025/06/19 17:37:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parse_sphere(t_scene *scene, char **str) {
	t_sphere	*sphere;

	if (util_array_count((void **)str) != 4)
		error_throw(ERROR_PARSE_SPHERE);
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		error_throw(ERROR_MALLOC);
	sphere->center = util_vector_parse(str[1]);
	sphere->radius = util_num_parse(str[2]) / 2;
	if (sphere->radius <= 0)
		error_throw(ERROR_RENDER_SPHERE_RADIUS);
	sphere->color = util_color_parse(str[3]);
	add_object_to_scene(scene, OBJ_SPHERE, sphere);
}
