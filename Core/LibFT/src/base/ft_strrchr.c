/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strrchr.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Does the same as ft_strchr, and looks for a character
 * in a specified string. However, this function will not
 * look for the first occurence, but for the last.
 *
 * @param s The string to perform the search operation on.
 * @param c The character that should be searched for.
 * @return A pointer to the character that should be found.
 */
char	*ft_strrchr(const char *s, int c)
{
	char		*last;
	char		find;
	size_t		i;

	last = (char *)s;
	find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last[i] == find)
			return (last + i);
		i--;
	}
	if (last[i] == find)
		return (last);
	return (NULL);
}
