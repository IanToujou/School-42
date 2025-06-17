/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:29:08 by mpoesy            #+#    #+#             */
/*   Updated: 2024/12/06 14:13:27 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	is_zero_or_blank(char *str)
{
	while (*str)
	{
		if (*str != '0' && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

char	*apply_hash_flag(char *str, t_format *format, char specifier)
{
	char	*new_str;

	if (!(format->flags & FLAG_HASH))
		return (ft_strdup(str));
	if (is_zero_or_blank(str))
		return (ft_strdup(str));
	if (specifier == 'x')
	{
		new_str = ft_strjoin("0x", str);
		return (new_str);
	}
	else if (specifier == 'X')
	{
		new_str = ft_strjoin("0X", str);
		return (new_str);
	}
	return (str);
}
