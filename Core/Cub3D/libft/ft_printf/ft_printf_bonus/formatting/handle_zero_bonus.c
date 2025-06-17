/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:51:47 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/25 11:19:27 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static int	write_padding(int width, char pad_char)
{
	int	num_char;

	num_char = 0;
	while (num_char < width)
	{
		write(1, &pad_char, 1);
		num_char++;
	}
	return (num_char);
}

int	handle_zero(t_format *format)
{
	int		width;
	int		num_char;
	char	pad_char;

	num_char = 0;
	if (format->width > 0)
		width = format->width;
	else
		width = 1;
	if (format->flags & FLAG_MINUS)
	{
		write(1, "\0", 1);
		num_char += 1 + write_padding(width - 1, ' ');
	}
	else
	{
		if (format->flags & FLAG_ZERO)
			pad_char = '0';
		else
			pad_char = ' ';
		num_char += write_padding(width - 1, pad_char);
		write(1, "\0", 1);
		num_char++;
	}
	return (num_char);
}
