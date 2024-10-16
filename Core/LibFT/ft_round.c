/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_round.c >                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 23:59:32 by ibour             #+#    #+#             */
/*   Updated: 2024/09/28 23:59:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Rounds a number to the next integer.
 *
 * @param x The number to round.
 * @return The result of the operation.
 */
double	ft_round(int x)
{
	if (x >= 0)
	{
		if (x - ((int) x) >= 0.5)
		{
			return (((int) x) + 1);
		}
		else
		{
			return ((int) x);
		}
	}
	else
	{
		if (x - ((int) x) <= -0.5)
			return (((int) x) - 1);
		else
			return ((int) x);
	}
}
