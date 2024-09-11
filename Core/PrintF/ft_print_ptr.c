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

#include <stdio.h>

#include "ft_printf.h"

void	ft_print_ptr(void *ptr, int *i)
{
	char 			*str;
	unsigned long	addr;

	addr = (long long) ptr;
	ft_print_str("0x", i);
	str = ft_num_base(addr, HEX_LOW_BASE);
	ft_print_str(str, i);
	free(str);
}