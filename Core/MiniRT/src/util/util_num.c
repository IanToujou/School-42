/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:44:10 by ibour             #+#    #+#             */
/*   Updated: 2025/06/19 14:19:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

double	util_num_parse(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	decimal = 0.0;
	sign = 1;
	i = 0;
	if (!str || str[0] == 0 || (!ft_isdigit(str[0]) && str[0] != '-' && str[0] != '+'))
		error_throw(ERROR_PARSE_NUM);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		double factor = 0.1;
		while (str[i] && ft_isdigit(str[i]))
		{
			decimal += (str[i++] - '0') * factor;
			factor *= 0.1;
		}
	}
	if (str[i] != '\0')
		error_throw(ERROR_PARSE_NUM);
	return ((result + decimal) * sign);
}
