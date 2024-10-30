/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:17 by ibour             #+#    #+#             */
/*   Updated: 2024/10/30 20:12:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Creates a new hash table of a given size.
 *
 * @param size The total size of the table.
 * @return The newly created hash table.
 */
t_hashtable	*ft_hashnew(int size)
{
	t_hashtable	*table;
	int			i;

	i = 0;
	table = (t_hashtable *) malloc(sizeof(t_hashtable));
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
