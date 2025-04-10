/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashcode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:17:40 by ibour             #+#    #+#             */
/*   Updated: 2024/10/30 20:11:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Creates a hash value for a given key.
 *
 * @param key Any key
 * @param size The total size of the hash table.
 * @return The index of the element.
 */
unsigned int	ft_hashcode(const char *key, int size)
{
	unsigned long int	hash;
	size_t				i;

	hash = 0;
	i = 0;
	while (hash < ULONG_MAX && i < ft_strlen(key))
	{
		hash = hash * 31 + key[i];
		i++;
	}
	return (hash % size);
}
