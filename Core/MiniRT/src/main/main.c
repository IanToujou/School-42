/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:42:04 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/19 13:02:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int close_window(void *param)
{
	(void) param;
	exit(0);
	return (0);
}

void update_camera_vectors(t_camera *cam)
{
	cam->forward = vec_normalize(cam->direction);
	cam->right = vec_normalize(vec_cross(cam->forward, (t_vec3){0, 1, 0}));
	cam->up = vec_cross(cam->right, cam->forward);
}

void update_camera_vectors_dir(t_camera *cam)
{
	double yaw_rad;
	double pitch_rad;
	double len;

	yaw_rad = cam->yaw * M_PI / 180.0;
	pitch_rad = cam->pitch * M_PI / 180.0;
	cam->direction.x = cos(pitch_rad) * cos(yaw_rad);
	cam->direction.y = sin(pitch_rad);
	cam->direction.z = cos(pitch_rad) * sin(yaw_rad);
	len = sqrt(cam->direction.x * cam->direction.x + cam->direction.y
	           * cam->direction.y + cam->direction.z * cam->direction.z);
	cam->direction.x /= len;
	cam->direction.y /= len;
	cam->direction.z /= len;
}

int key_press(int keycode, void *param)
{
	t_scene *scene;

	scene = (t_scene *) param;
	if (keycode == ESC_KEY)
	{
		exit(0);
	}
	else if (keycode == KEY_RIGHT)
	{
		scene->camera.yaw += 3.0;
		update_camera_vectors_dir(&scene->camera);
		update_camera_vectors(&scene->camera);
		render_scene(scene);
	}
	else if (keycode == KEY_LEFT)
	{
		scene->camera.yaw -= 3.0;
		update_camera_vectors_dir(&scene->camera);
		update_camera_vectors(&scene->camera);
		render_scene(scene);
	}
	else if (keycode == KEY_UP)
	{
		scene->camera.pitch += 3.0;
		if (scene->camera.pitch > 89.0)
			scene->camera.pitch = 89.0;
		update_camera_vectors_dir(&scene->camera);
		update_camera_vectors(&scene->camera);
		render_scene(scene);
	}
	else if (keycode == KEY_DOWN)
	{
		scene->camera.pitch -= 3.0;
		if (scene->camera.pitch < -89.0)
			scene->camera.pitch = -89.0;
		update_camera_vectors_dir(&scene->camera);
		update_camera_vectors(&scene->camera);
		render_scene(scene);
	}
	else if (keycode == KEY_W)
	{
		scene->camera.origin = vec_add(scene->camera.origin,
		                               vec_mul(scene->camera.direction, MOVE_SPEED));
		render_scene(scene);
	}
	else if (keycode == KEY_S)
	{
		scene->camera.origin = vec_sub(scene->camera.origin,
		                               vec_mul(scene->camera.direction, MOVE_SPEED));
		render_scene(scene);
	}
	else if (keycode == KEY_D)
	{
		scene->camera.origin = vec_add(scene->camera.origin,
		                               vec_mul(scene->camera.right, MOVE_SPEED));
		render_scene(scene);
	}
	else if (keycode == KEY_A)
	{
		scene->camera.origin = vec_sub(scene->camera.origin,
		                               vec_mul(scene->camera.right, MOVE_SPEED));
		render_scene(scene);
	}
	return (0);
}

/**
 * The main function, what do you expect?
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return A status code, 0 if successful and 1 if it fails.
 */
int main(const int argc, char **argv)
{
	t_scene scene;

	if (argc != 2)
		error_throw(ERROR_SYNTAX);
	if (init_parse(&scene, argv[1]))
		error_throw(ERROR_INIT_PARSE);
	if (create_scene(argv[1], &scene))
		error_throw(ERROR_INIT_SCENE);
	render_scene(&scene);
	mlx_hook(scene.win_ptr, 17, 0, close_window, &scene);
	mlx_key_hook(scene.win_ptr, key_press, &scene);
	mlx_loop(scene.mlx_ptr);
	return (0);
}
