/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_striter.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Applies a given function f to every character
 * in a specified string, s.
 *
 * @param s The string to apply the function to.
 * @param f The function that should be applied to
 * every character in the string.
 */
void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(&s[i]);
		i++;
	}
}
