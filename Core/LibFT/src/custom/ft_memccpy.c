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

#include "../../include/libft.h"

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
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;
	unsigned char		ch;

	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	ch = (unsigned char) c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == ch)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
