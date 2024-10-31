/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_print_num.c >                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:31:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/31 23:31:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_num(int num, int *i)
{
	if (num == -2147483648)
	{
		ft_print_num((num / 10), i);
		ft_print_char('8', i);
	}
	else if (num < 0)
	{
		ft_print_char('-', i);
		ft_print_num(-num, i);
	}
	else
	{
		if (num > 9)
			ft_print_num((num / 10), i);
		ft_print_char((char)('0' + num % 10), i);
	}
}
