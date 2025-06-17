/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:23:02 by mpoesy            #+#    #+#             */
/*   Updated: 2024/12/04 15:35:47 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*precision_d(char *str, t_format *format)
{
	size_t	len;
	char	*new_str;
	int		is_negative;

	len = ft_strlen(str);
	is_negative = (str[0] == '-');
	if (format->precision == 0 && str[0] == '0' && str[1] == '\0')
		return (ft_strdup(""));
	if (format->precision == (size_t)-1 || format->precision <= len
		- is_negative)
		return (ft_strdup(str));
	if (format->precision > 2147483648)
		return (NULL);
	new_str = ft_calloc(format->precision + is_negative + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	if (is_negative)
		new_str[0] = '-';
	ft_memset(new_str + is_negative, '0', format->precision - (len
			- is_negative));
	ft_memcpy(new_str + format->precision - (len - is_negative) + is_negative,
		str + is_negative, len - is_negative);
	return (new_str);
}
