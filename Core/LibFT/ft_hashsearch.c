/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_hashsearch.c >                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for a value in a hash table by using a
 * given key.
 *
 * @param table The table to search in.
 * @param key The key to look for.
 * @return The value associated with the key.
 */
int	ft_hashsearch(t_hashtable *table, const char *key)
{
	unsigned int	index;
	t_hashnode		*node;

	index = ft_hashcode(key, table->size);
	node = table->table[index];
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->next;

	if (node == NULL)
		return (-1);
	else
		return (node->value);
}