/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:09 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 01:22:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

/**
 * Handles error messages and exits the program with
 * the error status code.
 *
 * @param error The type of error that occurred.
 */
void	ft_throw_error(const int error)
{
	ft_printf("Error\n\033[31m");
	if (error == ERROR_UNKNOWN)
		ft_printf(ERROR_UNKNOWN_MSG);
	else if (error == ERROR_SYNTAX)
		ft_printf(ERROR_SYNTAX_MSG);
	else if (error == ERROR_MALLOC)
		ft_printf(ERROR_MALLOC_MSG);
	else if (error == ERROR_FILE)
		ft_printf(ERROR_FILE_MSG);
	else if (error == ERROR_INIT_MLX)
		ft_printf(ERROR_INIT_MLX_MSG);
	else if (error == ERROR_INIT_WINDOW)
		ft_printf(ERROR_INIT_WINDOW_MSG);
	else if (error == ERROR_INIT_DATA)
		ft_printf(ERROR_INIT_DATA_MSG);
	else if (error == ERROR_MAP_INVALID)
		ft_printf(ERROR_MAP_INVALID_MSG);
	else if (error == ERROR_MAP_FILE_EXTENSION)
		ft_printf(ERROR_MAP_FILE_EXTENSION_MSG);
	ft_printf("\033[0m\n");
	exit(EXIT_FAILURE);
}
