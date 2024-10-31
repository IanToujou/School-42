/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < ft_printf.c >                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:31:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/31 23:31:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_process(va_list args, char *str, int *i)
{
	if (*str == 'c')
		ft_print_char(va_arg(args, int), i);
	else if (*str == 's')
		ft_print_str(va_arg(args, char *), i);
	else if (*str == 'p')
		ft_print_ptr(va_arg(args, void *), i);
	else if (*str == 'i' || *str == 'd')
		ft_print_num(va_arg(args, int), i);
	else if (*str == 'u')
		ft_print_num_unsigned(va_arg(args, unsigned int), i);
	else if (*str == 'x')
		ft_print_hex(va_arg(args, unsigned int), i, HEX_LOW_BASE);
	else if (*str == 'X')
		ft_print_hex(va_arg(args, unsigned int), i, HEX_UPP_BASE);
	else if (*str == '%')
		ft_print_char(*str, i);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_process(args, (char *) str, &i);
		}
		else
			ft_print_char(*str, &i);
		str++;
	}
	va_end(args);
	return (i);
}
