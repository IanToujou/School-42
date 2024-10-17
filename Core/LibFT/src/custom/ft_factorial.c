/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_factorial.c >                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 23:59:32 by ibour             #+#    #+#             */
/*   Updated: 2024/09/28 23:59:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Calculates the factorial of a given number.
 *
 * @param x The number to perform the calculation on.
 * @return The result of the calculation.
 */
int	ft_factorial(int x)
{
	int	i;
	int	result;

	if (x < 0)
	{
		return (0);
	}
	i = 1;
	result = 1;
	while (i < x + 1)
	{
		result = result * i;
		i++;
	}
	return (result);
}
