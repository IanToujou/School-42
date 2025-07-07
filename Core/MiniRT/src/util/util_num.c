/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:44:10 by ibour             #+#    #+#             */
/*   Updated: 2025/07/07 17:58:53 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	validate_and_get_sign(char *str, int *i)
{
	int	sign;

	if (!str || str[0] == 0 || (!ft_isdigit(str[0])
			&& str[0] != '-' && str[0] != '+'))
		error_throw(ERROR_PARSE_NUM);
	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

static double	parse_integer_part(char *str, int *i)
{
	double	result;

	result = 0.0;
	while (str[*i] && ft_isdigit(str[*i]))
		result = result * 10.0 + (str[(*i)++] - '0');
	return (result);
}

static double	parse_decimal_part(char *str, int *i)
{
	double	decimal;
	double	factor;

	decimal = 0.0;
	if (str[*i] == '.')
	{
		(*i)++;
		factor = 0.1;
		while (str[*i] && ft_isdigit(str[*i]))
		{
			decimal += (str[(*i)++] - '0') * factor;
			factor *= 0.1;
		}
	}
	return (decimal);
}

double	util_num_parse(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	i = 0;
	sign = validate_and_get_sign(str, &i);
	result = parse_integer_part(str, &i);
	decimal = parse_decimal_part(str, &i);
	return ((result + decimal) * sign);
}
