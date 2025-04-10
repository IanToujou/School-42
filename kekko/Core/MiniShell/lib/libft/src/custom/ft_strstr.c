/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strstr.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Searches for a string inside another string.
 *
 * @param s The string to scan.
 * @param to_find The string to search for.
 * @return A pointer to the found string, or NULL if
 * not found.
 */
char	*ft_strstr(char *s, char *to_find)
{
	char	*haystack;
	char	*needle;

	if (*to_find == '\0')
		return (s);
	haystack = s;
	needle = to_find;
	while (true)
	{
		if (*needle == '\0')
			return (haystack - (needle - to_find));
		if (*haystack == *needle)
			needle++;
		else
			needle = to_find;
		if (*haystack == '\0')
			break ;
		haystack++;
	}
	return (NULL);
}
