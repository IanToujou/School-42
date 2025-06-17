/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:54:01 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/19 11:59:20 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	getlength(unsigned int n)
{
	int	length;

	if (n == 0)
		length = 1;
	else
		length = 0;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*str;

	len = getlength(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
