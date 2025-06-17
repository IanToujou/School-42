/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:38:14 by mpoesy            #+#    #+#             */
/*   Updated: 2025/01/15 17:42:58 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*skip_whitespaces(const char *str)
{
	while (*str && ft_isspace(str))
	{
		str++;
	}
	return (str);
}

static int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
	{
		(*str)++;
	}
	return (sign);
}

static double	parse_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	while (**str && ft_isdigit((unsigned char)**str))
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

static double	parse_fractional_part(const char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str && ft_isdigit((unsigned char)**str))
		{
			fraction = fraction * 10.0 + (**str - '0');
			divisor *= 10.0;
			(*str)++;
		}
	}
	return (fraction / divisor);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	integer_part;
	double	fractional_part;

	str = skip_whitespaces(str);
	sign = parse_sign(&str);
	integer_part = parse_integer_part(&str);
	fractional_part = parse_fractional_part(&str);
	return (sign * (integer_part + fractional_part));
}
