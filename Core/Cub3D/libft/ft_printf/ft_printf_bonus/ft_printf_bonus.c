/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:04:04 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/25 16:23:44 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_char(const char **str, va_list args, t_format *format)
{
	int	num_char;

	num_char = 0;
	if (**str == 'c')
		num_char = print_c(va_arg(args, int), format);
	else if (**str == 's')
		num_char = print_s(va_arg(args, char *), format);
	else if (**str == 'p')
		num_char = print_p(va_arg(args, void *), format);
	else if (**str == 'd' || **str == 'i')
		num_char = print_d(va_arg(args, int), format);
	else if (**str == 'u')
		num_char = print_u(va_arg(args, unsigned int), format);
	else if (**str == 'x')
		num_char = print_x(va_arg(args, unsigned int), format);
	else if (**str == 'X')
		num_char = print_cx(va_arg(args, unsigned int), format);
	else if (**str == '%')
		num_char = print_prc();
	return (num_char);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			num_char;
	t_format	format;

	num_char = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			format = parse_format(&str);
			num_char += check_char(&str, args, &format);
		}
		else
		{
			write(1, str, 1);
			num_char++;
		}
		str++;
	}
	va_end(args);
	return (num_char);
}
/*
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = ft_printf("%.1s%.2s%.3s%.4s\n", " - ", "", "4", "");
	b = printf("%.1s%.2s%.3s%.4s\n", " - ", "", "4", "");
	printf("%d ,%d\n",a,b);
	return (0);
}
*/
