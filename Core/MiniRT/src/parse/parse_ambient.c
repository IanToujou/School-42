/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:06:52 by ibour             #+#    #+#             */
/*   Updated: 2025/06/19 13:10:53 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parse_ambient(t_scene *scene, char *array)
{
	// parse errors
	scene->light.intensity = util_parse_double(array[1]);
}
