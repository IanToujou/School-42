/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:06:52 by ibour             #+#    #+#             */
/*   Updated: 2025/06/19 14:24:27 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	parse_ambient(t_scene *scene, char **str)
{
	// todo parse errors
	scene->ambient.ratio = util_num_parse(str[1]);
	scene->ambient.color = util_color_parse(str[2]);

}
