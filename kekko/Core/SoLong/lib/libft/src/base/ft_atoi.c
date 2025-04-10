/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_atoi.c >                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * Converts a string into an integer number. This
 * function will skip any whitespace characters, then
 * process any + or - signs and convert the remaining
 * number until the string ends or at the first occurrence
 * of a non-numeric character.
 *
 * @param str The string to convert.
 * @return The number extracted from the string.
 */
int	ft_atoi(const char *str)
{
	int	n;
	int	s;

	n = 0;
	s = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			s *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * s);
}
