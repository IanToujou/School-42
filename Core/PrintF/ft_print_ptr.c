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

#include "ft_printf.h"

static char	hex_digit(const int v) {
	if (v >= 0 && v < 10)
		return ('0' + v);
	return ('a' + v - 10);
}

static void	address_hex(void *ptr, char **addr)
{
	int			index;
	int			jndex;
	long long	p;

	p = (long long) ptr;
	if (!ptr)
	{
		*addr = (char *) malloc(sizeof(char) * 3);
		(*addr)[0] = '0';
		(*addr)[1] = 'x';
		(*addr)[2] = '0';
		return ;
	}
	*addr = (char *) malloc(sizeof(char) * 15);
	(*addr)[14] = '\0';
	(*addr)[0] = '0';
	(*addr)[1] = 'x';
	index = ((sizeof(p) << 3) - 4 * 5);
	jndex = 2;
	while (jndex < 14)
	{
		(*addr)[jndex] = hex_digit((p >> index) & 0xf);
		index -= 4;
		jndex++;
	}
}

void	ft_print_ptr(void *ptr, int *i)
{
	char	*addr;

	address_hex(ptr, &addr);
	ft_print_str(addr, i);
	free(addr);
}