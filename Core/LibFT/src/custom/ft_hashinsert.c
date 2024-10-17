/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_hashinsert.c >                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Inserts a key-value pair to the hash table.
 *
 * @param table The table to add the pair to.
 * @param key The key to add.
 * @param value The value assigned to the key.
 */
void	ft_hashinsert(t_hashtable *table, const char *key, int value)
{
	unsigned int	index;
	t_hashnode		*node;

	index = ft_hashcode(key, table->size);
	node = (t_hashnode *) malloc(sizeof(t_hashnode));
	if (!node)
		return ;
	node->key = ft_strdup(key);
	node->value = value;
	node->next = table->table[index];
	table->table[index] = node;
}