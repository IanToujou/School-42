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

static size_t	ft_isset(char str, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == str)
			return (1);
		i++;
	}
	return (0);
}

static char	*j_pos(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

/**
 * Trims a string by removing any characters in
 * the set at the beginning or at the end of the
 * string and returning a new string.
 *
 * @param s The string to trim.
 * @param set The charset to remove from the string.
 *
 * @return A new string that is trimmed.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	tmp;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_isset(s1[i], set) == 1)
		i++;
	j = ft_strlen(s1);
	if (j > 0)
		j--;
	while (j != 0 && ft_isset(s1[j], set) == 1)
		j--;
	if (j == 0 && ft_isset(s1[j], set) == 1)
		return (j_pos());
	str = (char *)malloc(sizeof(char) * ((j - i) + 2));
	if (!str)
		return (NULL);
	tmp = 0;
	while (i <= j)
		str[tmp++] = s1[i++];
	str[tmp] = '\0';
	return (str);
}
