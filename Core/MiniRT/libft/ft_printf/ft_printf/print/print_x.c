/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:33:46 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/18 17:01:41 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_x(unsigned int nbr, t_format *format)
{
	char	*str;
	char	*new_str;
	int		num_char;

	str = ft_itoa_base(nbr, 16);
	if (!str)
		return (0);
	new_str = apply_flags(str, format, 'x');
	if (!new_str)
		return (0);
	num_char = ft_strlen(new_str);
	write(1, new_str, num_char);
	free(new_str);
	return (num_char);
}
