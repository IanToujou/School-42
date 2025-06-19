/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errortype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:12:16 by ibour             #+#    #+#             */
/*   Updated: 2025/06/19 12:32:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORTYPE_H

# define ERRORTYPE_H

# define ERROR_UNKNOWN 0
# define ERROR_UNKNOWN_MSG "Unknown error."

# define ERROR_SYNTAX 1
# define ERROR_SYNTAX_MSG "./minirt <scene.rt>"

# define ERROR_MALLOC 2
# define ERROR_MALLOC_MSG "Memory allocation error."

# define ERROR_INIT_DATA 3
# define ERROR_INIT_DATA_MSG "Data initialization failed."

# define ERROR_INIT_PARSE 4
# define ERROR_INIT_PARSE_MSG "Parsing initialization failed."

# define ERROR_INIT_SCENE 5
# define ERROR_INIT_SCENE_MSG "Scene initialization failed."

# define ERROR_FILE_INVALID 5
# define ERROR_FILE_INVALID_MSG "File not found or invalid."

# define ERROR_FILE_EMPTY 5
# define ERROR_FILE_EMPTY_MSG "File is empty."

void	error_throw(int error);

#endif
