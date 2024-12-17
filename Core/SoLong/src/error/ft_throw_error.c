/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:09 by ibour             #+#    #+#             */
/*   Updated: 2024/12/17 08:21:22 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * Only exists because of norminette.
 *
 * @param error The type of error that occurred.
 */
static void	ft_throw_error_sub(const int error)
{
	if (error == ERROR_MAP_OTHER)
		ft_printf("Invalid map format.");
	else if (error == ERROR_MAP_FILE_FORMAT)
		ft_printf("Invalid map format. Required type is .ber");
	else if (error == ERROR_MAP_PLAYER)
		ft_printf("There has to be one player present on the map.");
	else if (error == ERROR_MAP_EDGES)
		ft_printf("The map edges are not aligned correctly.");
	else if (error == ERROR_MAP_RECTANGLE)
		ft_printf("The map is not a rectangle.");
	else if (error == ERROR_MAP_CHARACTERS)
		ft_printf("Invalid characters in the map.");
	else if (error == ERROR_FILE)
		ft_printf("Map file not found.");
}

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
		ft_printf("Usage: ./so_long <map>");
	}
	else if (error == ERROR_INIT_DATA)
		ft_printf("Initialization process failed: Memory allocation.");
	else if (error == ERROR_INIT_MLX)
		ft_printf("Initialization process failed: MLX library.");
	else if (error == ERROR_INIT_HOOKS)
		ft_printf("Initialization process failed: MLX hooks.");
	else if (error == ERROR_INIT_MAP)
		ft_printf("Initialization process failed: Map initialization.");
	else if (error == ERROR_INIT_GRAPHICS)
		ft_printf("Initialization process failed: Loading images.");
	ft_throw_error_sub(error);
	ft_printf("\033[0m\n");
	exit(EXIT_FAILURE);
}

void	ft_throw_and_free(t_gamedata *gamedata, const int error, int map)
{
	if (map == 1)
		ft_exit_map(gamedata->map->map);
	free(gamedata->str_quest);
	free(gamedata->str_collected);
	free(gamedata->str_moves);
	free(gamedata->str_collected_part);
	free(gamedata->str_moves_part);
	free(gamedata->player);
	free(gamedata->map);
	free(gamedata);
	ft_throw_error(error);
}
