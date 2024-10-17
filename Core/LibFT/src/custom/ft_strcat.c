/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strcat.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Concatenates two string together, by adding the
 * src string to the destination.
 *
 * @param dst The destination to copy to.
 * @param src The source to copy from.
 * @return A pointer to the first character of the
 * destination.
 */
char	*ft_strcat(char *dst, char *src)
{
	char	*result;

	result = dst;
	while (*result != '\0')
	{
		result++;
	}
	while (*src != '\0')
	{
		*(unsigned char *) result = *(unsigned char *) src;
		result++;
		src++;
	}
	*result = '\0';
	return (dst);
}
