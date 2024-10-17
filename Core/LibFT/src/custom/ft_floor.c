/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_floor.c >                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Takes in a double and rounds it down to the
 * nearest full integer. Supports both positive
 * and negative numbers.
 *
 * @param x The double to process.
 * @return The down-rounded number.
 */
double	ft_floor(double x)
{
	long long	n;
	double		d;

	n = (long long) x;
	d = (double) n;
	if (d == x || x >= 0)
		return (d);
	return (d - 1);
}
