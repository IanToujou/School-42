/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:15:20 by mpoesy            #+#    #+#             */
/*   Updated: 2024/12/02 11:08:46 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	parse_precision(const char **str, int *flag)
{
	size_t	precision;

	precision = -1;
	if (**str == '.')
	{
		(*flag) |= FLAG_DOT;
		precision = 0;
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			precision = precision * 10 + (**str - '0');
			(*str)++;
		}
	}
	return (precision);
}
