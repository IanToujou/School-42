/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strncat.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Concatenates two string together, by adding the
 * src string to the destination. It is similar to
 * ft_strcat, but only concatenates up to a certain
 * amount of characters, defined by n.
 *
 * @param dst The destination to copy to.
 * @param src The source to copy from.
 * @param n The maximum amount of characters to copy.
 * @return A pointer to the destination string.
 */
char	*ft_strncat(char *dst, const char *src, unsigned int n)
{
	unsigned int	i1;
	unsigned int	i2;

	i1 = 0;
	i2 = 0;
	while (dst[i1] != '\0')
		i1++;
	while (src[i2] != '\0' && i2 < n)
	{
		dst[i1] = src[i2];
		i1++;
		i2++;
	}
	dst[i1] = '\0';
	return (dst);
}
