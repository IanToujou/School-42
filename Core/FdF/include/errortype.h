/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errortype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:12:16 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 02:58:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORTYPE_H

# define ERRORTYPE_H

# define ERROR_UNKNOWN 0
# define ERROR_UNKNOWN_MSG "Unknown error."

# define ERROR_SYNTAX 1
# define ERROR_SYNTAX_MSG "Syntax error. Usage: ./fdf <map>"

# define ERROR_MALLOC 2
# define ERROR_MALLOC_MSG "Memory allocation error."

# define ERROR_FILE 3
# define ERROR_FILE_MSG "Failed to open file."

# define ERROR_ARRAY_CONVERSION 4
# define ERROR_ARRAY_CONVERSION_MSG "Failed to convert array."

# define ERROR_INIT_MLX 5
# define ERROR_INIT_MLX_MSG "MLX initialization failed."

# define ERROR_INIT_WINDOW 6
# define ERROR_INIT_WINDOW_MSG "Window initialization failed."

# define ERROR_INIT_DATA 7
# define ERROR_INIT_DATA_MSG "Data initialization failed."

# define ERROR_INIT_CAMERA 8
# define ERROR_INIT_CAMERA_MSG "Camera initialization failed."

# define ERROR_MAP_INVALID 9
# define ERROR_MAP_INVALID_MSG "The given map is invalid."

# define ERROR_MAP_FILE_EXTENSION 10
# define ERROR_MAP_FILE_EXTENSION_MSG "The file extension needs to be fdf."

#endif
