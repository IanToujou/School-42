/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_ceil.c >                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Takes in a double and rounds it up to the
 * nearest full integer. Supports both positive
 * and negative numbers.
 *
 * @param x The double to process.
 * @return The up-rounded number.
 */
double	ft_ceil(double x)
{
	if ((int) x == x)
		return (x);
	if (x > 0)
		return (int) x + 1;
	return (int) x;
}
