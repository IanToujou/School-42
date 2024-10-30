/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strdup.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Duplicates a string by allocating new memory for it.
 *
 * @param src The string to duplicate.
 * @return A pointer to the destination.
 */
char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(src) + 1;
	dst = (char *) malloc(size);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, src, size);
	return (dst);
}
