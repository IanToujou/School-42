
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_hashclear.c >                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Clears a hash table completely.
 *
 * @param table The table to clear.
 */
void	ft_hashclear(t_hashtable *table)
{
	int					i;
	struct s_hashnode	*node;
	struct s_hashnode	*temp;

	i = 0;
	while (i < table->size)
	{
		node = table->table[i];
		while (node != NULL)
		{
			temp = node;
			node = node->next;
			free(temp->key);
			free(temp);
		}
		i++;
	}
	free(table->table);
	free(table);
}
