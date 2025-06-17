/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:14:11 by mpoesy            #+#    #+#             */
/*   Updated: 2024/10/25 09:52:11 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	taille_dest;
	size_t	taille_src;
	size_t	i;

	taille_src = ft_strlen(src);
	if (size == 0 && dest == NULL)
		return (taille_src);
	taille_dest = ft_strlen(dest);
	if (size <= taille_dest)
		return (taille_src + size);
	i = 0;
	while ((taille_dest + i < size - 1) && src[i] != '\0')
	{
		dest[taille_dest + i] = src[i];
		i++;
	}
	dest[taille_dest + i] = '\0';
	return (taille_dest + taille_src);
}
