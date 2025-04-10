/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:09 by ibour             #+#    #+#             */
/*   Updated: 2024/12/09 09:27:03 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

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
		ft_printf("The syntax is not correct.\033[0m\n");
		ft_printf("Usage: ./fractol <fractal>\n");
		ft_printf("(1) mandelbrot\n");
		ft_printf("(2) julia\n");
		ft_printf("(3) burning_ship\n");
		ft_printf("(4) tricorn\n");
		ft_printf("(5) celtic_mandelbar");
	}
	else if (error == ERROR_INIT_MLX)
		ft_printf("Error initializing MLX.");
	else if (error == ERROR_INIT_WINDOW)
		ft_printf("Error initializing window.");
	ft_printf("\033[0m\n");
	exit(EXIT_FAILURE);
}
