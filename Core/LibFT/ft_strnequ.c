/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strnequ.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if two strings are equal up to n characters.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The maximum amount of characters to compare.
 * @return 1 if the strings are equal, 0 if not.
 */
int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2 && ft_strncmp(s1, s2, n) == 1)
		return (1);
	return (0);
}