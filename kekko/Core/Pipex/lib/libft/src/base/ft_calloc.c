/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <ibour@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:42:26 by ibour             #+#    #+#             */
/*   Updated: 2024/10/25 15:14:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Allocates a certain amount of memory and
 * initializes all the allocated bytes to zero.
 *
 * @param count The amount of blocks to allocate.
 * @param size The size to allocate.
 * @return A pointer to the whole allocated block.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
