/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:46:36 by ibour             #+#    #+#             */
/*   Updated: 2025/09/23 13:13:00 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	init_parse(t_data *data, const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(data);
		error_throw(ERROR_FILE_INVALID);
		return ;
	}
	data->map.depth = util_map_parse_depth(fd);
	data->map.width = util_map_parse_width(file);
	close(fd);
	if (data->map.depth <= 0 || data->map.width <= 0)
	{
		free(data);
		error_throw(ERROR_FILE_INVALID);
		return ;
	}
	init_map_array(data);
	init_map_read(data, file);
}
