/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width_and_padding_two.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:16:16 by mpoesy            #+#    #+#             */
/*   Updated: 2024/12/02 17:11:51 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	calculate_length(char *str, char specifier)
{
	int	length;

	length = 0;
	if (!str)
		return (0);
	if (specifier == 'c' && *str == '\0')
		return (1);
	while (str[length] != '\0')
		length++;
	return (length);
}

void	compute_lengths(int len_str, int width, t_padding *pad)
{
	pad->padding_len = 0;
	pad->total_len = len_str;
	if (width > len_str)
	{
		pad->padding_len = width - len_str;
		pad->total_len = width;
	}
	pad->index = 0;
}

char	*allocate_result(char *str, int width, int total_len, int is_width_set)
{
	char	*result;

	if (width <= 0 || !is_width_set)
		return (ft_strdup(str));
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	ft_memset(result, ' ', total_len);
	return (result);
}

void	add_padding(char *final_str, t_padding *pad)
{
	while (pad->padding_len > 0)
	{
		final_str[pad->index++] = pad->pad_char;
		pad->padding_len--;
	}
}

void	copy_string(char *final_str, char *str, t_padding *pad)
{
	while (*str)
		final_str[pad->index++] = *str++;
}
