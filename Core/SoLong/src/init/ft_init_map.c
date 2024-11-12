/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:22:29 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 12:06:38 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int ft_check_file_format(const char *file)
{
	int	fd;

	if (open(file, O_DIRECTORY) >= 0)
	{
		fd = open(file, O_DIRECTORY);
		close(fd);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	close(fd);
	if ((file[strlen(file) - 4] != '.' &&
		file[strlen(file) - 3] != 'b' &&
		file[strlen(file) - 2] != 'e' &&
		file[strlen(file) - 1] != 'r') || fd < 0)
			return (-1);
	return (0);
}

int	ft_init_map(t_gamedata *gamedata, char **argv)
{
	if(ft_check_file_format(argv[1]) < 0)
		ft_throw_error(ERROR_MAP_FILE_FORMAT);
	gamedata->map->amount_collectibles = 0;
	gamedata->map->amount_enemies = 0;
	gamedata->map->amount_players = 0;
	return (0);
}