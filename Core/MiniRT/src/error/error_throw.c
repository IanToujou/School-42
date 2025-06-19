/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_throw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:05:21 by ibour             #+#    #+#             */
/*   Updated: 2025/06/19 12:14:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void print_error_message(const int error)
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
}

/**
 * Handles error messages and exits the program with
 * the error status code.
 *
 * @param error The type of error that occurred.
 */
__attribute__((noreturn))
void error_throw(const int error)
{
	print_error_message(error);
	exit(EXIT_FAILURE);
}
