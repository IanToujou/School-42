/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:29:05 by ibour             #+#    #+#             */
/*   Updated: 2024/07/26 17:29:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	check_for_chars(char c, bool check_signs)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (true);
	if (c == '\r' || c == '\t' || c == '\v')
		return (true);
	if ((c == '-' || c == '+') && check_signs)
		return (true);
	return (false);
}

int	ft_atoi_base_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (check_for_chars(base[i], true))
			return (0);
		i++;
	}
	return (i);
}

int	ft_atoi_base_test(char str, char *base)
{
	int	retour;
	int	i;

	retour = 0;
	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base_search(char *str, int *i)
{
	int	mult;

	mult = 1;
	while (check_for_chars(str[*i], false))
		*i += 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			mult *= -1;
		*i += 1;
	}
	return (mult);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		mult;
	int		nb;
	int		tmp;
	int		len;

	nb = 0;
	i = 0;
	len = ft_atoi_base_error(base);
	if (len >= 2)
	{
		mult = ft_atoi_base_search(str, &i);
		tmp = ft_atoi_base_test(str[i], base);
		while (tmp != -1)
		{
			nb = (nb * len) + tmp;
			i++;
			tmp = ft_atoi_base_test(str[i], base);
		}
		return (nb *= mult);
	}
	return (0);
}
