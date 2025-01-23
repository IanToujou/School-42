/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:10:11 by ibour             #+#    #+#             */
/*   Updated: 2025/01/23 09:02:54 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/**
 * Dawg this is the main function what do you expect it to do?
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return The status code in case this fragile baby fucks up.
 */
int main(const int argc, char **argv) {
	t_data	data;

	if (ft_util_validate_args(argc) == -1)
		ft_throw_error(ERROR_SYNTAX);
	if (ft_util_validate_num(argv) == -1)
		ft_throw_error(ERROR_SYNTAX_NUM);
	if (ft_util_validate_limits(argv) == -1)
		ft_throw_error(ERROR_SYNTAX_LIMIT);
	if (ft_init_data(&data, argv) == -1)
		ft_throw_error(ERROR_INIT_DATA);
	ft_init_thread_main(&data);
	ft_init_monitoring(&data);
	ft_init_join(&data);
	ft_util_free(&data);
	return (0);
}
