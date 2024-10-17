/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_memset.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Fills a certain space in memory up with the value c, starting
 * from s, and up to n characters.
 *
 * @param s The starting destination in the memory.
 * @param c The character, or number, that will fill.
 * @param n How many bytes should be filled.
 * @return A pointer to the starting destination.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((t_byte *)s)[n] = (t_byte) c;
	return (s);
}
