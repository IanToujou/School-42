/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < get_next_line_utils.c >                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
    while (n--)
        ((unsigned char *)s)[n] = (unsigned char) c;
    return (s);
}

void	ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
    void	*ptr;

    ptr = malloc(count * size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, count * size);
    return (ptr);
}
