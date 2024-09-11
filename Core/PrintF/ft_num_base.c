/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_num_base.c >                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:31:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/31 23:31:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

static void	*ft_calloc(int number, int size)
{
	void	*dest;

	dest = malloc (number * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, number * size);
	return (dest);
}

static int	ft_strlen(const char *str)
{
	int	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

static int ft_numlen(unsigned long long n, char *base)
{
	int					length;
	unsigned long long	base_length;

	length = 1;
	base_length = ft_strlen(base);
	while (n >= base_length)
	{
		n /= base_length;
		length++;
	}
	return (length);
}

char	*ft_num_base(unsigned long long num, char *base)
{
	char	*str;
	int		length;
	int 	base_length;

	length = ft_numlen(num, base);
	base_length = ft_strlen(base);
	str = ft_calloc((length + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (length != 0) {
		length = length - 1;
		if (length == 0) break;
		str[length] = base[num % length];
		num /= base_length;
	}
	return (str);
}