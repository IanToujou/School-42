/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:54:55 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/20 07:15:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void init_window(t_scene *scene, int width, int height, char *title)
{
	printf("--- Initializing MiniLibX Window ---\n");
	scene->mlx_ptr = mlx_init();
	if (!scene->mlx_ptr)
	{
		perror("Error initializing mlx");
		exit(EXIT_FAILURE);
	}
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, width, height, title);
	if (!scene->win_ptr)
	{
		perror("Error creating window");
		exit(EXIT_FAILURE);
	}
	scene->image.img_ptr = mlx_new_image(scene->mlx_ptr, width, height);
	if (!scene->image.img_ptr)
	{
		perror("Error creating image");
		exit(EXIT_FAILURE);
	}
	scene->image.data = mlx_get_data_addr(scene->image.img_ptr,
	                                      &scene->image.bpp, &scene->image.line_length, &scene->image.endian);
}

int add_object_to_scene(t_scene *scene, const t_obj_type type, void *data)
{
	t_object *new_node;
	t_object *current;

	new_node = (t_object *) malloc(sizeof(t_object));
	if (!new_node)
		error_throw(ERROR_MALLOC);
	new_node->type = type;
	new_node->data = data;
	new_node->next = NULL;
	if (!scene->objects)
		scene->objects = new_node;
	else
	{
		current = scene->objects;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (0);
}

// Dummy version
// Would need to read and parse from the name of the file in the future
int create_scene(char *file, t_scene *scene)
{
	//t_sphere	*sphere;
	//t_plane		*plane;
	//t_cylinder	*cylinder;

	(void) file;
	//scene->camera.position.x = 0.0;
	//scene->camera.position.y = 0.0;
	//scene->camera.position.z = 6.0;
	//scene->camera.direction.x = 0.0;
	//scene->camera.direction.y = -1.0;
	//scene->camera.direction.z = 1.0;
	scene->camera.up = (t_vec3){0.0, 1.0, 0.0};
	scene->camera.forward = vec_normalize(scene->camera.direction);
	scene->camera.right = vec_normalize(vec_cross(scene->camera.forward,
	                                              scene->camera.up));
	// scene->camera.up = vec_normalize(vec_cross(scene->camera.right, scene->camera.forward));
	//scene->camera.fov = 70.0;
	/*
	scene->light.position.x = -10.0;
	scene->light.position.y = 10.0;
	scene->light.position.z = -10.0;
	scene->light.color.r = 255;
	scene->light.color.g = 255;
	scene->light.color.b = 255;
	scene->light.intensity = 0.7;
	*/
	scene->objects = NULL;
	/*
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
	{
		error("Failed to allocate memory for sphere.");
		return (-1);
	}
	sphere->center = (t_vec3){0.0, 0.0, 10.0};
	sphere->radius = 2.0;
	sphere->color = (t_color){255, 0, 0};
	printf("Created dummy sphere:\nCenter (%.1f,%.1f,%.1f)\nRadius %.1f\nColor R: %d - G: %d - B: %d\n\n", sphere->center.x,
		sphere->center.y, sphere->center.z, sphere->radius, sphere->color.r,
		sphere->color.g, sphere->color.b);
	if (add_object_to_scene(scene, OBJ_SPHERE, sphere) == -1)
		return (-1);
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
	{
		error("Failed to allocate memory for sphere.");
		return (-1);
	}
	sphere->center = (t_vec3){5.0, 0.0, 10.0};
	sphere->radius = 5.0;
	sphere->color = (t_color){0, 255, 0};
	if (add_object_to_scene(scene, OBJ_SPHERE, sphere) == -1)
		return (-1);
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
	{
		error("Failed to allocate memory for plane.");
		return (-1);
	}
	plane->point = (t_vec3){0.0, -2.0, 15.0};
	plane->normal = (t_vec3){0.0, 1.0, 0.0};
	plane->color = (t_color){0, 0, 255};
	printf("Created dummy plane:\nPoint (%.1f,%.1f,%.1f)\nNormal(% .1f, % .1f, % .1f)\nColor R: %d - G: %d - B: %d\n\n", plane->point.x,
		plane->point.y, plane->point.z, plane->normal.x, plane->normal.y,
		plane->normal.z, plane->color.r, plane->color.g, plane->color.b);
	if (add_object_to_scene(scene, OBJ_PLANE, plane) == -1)
		return (-1);
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
	{
		error("Failed to allocate memory for cylinder.");
		return (-1);
	}
	cylinder->point = (t_vec3){-3.0, -2.0, 12.0};            // base center
	cylinder->axis = vec_normalize((t_vec3){0.0, 1.0, 0.0}); // upright
	cylinder->radius = 1.0;
	cylinder->height = 6.0;
	cylinder->color = (t_color){255, 255, 0};
	printf("Created dummy cylinder:\nBase (%.1f,%.1f,%.1f)\nAxis (% .1f, % .1f, % .1f)\nRadius %.1f\nHeight %.1f\nColor R: %d - G: %d - B: %d\n\n",
		cylinder->point.x, cylinder->point.y, cylinder->point.z,
		cylinder->axis.x, cylinder->axis.y, cylinder->axis.z, cylinder->radius,
		cylinder->height, cylinder->color.r, cylinder->color.g,
		cylinder->color.b);
	if (add_object_to_scene(scene, OBJ_CYLINDER, cylinder) == -1)
		return (-1);
		*/
	// Create a box from 6 planes (each plane is a wall of the box)
	t_plane *planes[6];
	t_vec3 box_center = {0.0, 0.0, 10.0};
	double box_half_size = 5.0;
	t_color wall_color[6] = {
		{255, 0, 0}, // Front plane - Red
		{0, 255, 0}, // Back plane - Green
		{0, 0, 255}, // Left plane - Blue
		{255, 255, 0}, // Right plane - Yellow
		{255, 0, 255}, // Bottom plane - Magenta
		{0, 255, 255} // Top plane - Cyan
	};

	// Define planes for each side of the box
	// Each plane needs a point and a normal vector pointing inward

	// Front plane (facing toward -Z)
	planes[0] = (t_plane *) malloc(sizeof(t_plane));
	if (!planes[0]) return error("Failed to allocate memory for front plane.");
	planes[0]->point = (t_vec3){box_center.x, box_center.y, box_center.z - box_half_size};
	planes[0]->normal = (t_vec3){0.0, 0.0, 1.0};
	planes[0]->color = wall_color[0];

	// Back plane (facing toward +Z)
	planes[1] = (t_plane *) malloc(sizeof(t_plane));
	if (!planes[1]) return error("Failed to allocate memory for back plane.");
	planes[1]->point = (t_vec3){box_center.x, box_center.y, box_center.z + box_half_size};
	planes[1]->normal = (t_vec3){0.0, 0.0, -1.0};
	planes[1]->color = wall_color[1];

	// Left plane (facing toward +X)
	planes[2] = (t_plane *) malloc(sizeof(t_plane));
	if (!planes[2]) return error("Failed to allocate memory for left plane.");
	planes[2]->point = (t_vec3){box_center.x - box_half_size, box_center.y, box_center.z};
	planes[2]->normal = (t_vec3){1.0, 0.0, 0.0};
	planes[2]->color = wall_color[2];

	// Right plane (facing toward -X)
	planes[3] = (t_plane *) malloc(sizeof(t_plane));
	if (!planes[3]) return error("Failed to allocate memory for right plane.");
	planes[3]->point = (t_vec3){box_center.x + box_half_size, box_center.y, box_center.z};
	planes[3]->normal = (t_vec3){-1.0, 0.0, 0.0};
	planes[3]->color = wall_color[3];

	// Bottom plane (floor, facing up)
	planes[4] = (t_plane *) malloc(sizeof(t_plane));
	if (!planes[4]) return error("Failed to allocate memory for bottom plane.");
	planes[4]->point = (t_vec3){box_center.x, box_center.y - box_half_size, box_center.z};
	planes[4]->normal = (t_vec3){0.0, 1.0, 0.0};
	planes[4]->color = wall_color[4];

	// Top plane (ceiling, facing down)
	planes[5] = (t_plane *) malloc(sizeof(t_plane));
	if (!planes[5]) return error("Failed to allocate memory for top plane.");
	planes[5]->point = (t_vec3){box_center.x, box_center.y + box_half_size, box_center.z};
	planes[5]->normal = (t_vec3){0.0, -1.0, 0.0};
	planes[5]->color = wall_color[5];

	// Add all planes to the scene
	for (int i = 0; i < 6; i++)
	{
		if (add_object_to_scene(scene, OBJ_PLANE, planes[i]) == -1)
			return (-1);
	}
	// Sphere inside the box
	t_sphere *inner_sphere = (t_sphere *) malloc(sizeof(t_sphere));
	if (!inner_sphere) return error("Failed to allocate memory for inner sphere.");
	inner_sphere->center = (t_vec3){0.0, 0.0, 10.0};
	inner_sphere->radius = 1.5;
	inner_sphere->color = (t_color){255, 100, 100}; // Light red
	if (add_object_to_scene(scene, OBJ_SPHERE, inner_sphere) == -1)
		return (-1);

	// Cylinder inside the box
	t_cylinder *inner_cylinder = (t_cylinder *) malloc(sizeof(t_cylinder));
	if (!inner_cylinder) return error("Failed to allocate memory for inner cylinder.");
	inner_cylinder->point = (t_vec3){-2.0, -3.0, 10.0};
	inner_cylinder->axis = vec_normalize((t_vec3){0.0, 1.0, 0.0});
	inner_cylinder->radius = 0.8;
	inner_cylinder->height = 4.0;
	inner_cylinder->color = (t_color){100, 255, 100}; // Light green
	if (add_object_to_scene(scene, OBJ_CYLINDER, inner_cylinder) == -1)
		return (-1);
	// Example light source structure, assuming you have a similar struct
	scene->ambient.position = (t_vec3){-4.0, 4.0, 6.0};
	scene->ambient.ratio = 0.7; // You can adjust this
	scene->ambient.color = (t_color){255, 255, 255}; // White light
	//if (add_light_to_scene(scene, light) == -1)
	//  return (-1);

	return (0);
}
