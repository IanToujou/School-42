/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:09 by ibour             #+#    #+#             */
/*   Updated: 2024/11/09 21:41:54 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_throw_error(const int error)
{
	ft_printf("\033[31mError: ");
	if (error == ERROR_SYNTAX)
	{
		ft_printf("The syntax is not correct.\n\033[0m");
		ft_printf("Usage: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	exit(EXIT_FAILURE);
}