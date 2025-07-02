/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:10:47 by ibour             #+#    #+#             */
/*   Updated: 2025/07/02 09:42:34 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	init_parse_check_file(const char *file_name)
{
	size_t	length;

	length = ft_strlen(file_name);
	return (length > 3 && !ft_strcmp(file_name + length - 3, ".rt"));
}

static void	init_parse_line(t_scene *scene, const char *line)
{
	char **array;

	if (line[0] == 0 || line[0] == '\n')
		error_throw(ERROR_INIT_PARSE);
	array = ft_split(line, ' ');
	if (!array)
		error_throw(ERROR_MALLOC);
	if (!ft_strcmp("A", array[0]))
		parse_ambient(scene, array);
	else if (!ft_strcmp("C", array[0]))
		parse_camera(scene, array);
	else if (!ft_strcmp("pl", array[0]))
		parse_plane(scene, array);
	else if (!ft_strcmp("sp", array[0]))
		parse_sphere(scene, array);
	else if (!ft_strcmp("L", array[0]))
		parse_spotlight(scene, array);
	else if (!ft_strcmp("cy", array[0]))
		parse_cylinder(scene, array);
	else
		error_throw(ERROR_INIT_PARSE);
	util_array_free((void**)array);
	array = NULL;
}

void init_parse(t_scene *scene, const char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || !init_parse_check_file(file_name))
		error_throw(ERROR_FILE_INVALID);
	line = get_next_line(fd);
	if (!line)
		error_throw(ERROR_FILE_EMPTY);
	while (line != NULL)
	{
		if (line[0] != '\n')
			init_parse_line(scene, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}