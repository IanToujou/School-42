/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:09:51 by ibour             #+#    #+#             */
/*   Updated: 2025/07/07 17:49:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

/**
 * Exits the MLX library and closes any existing windows.
 *
 * @param scene The data of the program.
 */
void	exit_mlx(t_scene *scene)
{
	if (!scene || !scene->mlx_ptr)
		return ;
	if (scene->image.img_ptr)
	{
		mlx_destroy_image(scene->mlx_ptr, scene->image.img_ptr);
		scene->image.img_ptr = NULL;
	}
	if (scene->win_ptr)
	{
		mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
		scene->win_ptr = NULL;
	}
	mlx_destroy_display(scene->mlx_ptr);
	free(scene->mlx_ptr);
	scene->mlx_ptr = NULL;
}
