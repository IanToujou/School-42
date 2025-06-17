/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:06:41 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/19 11:57:26 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_u(unsigned int nbr, t_format *format)
{
	char	*str;
	char	*new_str;
	int		num_char;

	str = ft_utoa(nbr);
	if (!str)
		return (0);
	new_str = apply_flags(str, format, 'u');
	if (!new_str)
		return (0);
	num_char = ft_strlen(new_str);
	write(1, new_str, num_char);
	free(new_str);
	return (num_char);
}
