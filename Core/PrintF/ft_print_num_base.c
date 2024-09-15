/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_print_num_base.c >                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:31:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/31 23:31:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *str)
{
	int	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_print_num_base(unsigned long int p, char *base, int *i)
{
	int	length;

	length = ft_strlen(base);
	if (p / length)
		ft_print_num_base(p / length, base, i);
	ft_print_char(base[p % length], i);
}
