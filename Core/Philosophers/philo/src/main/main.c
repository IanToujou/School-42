/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:10:11 by ibour             #+#    #+#             */
/*   Updated: 2025/01/13 22:53:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static int	ft_validate_limits(char **argv)
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

static int	ft_validate_num(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (!ft_util_str_isnum(argv[i])) return (-1);
	return (0);
}

static int	ft_validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	if (ft_validate_num(argv) == -1)
		return (-1);
	if (ft_validate_limits(argv) == -1)
		return (-1);
	return (0);
}

int main(const int argc, char **argv) {
	t_data	*data;

	if (ft_validate_args(argc, argv) == -1)
		ft_throw_error(ERROR_SYNTAX);
	if (ft_init_data(&data, argv) == -1)
		ft_throw_error(ERROR_INIT_DATA);
	// Start program
	// Free data
	return (0);
}
