/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:40:19 by ibour             #+#    #+#             */
/*   Updated: 2024/12/17 09:44:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	check_for_chars(const char c, const int signs)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	if ((c == '-' || c == '+') && signs)
		return (1);
	return (0);
}

static int	ft_atoi_base_error(const char *base)
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

static int	ft_atoi_base_test(const char str, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_atoi_base_search(const char *str, int *i)
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

int	ft_atoi_base(const char *str, const char *base)
{
	int		i;
	int		mult;
	int		nb;
	int		temp;
	int		len;

	nb = 0;
	i = 0;
	len = ft_atoi_base_error(base);
	if (len >= 2)
	{
		mult = ft_atoi_base_search(str, &i);
		temp = ft_atoi_base_test(str[i], base);
		while (temp != -1)
		{
			nb = (nb * len) + temp;
			i++;
			temp = ft_atoi_base_test(str[i], base);
		}
		return (nb * mult);
	}
	return (0);
}
