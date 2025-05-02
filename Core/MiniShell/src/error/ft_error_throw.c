/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_throw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:05:21 by ibour             #+#    #+#             */
/*   Updated: 2025/03/26 12:33:22 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_error_message(const int error)
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
	else if (error == ERROR_INIT_ENV)
		printf(ERROR_INIT_ENV_MSG);
	else if (error == ERROR_INIT_TEMP)
		printf(ERROR_INIT_TEMP_MSG);
	else if (error == ERROR_INIT_STD)
		printf(ERROR_INIT_STD_MSG);
	else if (error == ERROR_EXIT_STD)
		printf(ERROR_EXIT_STD_MSG);
	printf("\033[0m\n");
}

/**
 * Handles error messages and exits the program with
 * the error status code.
 *
 * @param error The type of error that occurred.
 */
void	ft_error_throw(const int error)
{
	print_error_message(error);
	if (error == ERROR_FORK)
		printf(ERROR_FORK_MSG);
	else if (error == ERROR_GETCWD)
		printf(ERROR_GETCWD_MSG);
	else if (error == ERROR_DUP2)
		printf(ERROR_DUP2_MSG);
	else if (error == ERROR_OPEN)
		printf(ERROR_OPEN_MSG);
	else if (error == ERROR_CLOSE)
		printf(ERROR_CLOSE_MSG);
	else if (error == ERROR_PIPE)
		printf(ERROR_PIPE_MSG);
	printf("\033[0m\n");
	exit(EXIT_FAILURE);
}
