/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_memccpy.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies n bytes of memory into a destination block, either
 * until the character c is found, or if n bytes are reached.
 *
 * If c is encountered, it will copy it too and return a pointer
 * to the next byte after the character c.
 *
 * @param dst The destination of the copy.
 * @param src The source to copy.
 * @param c The character to encounter.
 * @param n The amount of bytes to copy.
 * @return A pointer to the next character after c, if encountered,
 * or if not, simply returns NULL.
 */
void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == c)
			return (src + i + 1);
		i++;
	}
	return (NULL);
}
