/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errortype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:12:16 by ibour             #+#    #+#             */
/*   Updated: 2025/09/10 18:18:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORTYPE_H

# define ERRORTYPE_H

# define ERROR_UNKNOWN 0
# define ERROR_UNKNOWN_MSG "Unknown error."

# define ERROR_SYNTAX 1
# define ERROR_SYNTAX_MSG "./fdf <map.fdf>"

# define ERROR_MALLOC 2
# define ERROR_MALLOC_MSG "Memory allocation error."

# define ERROR_INIT_DATA 3
# define ERROR_INIT_DATA_MSG "Data initialization failed."

# define ERROR_INIT_PARSE 4
# define ERROR_INIT_PARSE_MSG "Parsing initialization failed."

# define ERROR_INIT_MLX 5
# define ERROR_INIT_MLX_MSG "MLX initialization failed."

# define ERROR_FILE_INVALID 6
# define ERROR_FILE_INVALID_MSG "File not found or invalid."

# define ERROR_FILE_EMPTY 7
# define ERROR_FILE_EMPTY_MSG "File is empty."

# define ERROR_PARSE_NUM 8
# define ERROR_PARSE_NUM_MSG "Failed to parse number."

# define ERROR_RENDER_PROJECTION 9
# define ERROR_RENDER_PROJECTION_MSG "Failed to render projection."

# define ERROR_RENDER_IMAGE 10
# define ERROR_RENDER_IMAGE_MSG "Failed to render image."

void	error_throw(int error);

#endif
