/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errortype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:12:16 by ibour             #+#    #+#             */
/*   Updated: 2025/07/15 09:45:57 by ibour            ###   ########.fr       */
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

# define ERROR_INIT_MLX 6
# define ERROR_INIT_MLX_MSG "MLX initialization failed."

# define ERROR_FILE_INVALID 7
# define ERROR_FILE_INVALID_MSG "File not found or invalid."

# define ERROR_FILE_EMPTY 8
# define ERROR_FILE_EMPTY_MSG "File is empty."

# define ERROR_PARSE_NUM 9
# define ERROR_PARSE_NUM_MSG "Failed to parse number."

# define ERROR_PARSE_COLOR 10
# define ERROR_PARSE_COLOR_MSG "Failed to parse color."

# define ERROR_PARSE_VECTOR 11
# define ERROR_PARSE_VECTOR_MSG "Failed to parse vector."

# define ERROR_PARSE_AMBIENT 12
# define ERROR_PARSE_AMBIENT_MSG "Failed to parse ambient light."

# define ERROR_PARSE_CAMERA 13
# define ERROR_PARSE_CAMERA_MSG "Failed to parse camera."

# define ERROR_PARSE_SPOTLIGHT 14
# define ERROR_PARSE_SPOTLIGHT_MSG "Failed to parse spotlight."

# define ERROR_PARSE_PLANE 15
# define ERROR_PARSE_PLANE_MSG "Failed to parse plane."

# define ERROR_PARSE_SPHERE 16
# define ERROR_PARSE_SPHERE_MSG "Failed to parse sphere."

# define ERROR_PARSE_CYLINDER 17
# define ERROR_PARSE_CYLINDER_MSG "Failed to parse cylinder."

# define ERROR_RENDER_AMBIENT_RATIO 18
# define ERROR_RENDER_AMBIENT_RATIO_MSG "Ambient ration cannot be 0."

# define ERROR_RENDER_SPHERE_RADIUS 19
# define ERROR_RENDER_SPHERE_RADIUS_MSG "Sphere radius cannot be 0."

# define ERROR_PARSE_CONE 20
# define ERROR_PARSE_CONE_MSG "Failed to parse cone."

void	error_throw(int error);

#endif
