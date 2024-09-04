/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_hashnew.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Creates a new hash table of a given size.
 *
 * @param size The total size of the table.
 * @return The newly created hash table.
 */
t_hashtable	*ft_hashnew(int size)
{
	int 		i;

	i = 0;
	t_hashtable	*table = (t_hashtable *) malloc(sizeof(t_hashtable));
	if (!table)
		return (NULL);
	table->size = size;
	table->table = (t_hashnode **) malloc(sizeof(t_hashnode) * size);
	if (!table->table)
		return (NULL);
	while (i < size)
	{
		table->table[i] = NULL;
		i++;
	}
	return (table);
}