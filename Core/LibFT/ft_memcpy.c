/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_memcpy.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies n bytes of memory into a destination block.
 *
 * @param dst The destination of the copy.
 * @param src The source to copy.
 * @param n The amount of bytes to copy.
 * @return A pointer to the destination of the copy, if successful.
 */
void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t i;

	i = 0;
	if(!dst || !src)
		return (NULL);
	while(i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
}