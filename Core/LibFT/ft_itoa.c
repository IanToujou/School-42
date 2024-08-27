/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_itoa.c >                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t	size;

	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	size_t	size;

	num = n;
	size = get_size(n);
	if (n < 0)
		num *= -1;
	result = (char *) malloc(size + 1);
	if (!result)
		return (NULL);
	*(result + size--) = '\0';
	while (num > 0)
	{
		*(result + size--) = (num % 10) + '0';
		num /= 10;
	}
	if (size == 0 && result[1] == '\0')
		*(result + size) = '0';
	else if (size == 0 && result[1])
		*(result + size) = '-';
	return (result);
}