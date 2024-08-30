/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_pow.c >                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calculates a number x to the power of y,
 * by using exponentiation by squaring in a
 * recursive call chain.
 *
 * It supports the type double as a base, and
 * negative powers. However, fractional powers
 * are not supported.
 *
 * @param x The base to elevate.
 * @param y To the power of.
 * @return The result of the calculation.
 */
double ft_pow(double x, int y)
{
	if (y < 0)
		return ft_pow(1/x, -y);
	else if (y == 0)
		return (1);
	else if (y % 2 == 0)
		return ft_pow(x * x, y / 2);
	else
		return x * ft_pow(x * x, (y - 1) / 2);
}
