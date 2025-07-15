/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:38:22 by ibour             #+#    #+#             */
/*   Updated: 2025/07/15 10:38:49 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	exit_data(t_scene *scene)
{
	t_object	*current;
	t_object	*next;

	if (!scene)
		return ;
	current = scene->objects;
	while (current)
	{
		next = current->next;
		if (current->data)
			free(current->data);
		free(current);
		current = next;
	}
	if (scene->mlx_ptr)
	{
		if (scene->image.img_ptr)
			mlx_destroy_image(scene->mlx_ptr, scene->image.img_ptr);
		if (scene->win_ptr)
			mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
		mlx_destroy_display(scene->mlx_ptr);
		free(scene->mlx_ptr);
	}
	free(scene);
}
