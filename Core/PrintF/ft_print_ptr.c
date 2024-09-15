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

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putnum_base(unsigned long int p, char *base, int *i)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (p / base_len)
		ft_putnum_base(p / base_len, base, i);
	ft_print_char(base[p % base_len], i);
}

void	ft_print_ptr(void *ptr, int *i)
{
	unsigned long	p;

	p = (unsigned long) ptr;
	if (p)
	{
		ft_print_str("0x", i);
		ft_putnum_base(p, "0123456789abcdef", i);
	}
	else
		ft_print_str("(nil)", i);
}
