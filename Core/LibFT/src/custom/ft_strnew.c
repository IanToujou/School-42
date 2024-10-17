/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strnew.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Allocates space for a new string at a given size
 * and initializes every character to '\0'.
 *
 * @param size The size of the string.
 * @return A pointer to the newly created string.
 */
char	*ft_strnew(size_t size)
{
	char	*s;

	s = (char *) ft_calloc(size + 1, 1);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
