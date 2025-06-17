/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:00:09 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/25 16:03:23 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static char	*apply_precision(char *str, t_format *format, char specifier)
{
	if (specifier == 'd' || specifier == 'i')
		return (precision_d(str, format));
	else if (specifier == 'u')
		return (precision_u(str, format));
	else if (specifier == 'x')
		return (precision_x(str, format));
	else if (specifier == 'X')
		return (precision_cx(str, format));
	else if (specifier == 's')
		return (precision_s(str, format));
	else
		return (ft_strdup(str));
}

static char	*apply_space_flag(char *str, t_format *format, char specifier)
{
	char	*tmp;

	if (format->flags & FLAG_SPACE && !(format->flags & FLAG_PLUS)
		&& (specifier == 'd' || specifier == 'i' || specifier == 'u'))
	{
		if (str[0] != '-' && str[0] != '+')
		{
			tmp = str;
			str = (char *)malloc(ft_strlen(tmp) + 2);
			if (!str)
				return (NULL);
			str[0] = ' ';
			ft_strlcpy(str + 1, tmp, ft_strlen(tmp) + 1);
		}
	}
	return (str);
}

static char	*apply_plus_flag(char *str, t_format *format, char specifier)
{
	char	*tmp;

	if (format->flags & FLAG_PLUS && (specifier == 'd' || specifier == 'i'
			|| specifier == 'u'))
	{
		if (str[0] != '-' && str[0] != '+')
		{
			tmp = str;
			str = (char *)malloc(ft_strlen(tmp) + 2);
			if (!str)
				return (NULL);
			str[0] = '+';
			ft_strlcpy(str + 1, tmp, ft_strlen(tmp) + 1);
		}
	}
	return (str);
}

static void	malloc_check(char *str, char *new_str)
{
	if (new_str != str)
		free(str);
}

char	*apply_flags(char *str, t_format *format, char specifier)
{
	char	*new_str;

	new_str = apply_precision(str, format, specifier);
	malloc_check(str, new_str);
	str = new_str;
	new_str = add_prefix(str, specifier);
	malloc_check(str, new_str);
	str = new_str;
	new_str = apply_space_flag(str, format, specifier);
	malloc_check(str, new_str);
	str = new_str;
	new_str = apply_plus_flag(str, format, specifier);
	malloc_check(str, new_str);
	str = new_str;
	new_str = apply_hash_flag(str, format, specifier);
	malloc_check(str, new_str);
	str = new_str;
	new_str = apply_width_and_padding(str, format, specifier);
	malloc_check(str, new_str);
	return (new_str);
}
