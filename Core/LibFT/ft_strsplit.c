/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strsplit.c >                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char c)
{
	int		i;
	int		indicator;
	int		words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		indicator = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			indicator = 1;
			i++;
		}
		while (str[i] == c && str[i] != '\0')
			i++;
		if (indicator == 1)
			words++;
	}
	return (words);
}

static int	new_str(char const *str, char c)
{
	int		i;

	i = 0;
	while (str[i] == c && str[i] != '\0')
		str++;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static char	**split(char **array, char const *s, char c, int count)
{
	char	*str;
	int		key;
	int		i;

	i = 0;
	key = 0;
	while (key < count)
	{
		str = (char *)malloc(sizeof(char) * (new_str(s, c) + 1));
		if (str == NULL)
			return (NULL);
		while (s[0] == c && s[0] != '\0')
			s++;
		while (s[0] != c && s[0] != '\0')
			str[i++] = *s++;
		str[i] = '\0';
		array[key++] = str;
		i = 0;
	}
	array[count] = 0;
	return (array);
}

/**
 * Returns a fresh array with string split by a given
 * delimiter in a given string. For example, if the string
 * is delimited by * and it is "hello*world*!", it will
 * return an array containing ["hello", "world", "!"].
 *
 * @param s The given string to split.
 * @param c A character serving as a delimiter.
 * @return A fresh array of strings.
 */
char	**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**array;

	if (s == NULL)
		return (NULL);
	count = word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
		return (NULL);
	array = split(array, s, c, count);
	return (array);
}
