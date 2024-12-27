/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 01:30:16 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 01:35:15 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_data		*ft_init_data(t_map *map)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_throw_error(ERROR_INIT_DATA);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_throw_error(ERROR_INIT_MLX);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	if (!data->win)
		ft_throw_error(ERROR_INIT_WINDOW);
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img)
		ft_throw_error(ERROR_INIT_WINDOW);
	data->data_addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
										&(data->size_line), &(data->endian));
	data->map = map;
	data->mouse = (t_mouse *) malloc(sizeof(t_mouse));
	if (!data->mouse)
		ft_throw_error(ERROR_INIT_WINDOW);
	return (data);
}
