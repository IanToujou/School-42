/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:13:10 by mpoesy            #+#    #+#             */
/*   Updated: 2025/01/16 12:14:33 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	handle_sign(double *value, char *buffer, int *index, int max_chars)
{
	if (*value < 0)
	{
		*value = -*value;
		if (*index < max_chars)
		{
			buffer[(*index)++] = '-';
			return (1);
		}
	}
	return (0);
}

static void	convert_integer_part(long long int_part, char *buffer, int *index,
		int max_chars)
{
	char	temp_buffer[20];
	int		temp_index;

	temp_index = 0;
	if (int_part == 0)
	{
		if (*index < max_chars)
			buffer[(*index)++] = '0';
		return ;
	}
	while (int_part > 0)
	{
		temp_buffer[temp_index++] = (int_part % 10) + '0';
		int_part /= 10;
	}
	while (temp_index > 0 && *index < max_chars)
		buffer[(*index)++] = temp_buffer[--temp_index];
}

static void	convert_fractional_part(double frac_part, char *buffer, int *index,
		int max_chars)
{
	int	digit;

	if (*index < max_chars)
		buffer[(*index)++] = '.';
	while (frac_part > 0 && *index < max_chars)
	{
		frac_part *= 10;
		digit = (int)frac_part;
		buffer[(*index)++] = digit + '0';
		frac_part -= digit;
	}
}

void	ft_ftoa(double value, char *buffer, int max_chars)
{
	int			index;
	long long	int_part;
	double		frac_part;

	index = 0;
	if (max_chars > 10)
		max_chars = 10;
	handle_sign(&value, buffer, &index, max_chars);
	int_part = (long long)value;
	frac_part = value - int_part;
	convert_integer_part(int_part, buffer, &index, max_chars);
	if (index < max_chars - 1 && frac_part > 0)
		convert_fractional_part(frac_part, buffer, &index, max_chars);
	buffer[index] = '\0';
}
