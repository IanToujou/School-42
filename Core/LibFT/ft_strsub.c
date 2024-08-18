/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strsub.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies from a certain index, up to a maximum
 * length and creates a new sub-string.
 *
 * @param s The string to copy from.
 * @param start The index to start.
 * @param len The maximum length to copy.
 * @return A new string found in the provided string.
 */
char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;

	i = 0;
	result = (char*) malloc(sizeof(char) * (len + 1));
	if (result == NULL || s == NULL)
		return (NULL);
	while (i < (unsigned int) len)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}