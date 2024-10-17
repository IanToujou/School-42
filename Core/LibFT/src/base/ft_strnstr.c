/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strnstr.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Searches for a string inside another string, up to
 * a certain length.
 *
 * @param s The string to scan.
 * @param to_find The string to search for.
 * @param n The maximum length to check for.
 * @return A pointer to the found string, or NULL if
 * not found.
 */
char	*ft_strnstr(const char *s, const char *to_find, size_t n)
{
	unsigned int	pos;
	unsigned int	i;

	if (!*to_find)
		return ((char *)s);
	pos = 0;
	while (s[pos] && (size_t)pos < n)
	{
		if (s[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] && s[pos + i] == to_find[i]
				&& (size_t)(pos + i) < n)
				i++;
			if (to_find[i] == '\0')
				return ((char *)&s[pos]);
		}
		pos++;
	}
	return (NULL);
}
