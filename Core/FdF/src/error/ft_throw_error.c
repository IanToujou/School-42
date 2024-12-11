/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:09 by ibour             #+#    #+#             */
/*   Updated: 2024/12/11 17:31:06 by ibour            ###   ########.fr       */
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
		ft_printf("An unknown error occured.");
	else if (error == ERROR_SYNTAX)
	{
		ft_printf("The syntax is not correct.\n");
		ft_printf("Usage: ./fdf <map>");
	}
	else if (error == ERROR_INIT_MLX)
		ft_printf("Error initializing MLX.");
	else if (error == ERROR_INIT_WINDOW)
		ft_printf("Error initializing window.");
	ft_printf("\033[0m\n");
	exit(EXIT_FAILURE);
}
