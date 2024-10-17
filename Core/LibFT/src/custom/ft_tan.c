/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_tan.c >                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 23:59:32 by ibour             #+#    #+#             */
/*   Updated: 2024/09/28 23:59:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Calculates the tangent value of a given angle.
 * The input angle needs to be in radians.
 *
 * @param x The angle to perform the calculation on.
 * @return The result of the calculation.
 */
double	ft_tan(int x)
{
	return (ft_sin(x) / ft_cos(x));
}
