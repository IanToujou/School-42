/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:09:41 by ibour             #+#    #+#             */
/*   Updated: 2024/11/07 13:54:50 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	ft_init_sub(const t_data *data)
{
	char	*relative_path;
	int		width;
	int		height;

	relative_path = "./assets/waltuh.xpm";
	data->image->player_right = mlx_xpm_file_to_image(data->mlx, relative_path,
			&width, &height);
	relative_path = "./assets/meth.xpm";
	data->image->background = mlx_xpm_file_to_image(data->mlx, relative_path,
			&width, &height);
}

void	ft_init(t_data *data, t_map *map)
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	t_image	*image;

	data->map = map;
	image = malloc(sizeof(t_image));
	if (!image)
	{
		ft_handle_error("Error");
		ft_handle_error("Image memory allocation failed.");
		exit(EXIT_FAILURE);
	}
	data->image = image;
	relative_path = "./assets/waltuh.xpm";
	data->image->player_up = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./assets/waltuh.xpm";
	data->image->player_left = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	relative_path = "./assets/waltuh.xpm";
	data->image->player_down = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);

	ft_init_sub(data);
	data->counter = 0;
	data->collected = 0;
}