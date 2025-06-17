/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:08:52 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/19 11:08:26 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// Max : base 16
char	*ft_itoa_base(size_t num, int base)
{
	char	*str;
	char	*digits;
	int		len;
	size_t	n;

	digits = "0123456789abcdef";
	len = 1;
	n = num;
	while (n >= (size_t)base)
	{
		len++;
		n /= base;
	}
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = digits[num % base];
		num /= base;
	}
	return (str);
}
