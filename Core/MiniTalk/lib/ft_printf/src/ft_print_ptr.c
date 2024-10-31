/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_print_ptr.c >                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:31:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/31 23:31:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_ptr(void *ptr, int *i)
{
	unsigned long	p;

	p = (unsigned long) ptr;
	if (p)
	{
		ft_print_str("0x", i);
		ft_print_num_base(p, "0123456789abcdef", i);
	}
	else
		ft_print_str("(nil)", i);
}
