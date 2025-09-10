/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:26:28 by ibour             #+#    #+#             */
/*   Updated: 2025/09/09 14:39:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gg_collect.h"

/**
 * Allocates memory of any size. It works very similarly to malloc.
 * On failure, it returns NULL. Never free allocated memory using the
 * default free function when allocating memory with gg_malloc. You
 * should use gg_free or gg_free_all.
 *
 * @param data The main garbage data struct.
 * @param size The size of memory to allocate.
 * @return A pointer to the newly allocated memory.
 */
void	*gg_malloc(t_gg_data *data, const size_t size)
{
	t_gg_node	*node;
	void		*ptr;

	if (!data || size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	node = malloc(sizeof(t_gg_node));
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
	return (ptr);
}

/**
 * Works similarly to calloc, allocating size times count memory and
 * returning a new pointer to it. On failure, it returns NULL.
 *
 * @param data The main garbage data struct.
 * @param count The count of memory to allocate.
 * @param size The size of memory to allocate.
 *
 * @return A pointer to the newly allocated memory.
 */
void	*gg_calloc(t_gg_data *data, const size_t count, const size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t	i;

	if (!data || count == 0 || size == 0)
		return (NULL);
	total_size = count * size;
	ptr = gg_malloc(data, total_size);
	if (ptr)
	{
		i = 0;
		while (i < total_size)
			((char *)ptr)[i++] = 0;
	}
	return (ptr);
}

/**
 * Reallocates memory for a pointer. It works similarly to realloc.
 * On failure, it returns NULL.
 *
 * @param data The main garbage data struct.
 * @param ptr The pointer to reallocate.
 * @param new_size A pointer to the newly allocated memory.
 * @return
 */
void	*gg_realloc(t_gg_data *data, void *ptr, const size_t new_size)
{
	void		*new_ptr;
	t_gg_node	*current;

	if (!data)
		return (NULL);
	if (!ptr)
		return (gg_malloc(data, new_size));
	if (new_size == 0)
	{
		gg_free(data, ptr);
		return (NULL);
	}
	current = data->head;
	while (current && current->ptr != ptr)
		current = current->next;
	if (!current)
		return (NULL);
	new_ptr = realloc(ptr, new_size);
	if (!new_ptr)
		return (NULL);
	data->size -= current->size;
	data->size += new_size;
	current->ptr = new_ptr;
	current->size = new_size;
	return (new_ptr);
}
