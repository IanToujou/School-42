/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:10:11 by ibour             #+#    #+#             */
/*   Updated: 2025/01/07 19:27:09 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

static int	ft_validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	// check if numbers
	// check out of bounds
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
