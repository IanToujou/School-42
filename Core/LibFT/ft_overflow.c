/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_overflow.c >                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates 128 bytes of memory in an infinite loop.
 * In other words, fills up your memory until the
 * machine crashes.
 */
void	ft_overflow()
{
	int *ptr;
	while (1)
	{
		ptr = malloc(128);
		if (!ptr) break;
	}
	free(ptr);
}