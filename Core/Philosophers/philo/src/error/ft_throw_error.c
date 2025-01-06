/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:31:54 by ibour             #+#    #+#             */
/*   Updated: 2025/01/06 08:42:06 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/**
 * Handles error messages and exits the program with
 * the error status code.
 *
 * @param error The type of error that occurred.
 */
void	ft_throw_error(const int error)
{
	printf("Error\n\033[31m");
	if (error == ERROR_UNKNOWN)
		printf(ERROR_UNKNOWN_MSG);
	else if (error == ERROR_SYNTAX)
		printf(ERROR_SYNTAX_MSG);
	else if (error == ERROR_MALLOC)
		printf(ERROR_MALLOC_MSG);
	else if (error == ERROR_INIT_DATA)
		printf(ERROR_INIT_DATA_MSG);
	printf("\033[0m\n");
	exit(EXIT_FAILURE);
}
