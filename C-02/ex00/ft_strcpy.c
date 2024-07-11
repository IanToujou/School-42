/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_strlen.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 07:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/07/11 07:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	c;
	int	index;

	index = 0;
	while (true)
	{
		c = src[index];
		if (c == '\0')
		{
			dest[index] = '\0';
			break ;
		}
		dest[index] = c;
		index++;
	}
	return (dest);
}
