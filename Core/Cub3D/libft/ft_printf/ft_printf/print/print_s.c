/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:43:24 by mpoesy            #+#    #+#             */
/*   Updated: 2024/12/05 15:58:16 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_null_string(t_format *format)
{
	char	*new_str;

	if ((format->iswidthsetup == 1 && format->width > 6)
		|| format->precision < 6)
		return (i_dont_get_why_its_like_this(format, 's'));
	else
	{
		new_str = "(null)";
		return (write(1, new_str, 6));
	}
}

int	print_s(char *str, t_format *format)
{
	int		num_char;
	char	*new_str;
	char	*test;

	if (!str)
	{
		return (handle_null_string(format));
	}
	test = ft_strdup(str);
	new_str = apply_flags(test, format, 's');
	if (!new_str)
	{
		free(new_str);
		return (0);
	}
	num_char = ft_strlen(new_str);
	write(1, new_str, num_char);
	free(new_str);
	return (num_char);
}
