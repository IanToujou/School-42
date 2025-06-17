/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:53:37 by mpoesy            #+#    #+#             */
/*   Updated: 2024/12/04 14:54:35 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_d(int nbr, t_format *format)
{
	char	*str;
	char	*new_str;
	int		num_char;

	str = ft_itoa(nbr);
	if (!str)
	{
		if ((format->iswidthsetup == 1 && format->width > 6)
			|| format->precision < 6)
			return (i_dont_get_why_its_like_this(format, 'd'));
		else
		{
			str = "(nil)";
			return (write(1, str, 5));
		}
	}
	new_str = apply_flags(str, format, 'd');
	if (!new_str)
		return (0);
	num_char = ft_strlen(new_str);
	write(1, new_str, num_char);
	free(new_str);
	return (num_char);
}
