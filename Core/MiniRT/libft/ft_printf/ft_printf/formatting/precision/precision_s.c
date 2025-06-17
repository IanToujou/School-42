/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:23:53 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/28 16:11:29 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*precision_s(char *str, t_format *format)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(str);
	if (format->precision < 0 || format->precision >= len)
		return (ft_strdup(str));
	new_str = ft_calloc(format->precision + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, str, format->precision);
	return (new_str);
}
