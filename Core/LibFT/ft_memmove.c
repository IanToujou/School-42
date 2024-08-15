/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_memmove.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies n bytes from a source to a destination. It is
 * similar to memcpy, but it uses an intermediate buffer.
 *
 * @param dst The destination to copy to.
 * @param src The source to copy from.
 * @param s The amount of bytes to copy.
 * @return
 */
void	*ft_memmove(void *dst, void *src, size_t s)
{
	size_t	i;

	if (src < dst)
		ft_memcpy(dst, src, s);
	else
	{
		i = 0;
		while (i < s)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}