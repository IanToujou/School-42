/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strmap.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Processes a string with a given function and
 * maps the return values to a new string before
 * returning it.
 *
 * @param s The string to process.
 * @param f The function that will process the string.
 * @return A newly created string with the mapped
 * values.
 */
char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	i;

	result = ft_strnew(ft_strlen(s));
	if (s && f && result != NULL)
	{
		i = 0;
		while (s[i])
		{
			result[i] = f(s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
