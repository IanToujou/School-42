/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:33:48 by ibour             #+#    #+#             */
/*   Updated: 2024/10/30 20:11:02 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
