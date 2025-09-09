/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:27:12 by ibour             #+#    #+#             */
/*   Updated: 2025/09/09 14:52:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/gg_collect.h"

/**
 * Frees everything allocated inside the garbage collector's cache
 * and sets the pointers to NULL. You cannot continue using other
 * features after freeing everything.
 *
 * @param data The main garbage data struct.
 */
void	gg_free_all(t_gg_data *data)
{
	t_gg_node	*current;
	t_gg_node	*next;

	if (!data)
		return ;
	current = data->head;
	while (current)
	{
		next = current->next;
		free(current->ptr);
		free(current);
		current = next;
	}
	data->head = NULL;
	data->alloc_count = 0;
	data->size = 0;
	free(data);
}

/**
 * Frees up previously allocated memory and sets the pointers to NULL.
 * This method is safe in most cases and will simply not do anything when
 * trying to free up unallocated space.
 *
 * @param data The main garbage data struct.
 * @param ptr The pointer to free.
 */
void	gg_free(t_gg_data *data, void *ptr)
{
	t_gg_node	*current;
	t_gg_node	*prev;

	if (!data || !ptr)
		return ;
	current = data->head;
	prev = NULL;
	while (current && current->ptr != ptr)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (prev)
		prev->next = current->next;
	else
		data->head = current->next;
	data->alloc_count--;
	data->size -= current->size;
	free(current->ptr);
	free(current);
}
