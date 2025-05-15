/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ggcollect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:58:13 by ibour             #+#    #+#             */
/*   Updated: 2025/05/15 07:34:34 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ggcollect.h"

void	*gg_malloc(const size_t size)
{
	t_gg_object *obj = (t_gg_object *) malloc(sizeof(t_gg_object) + size);
	obj->size = size;
	obj->marked = 0;
	obj->next = NULL;
	obj->data = (char *) obj + sizeof(t_gg_object);
	return (obj);
}

void gg_add_root(t_gg_data data, void* ptr) {
	if (data.root_count >= MAX_ROOTS)
		exit(1);
	data.roots[data.root_count++] = ptr;
}

void gg_mark(t_gg_object *obj)
{
	if (!obj || obj->marked) return;
	obj->marked = 1;
}

void gg_mark_all(const t_gg_data data)
{
	size_t	i;

	i = 0;
	while (i < data.root_count) {
		t_gg_object *obj = ((t_gg_object *) data.roots[i]) - 1;
		gg_mark(obj);
		i++;
	}
}

void gg_sweep(t_gg_data data) {
	t_gg_object** obj = &data.heap;
	while (*obj) {
		if (!(*obj)->marked) {
			t_gg_object* unreached = *obj;
			*obj = unreached->next;
			free(unreached);
		} else {
			(*obj)->marked = 0;
			obj = &((*obj)->next);
		}
	}
}

void gg_collect(const t_gg_data data)
{
	gg_mark_all(data);
	gg_sweep(data);
}

t_gg_data	gg_init()
{
	t_gg_data data;

	data.heap = NULL;
	data.root_count = 0;
	return (data);
}

void	gg_exit(const t_gg_data data)
{
	gg_collect(data);
}
