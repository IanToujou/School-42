/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:10:11 by ibour             #+#    #+#             */
/*   Updated: 2025/01/15 07:40:17 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int main(const int argc, char **argv) {
	t_data	*data;

	if (ft_util_validate_args(argc) == -1)
		ft_throw_error(ERROR_SYNTAX);
	if (ft_util_validate_num(argv) == -1)
		ft_throw_error(ERROR_SYNTAX_NUM);
	if (ft_util_validate_limits(argv) == -1)
		ft_throw_error(ERROR_SYNTAX_LIMIT);
	if (ft_init_data(&data, argv) == -1)
		ft_throw_error(ERROR_INIT_DATA);
	// Start program
	// Free data
	return (0);
}
