/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_hashdel.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (node != NULL && ft_strcmp(node->key, key) != 0) {
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