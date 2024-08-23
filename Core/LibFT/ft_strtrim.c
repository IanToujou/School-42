/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strtrim.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Trims a string by removing any whitespaces at
 * the beginning or at the end and returning a
 * new string.
 *
 * @param s The string to trim.
 * @return A new string that is trimmed.
 */
char	*ft_strtrim(char const *s)
{
	size_t	i;

	if (!s)
		return (NULL);
	while (*s && ft_strchr(" \n\t", *s))
		s++;
	i = ft_strlen(s);
	while (i && ft_strchr(" \n\t", s[i]))
		i--;
	return (ft_strsub(s, 0, i + 1));
}
