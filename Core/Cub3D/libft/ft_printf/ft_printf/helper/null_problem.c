/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_problem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:23:07 by mpoesy            #+#    #+#             */
/*   Updated: 2024/12/05 16:12:32 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	loop(int incr, int max)
{
	int	num;

	num = 0;
	while (incr > max)
	{
		num += write(1, " ", 1);
		incr--;
	}
	return (num);
}

int	i_dont_get_why_its_like_this(t_format *format, char specifier)
{
	int		num;
	char	*new_str;

	num = 0;
	if (specifier == 's')
		new_str = "(null)";
	else
		new_str = "(nil)";
	if (format->precision < ft_strlen(new_str))
	{
		num += loop(format->width, 0);
		return (num);
	}
	if (format->flags & FLAG_MINUS)
	{
		num += write(1, new_str, ft_strlen(new_str));
		num += loop(format->width, ft_strlen(new_str));
	}
	else
	{
		num += loop(format->width, ft_strlen(new_str));
		num += write(1, new_str, ft_strlen(new_str));
	}
	return (num);
}
