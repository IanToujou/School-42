/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_print_nbr.c >                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:31:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/31 23:31:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int num, int *i)
{
	if (num == -2147483648)
	{
		ft_print_nbr((num / 10), i);
		ft_print_char('8', i);
	}
	else if (num < 0)
	{
		ft_print_char('-', i);
		ft_print_nbr(-num, i);
	}
	else
	{
		if (num > 9)
			ft_print_nbr((num / 10), i);
		ft_print_char((char)('0' + num % 10), i);
	}
}
