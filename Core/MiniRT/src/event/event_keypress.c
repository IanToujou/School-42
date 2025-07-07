/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:26:56 by ibour             #+#    #+#             */
/*   Updated: 2025/07/07 17:53:48 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	event_keypress_help(const int keycode, t_scene *scene)
{
	if (keycode == KEY_W)
	{
		scene->camera.position = vec_add(scene->camera.position,
				vec_mul(scene->camera.direction, MOVE_SPEED));
		render_scene(scene);
	}
	else if (keycode == KEY_S)
	{
		scene->camera.position = vec_sub(scene->camera.position,
				vec_mul(scene->camera.direction, MOVE_SPEED));
		render_scene(scene);
	}
	else if (keycode == KEY_D)
	{
		scene->camera.position = vec_add(scene->camera.position,
				vec_mul(scene->camera.right, MOVE_SPEED));
		render_scene(scene);
	}
	else if (keycode == KEY_A)
	{
		scene->camera.position = vec_sub(scene->camera.position,
				vec_mul(scene->camera.right, MOVE_SPEED));
		render_scene(scene);
	}
}

static void	event_keypress_secondary(const int keycode, t_scene *scene)
{
	if (keycode == KEY_UP)
	{
		scene->camera.pitch += 3.0;
		if (scene->camera.pitch > 89.0)
			scene->camera.pitch = 89.0;
		util_camera_update_vec_dir(&scene->camera);
		util_camera_update_vec(&scene->camera);
		render_scene(scene);
	}
	else if (keycode == KEY_DOWN)
	{
		scene->camera.pitch -= 3.0;
		if (scene->camera.pitch < -89.0)
			scene->camera.pitch = -89.0;
		util_camera_update_vec_dir(&scene->camera);
		util_camera_update_vec(&scene->camera);
		render_scene(scene);
	}
	else
		event_keypress_help(keycode, scene);
}

int	event_keypress(const int keycode, t_scene *scene)
{
	if (keycode == ESC_KEY)
		event_close(scene);
	else if (keycode == KEY_RIGHT)
	{
		scene->camera.yaw += 3.0;
		util_camera_update_vec_dir(&scene->camera);
		util_camera_update_vec(&scene->camera);
		render_scene(scene);
	}
	else if (keycode == KEY_LEFT)
	{
		scene->camera.yaw -= 3.0;
		util_camera_update_vec_dir(&scene->camera);
		util_camera_update_vec(&scene->camera);
		render_scene(scene);
	}
	else
		event_keypress_secondary(keycode, scene);
	return (0);
}
