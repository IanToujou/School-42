/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:05:28 by ibour             #+#    #+#             */
/*   Updated: 2025/07/07 18:01:24 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	init_mlx_gfx(t_scene *scene)
{
	scene->image.img_ptr = mlx_new_image(scene->mlx_ptr, WIDTH, HEIGHT);
	if (!scene->image.img_ptr)
		error_throw(ERROR_INIT_MLX);
	scene->image.data = mlx_get_data_addr(scene->image.img_ptr,
			&scene->image.bpp, &scene->image.line_length, &scene->image.endian);
}

/**
 * Initializes the MLX library and creates a new window
 * to work with.
 *
 * @param scene The data of the program.
 * @return 0 if the process was successful. -1 if an error occurred.
 */
void	init_mlx(t_scene *scene)
{
	scene->mlx_ptr = mlx_init();
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, WIDTH,
			HEIGHT, "MiniRT");
	if (!scene->win_ptr)
		error_throw(ERROR_INIT_MLX);
	init_mlx_gfx(scene);
}
