/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:09 by ibour             #+#    #+#             */
/*   Updated: 2024/11/11 08:44:14 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/**
 * Handles error messages and exits the program with
 * the error status code.
 *
 * @param error The type of error that occurred.
 */
void	ft_throw_error(const int error)
{
	ft_printf("\033[31mError: ");
	if (error == ERROR_UNKNOWN)
		ft_printf("An unknown error occured.\033[0m\n");
	else if (error == ERROR_SYNTAX)
	{
		ft_printf("The syntax is not correct.\033[0m\n");
		ft_printf("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	else if (error == ERROR_PIPE)
		ft_printf("Failed to build a pipe. Call a plumber.\033[0m\n");
	else if (error == ERROR_FORK)
		ft_printf("Failed to create a fork. Maybe try a spoon?");
	else if (error == ERROR_FILE)
		ft_printf("Could not open the file.");
	else if (error == ERROR_PATH)
		ft_printf("Could not find the path.");
	else if (error == ERROR_EXECUTE)
		ft_printf("Could not execute the process.");
	exit(EXIT_FAILURE);
}
