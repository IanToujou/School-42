/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <ibour@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:42:26 by ibour             #+#    #+#             */
/*   Updated: 2024/10/25 15:24:25 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
	size_t	s_len;
	size_t	t_len;

	if (!*to_find)
		return ((char *)s);
	if (n == 0)
		return (NULL);
	s_len = ft_strlen(s);
	t_len = ft_strlen(to_find);
	if (t_len > s_len)
		n = s_len;
	while (*s && n >= t_len)
	{
		if (ft_strncmp(s, to_find, t_len) == 0)
			return ((char *)s);
		s++;
		n--;
	}
	return (NULL);
}
