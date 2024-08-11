/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_memalloc.c >                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *
 * Allocates a specific amount of memory and
 * initializes it to zero.
 *
 * @param size The amount of memory to allocate.
 * @return A pointer to the newly allocated block.
 */
void	*ft_memalloc(size_t size)
{
	void*	result;

	result = malloc(sizeof(size_t) * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size);
	return (result);
}