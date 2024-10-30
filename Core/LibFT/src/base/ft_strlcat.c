/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strlcat.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Concatenates two strings together and checks if there
 * is enough space in the memory.
 *
 * @param dst The destination to copy the string to.
 * @param src The source string to copy.
 * @param n The length of the string to append.
 * @return The total length of the string.
 */
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int n)
{
	char			*s;
	const char		*src_start;
	unsigned int	dst_length;
	unsigned int	remaining;

	s = dst;
	src_start = src;
	remaining = n;
	while (remaining-- != 0 && *s != '\0')
		s++;
	dst_length = s - dst;
	remaining = n - dst_length;
	if (remaining == 0)
		return (dst_length + ft_strlen(src));
	while (*src != '\0')
	{
		if (remaining > 1)
		{
			*s++ = *src;
			remaining--;
		}
		src++;
	}
	*s = '\0';
	return (dst_length + (src - src_start));
}
