/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:15:58 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/18 17:01:59 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	other_toupper(unsigned int i, char *c)
{
	(void)i;
	*c = (char)ft_toupper((int)*c);
}

int	print_cx(unsigned int nbr, t_format *format)
{
	char	*str;
	int		num_char;
	char	*new_str;

	str = ft_itoa_base(nbr, 16);
	if (!str)
		return (0);
	ft_striteri(str, other_toupper);
	new_str = apply_flags(str, format, 'X');
	if (!new_str)
		return (0);
	num_char = ft_strlen(new_str);
	write(1, new_str, num_char);
	free(new_str);
	return (num_char);
}
