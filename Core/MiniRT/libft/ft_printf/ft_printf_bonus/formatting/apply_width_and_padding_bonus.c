/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width_and_padding.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:08:13 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/22 16:10:40 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

static void	apply_left_padding(char *final_str, char *str, t_padding *pad)
{
	if (pad->pad_char == '0')
	{
		if (*str == '-' || *str == '+' || *str == ' ' || (*str == '0' && (*(str
						+ 1) == 'x' || *(str + 1) == 'X')))
		{
			if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
			{
				final_str[pad->index++] = *str++;
				final_str[pad->index++] = *str++;
			}
			else
			{
				final_str[pad->index++] = *str++;
			}
		}
		add_padding(final_str, pad);
	}
	else
	{
		add_padding(final_str, pad);
		if (*str == '-')
			final_str[pad->index++] = *(str)++;
	}
	copy_string(final_str, str, pad);
}

static void	apply_right_padding(char *final_str, char *str, t_padding *pad)
{
	copy_string(final_str, str, pad);
	add_padding(final_str, pad);
}

static char	determine_padding_char(t_format *format)
{
	if ((format->flags & FLAG_ZERO) && format->precision == (size_t)-1)
		return ('0');
	return (' ');
}

char	*apply_width_and_padding(char *str, t_format *format, char specifier)
{
	char		*final_str;
	int			len_str;
	t_padding	pad;

	len_str = calculate_length(str, specifier);
	compute_lengths(len_str, format->width, &pad);
	final_str = allocate_result(str, format->width, pad.total_len,
			format->iswidthsetup);
	if (!final_str)
		return (NULL);
	pad.pad_char = determine_padding_char(format);
	if (format->flags & FLAG_MINUS)
		apply_right_padding(final_str, str, &pad);
	else
		apply_left_padding(final_str, str, &pad);
	final_str[pad.total_len] = '\0';
	return (final_str);
}
