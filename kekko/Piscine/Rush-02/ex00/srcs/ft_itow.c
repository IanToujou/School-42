/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:15:24 by ibour             #+#    #+#             */
/*   Updated: 2024/07/27 14:15:25 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "../includes/ft_boolean.h"
#include "../includes/ft_io.h"
#include "../includes/ft_dictionary.h"
#include "../includes/ft_convert.h"

int	ft_res_dict_in(t_dict *dict, unsigned long number)
{
	int		index;

	index = 0;
	while (index < dict->size)
	{
		if (dict->entries[index].value == number)
			return (index);
		index++;
	}
	return (-1);
}

t_bool	ft_itow_is_value_power_of_ten(unsigned long number)
{
	unsigned long		power;

	power = 1;
	while (power <= number)
	{
		if (power == number)
			return (true);
		power *= 10;
	}
	return (false);
}

void	ft_itow_print_if(t_bool print, t_bool *put_space, char *str)
{
	if (!print)
		return ;
	if (*put_space)
		ft_putstr(1, " ");
	*put_space = true;
	ft_putstr(1, str);
}

t_bool	ft_itow_short(t_dict *dict, unsigned long n, t_bool *put_sp, t_bool b)
{
	int		dict_index;

	dict_index = ft_res_dict_in(dict, n);
	if (dict_index == -1)
		return (false);
	ft_itow_print_if(b, put_sp, dict->entries[dict_index].str);
	return (true);
}

t_bool	ft_itow(t_dict *dict, unsigned long n, t_bool *put_space, t_bool b)
{
	int				size;
	int				divisor;
	int				i;
	unsigned long	*d;

	if ((n <= 20 && ft_itow_short(dict, n, 0, false))
		|| (ft_res_dict_in(dict, n) != -1
			&& !ft_itow_is_value_power_of_ten(n)))
		return (ft_itow_short(dict, n, put_space, b));
	size = snprintf(NULL, 0, "%lu", n);
	d = malloc(size * sizeof(unsigned long));
	divisor = 1;
	i = 0;
	while (i < size)
	{
		d[size - 1 - i] = (n / divisor) % 10 * divisor;
		divisor *= 10;
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (d[i] != 0)
		{
			if (ft_res_dict_in(dict, d[i]) != -1)
				ft_itow_short(dict, d[i], put_space, b);
			else
			{
				if (d[i] >= 10000 && ft_res_dict_in(dict, d[i]) == -1)
				{
					ft_itow(dict, d[i] / 1000, put_space, b);
					ft_itow_short(dict, d[i] / f_dig(d[i]), put_space, b);
				}
				else
				{
					ft_itow_short(dict, f_dig(d[i]), put_space, b);
					ft_itow_short(dict, d[i] / f_dig(d[i]), put_space, b);
				}
			}
		}
		i++;
	}
	free(d);
	return (true);
}
