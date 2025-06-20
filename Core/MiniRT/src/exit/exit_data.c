/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:38:22 by ibour             #+#    #+#             */
/*   Updated: 2025/06/20 07:51:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	exit_data(const t_scene *scene)
{
	(void)scene;
	if (scene && scene->mlx_ptr)
		free(scene->mlx_ptr);
}
