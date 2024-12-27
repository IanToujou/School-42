/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:24:42 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 01:46:19 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int main(const int argc, char **argv) {
	int			fd;
	t_map		*map;
	t_coord_val	*coords;
	t_data		*data;

	coords = NULL;
	if (argc != 2)
		ft_throw_error(ERROR_SYNTAX);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_throw_error(ERROR_FILE);
	map = ft_init_map();
	if (read_map(fd, &coords, map) == -1)
		ft_throw_error(ERROR_MAP_INVALID);
	data = ft_init_data(map);
	ft_util_stack_to_array(&coords, map);
	data->camera = ft_init_camera(data);
	ft_graphics_draw(data->map, data);
	setup_controls(data);
	mlx_loop(data->mlx);
	return (0);
}
