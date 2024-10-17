/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_cos.c >                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 23:59:32 by ibour             #+#    #+#             */
/*   Updated: 2024/09/28 23:59:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Calculates the cosine value of a given angle.
 * The input angle needs to be in radians.
 *
 * @param x The angle to perform the calculation on.
 * @return The result of the calculation.
 */
double	ft_cos(double x)
{
	double	result;
	int		sign;
	int		i;
	int		exponent;

	result = 0;
	sign = 1;
	i = 0;
	while (i < 10)
	{
		exponent = 2 * i;
		result += sign * (ft_pow(x, exponent) / ft_factorial(exponent));
		sign *= -1;
		i++;
	}
	return (result);
}
