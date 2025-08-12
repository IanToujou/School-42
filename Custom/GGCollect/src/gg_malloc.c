/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:26:28 by ibour             #+#    #+#             */
/*   Updated: 2025/08/12 11:39:03 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gg_collect.h"

void	*gg_malloc(t_gg_data *data, const size_t size)
{
	if (!data || size == 0)
		return (NULL);
	void *ptr = malloc(size);
	if (!ptr)
		return (NULL);
	t_gg_node *node = malloc(sizeof(t_gg_node));
	if (!node)
	{
		free(ptr);
		return (NULL);
	}
	node->ptr = ptr;
	node->size = size;
	node->next = data->head;
	data->head = node;
	data->alloc_count++;
	data->size += size;
	return ptr;
}

void *gg_calloc(t_gg_data *data, const size_t count, const size_t size) {
	size_t	total_size;
	size_t	i;

	if (!data || count == 0 || size == 0)
		return (NULL);
	total_size = count * size;
	void *ptr = gg_malloc(data, total_size);
	if (ptr)
	{
		i = 0;
		while (i < total_size)
			((char*)ptr)[i++] = 0;
	}
	return (ptr);
}
