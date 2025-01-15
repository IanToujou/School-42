/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:59:40 by ibour             #+#    #+#             */
/*   Updated: 2025/01/15 13:10:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	ft_util_validate_limits(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_util_atol(argv[i]) > INT_MAX || ft_util_atol(argv[i]) < INT_MIN)
			return (-1);
	}
	return (0);
}

int	ft_util_validate_num(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (ft_util_str_is_num(argv[i]) == -1) return (-1);
	return (0);
}

int	ft_util_validate_args(const int argc)
{
	if (argc < 5 || argc > 6)
		return (-1);
	return (0);
}
