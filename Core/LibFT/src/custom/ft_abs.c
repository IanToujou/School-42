/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:53:45 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 01:56:53 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Takes in a double and returns its absolute
 * value.
 *
 * @param x The double to process.
 * @return The absolute value.
 */
double	ft_abs(const double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
