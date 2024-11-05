/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:06:10 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 15:50:56 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Throws a given error and exits the program if
 * specified.
 *
 * @param error A custom error message to display.
 * @param exitProgram Whether the program should exit or not.
 */
void	ft_handle_error(char* error, const int exitProgram)
{
	ft_printf("Error: %s\n", error);
	if(exitProgram)
		exit(EXIT_FAILURE);
}