/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:54:55 by mpoesy            #+#    #+#             */
/*   Updated: 2025/06/20 13:36:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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
