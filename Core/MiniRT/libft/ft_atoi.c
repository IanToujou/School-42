/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:27:22 by mpoesy            #+#    #+#             */
/*   Updated: 2024/10/25 17:24:41 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate(const char *nptr, int sign)
{
	size_t	nb;
	int		digit;

	nb = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		digit = *nptr - '0';
		if (nb > (size_t)(-1) / 10 || (nb == (size_t)(-1) / 10 && digit > 7))
		{
			if (sign < 0)
				return (-2147483648);
			else
				return (2147483647);
		}
		nb = nb * 10 + digit;
		nptr++;
	}
	return (nb * sign);
}

int	ft_atoi(const char *nptr)
{
	int	sign;

	sign = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v')
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	return (calculate(nptr, sign));
}
