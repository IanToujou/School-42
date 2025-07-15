/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_throw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:05:21 by ibour             #+#    #+#             */
/*   Updated: 2025/07/15 09:46:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static void	print_basic_errors(const int error)
{
	if (error == ERROR_UNKNOWN)
		printf(ERROR_UNKNOWN_MSG);
	else if (error == ERROR_SYNTAX)
		printf(ERROR_SYNTAX_MSG);
	else if (error == ERROR_MALLOC)
		printf(ERROR_MALLOC_MSG);
	else if (error == ERROR_INIT_DATA)
		printf(ERROR_INIT_DATA_MSG);
	else if (error == ERROR_INIT_PARSE)
		printf(ERROR_INIT_PARSE_MSG);
	else if (error == ERROR_INIT_SCENE)
		printf(ERROR_INIT_SCENE_MSG);
	else if (error == ERROR_FILE_INVALID)
		printf(ERROR_FILE_INVALID_MSG);
	else if (error == ERROR_FILE_EMPTY)
		printf(ERROR_FILE_EMPTY_MSG);
}

static void	print_parse_errors(const int error)
{
	if (error == ERROR_PARSE_NUM)
		printf(ERROR_PARSE_NUM_MSG);
	else if (error == ERROR_PARSE_COLOR)
		printf(ERROR_PARSE_COLOR_MSG);
	else if (error == ERROR_PARSE_VECTOR)
		printf(ERROR_PARSE_VECTOR_MSG);
	else if (error == ERROR_PARSE_AMBIENT)
		printf(ERROR_PARSE_AMBIENT_MSG);
	else if (error == ERROR_PARSE_CAMERA)
		printf(ERROR_PARSE_CAMERA_MSG);
	else if (error == ERROR_PARSE_SPOTLIGHT)
		printf(ERROR_PARSE_SPOTLIGHT_MSG);
	else if (error == ERROR_PARSE_CONE)
		printf(ERROR_PARSE_CONE_MSG);
}

static void	print_object_errors(const int error)
{
	if (error == ERROR_PARSE_PLANE)
		printf(ERROR_PARSE_PLANE_MSG);
	else if (error == ERROR_PARSE_SPHERE)
		printf(ERROR_PARSE_SPHERE_MSG);
	else if (error == ERROR_PARSE_CYLINDER)
		printf(ERROR_PARSE_CYLINDER_MSG);
	else if (error == ERROR_RENDER_AMBIENT_RATIO)
		printf(ERROR_RENDER_AMBIENT_RATIO_MSG);
}

static void	print_error_message(const int error)
{
	printf("Error\n\033[31m");
	print_basic_errors(error);
	print_parse_errors(error);
	print_object_errors(error);
	printf("\033[0m\n");
}

/**
 * Handles error messages and exits the program with
 * the error status code.
 *
 * @param error The type of error that occurred.
 */
__attribute__((noreturn))
void	error_throw(const int error)
{
	print_error_message(error);
	exit(EXIT_FAILURE);
}
