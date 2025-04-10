/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:34:40 by ibour             #+#    #+#             */
/*   Updated: 2024/10/30 20:11:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Deletes a key-value pair from a hash table.
 *
 * @param table The table to delete the pair from.
 * @param key The key assigned to the value to delete.
 */
void	ft_hashdel(t_hashtable *table, const char *key)
{
	unsigned int	index;
	t_hashnode		*node;
	t_hashnode		*prev;

	index = ft_hashcode(key, table->size);
	node = table->table[index];
	prev = NULL;
	while (node != NULL && ft_strcmp(node->key, key) != 0)
	{
		prev = node;
		node = node->next;
	}
	if (node == NULL)
		return ;
	if (prev == NULL)
		table->table[index] = node->next;
	else
		prev->next = node->next;
	free(node->key);
	free(node);
}
