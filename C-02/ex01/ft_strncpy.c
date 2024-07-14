/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strncpy.c >                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:00:41 by ibour             #+#    #+#             */
/*   Updated: 2024/07/13 16:20:22 by ibour            ###   ########.fr       */
/*                                                                            */
#include <stdio.h>

/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

/*int main() {
	char *src;
	char dest[0];

	src = "Hello World";
	printf("base: %s\n", src);
	printf("before copy: %s\n", dest);
	ft_strncpy(dest, src, 12);
	printf("after copy: %s\n", dest);
}*/