/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_min.c >                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Compares two doubles, x and y, and returns
 * the smallest one of the two.
 *
 * @param x The first double.
 * @param y The second double.
 * @return The smaller double of the two.
 */
double	ft_min(double x, double y)
{
	if (x < y)
		return (x);
	else
		return (y);
}
