/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:48:45 by ibour             #+#    #+#             */
/*   Updated: 2024/11/07 13:54:32 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_game_lose(const t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_printf("Game over!\n");
	exit(EXIT_SUCCESS);
}

int	ft_game_win(const t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	ft_printf("You won!\n");
	exit(EXIT_SUCCESS);
}

int	ft_render_frame(t_data *data)
{
	ft_render_background(data);
	ft_render_map(data);
	mlx_hook(data->window, 17, 1L << 2, ft_game_lose, data);
	mlx_key_hook(data->window, ft_hook_key, data);
	return (0);
}

int	main(const int argc, char **argv)
{
	t_data		data;
	t_map		map;

	(void)argc;
	ft_render_window(&data, argv);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
	{
		ft_handle_error("Failed to allocate space for the map.");
		exit(EXIT_FAILURE);
	}
	data.mlx = mlx_init();
	ft_init(&data, &map);
	ft_parse_map(&data, argv, argc);
	if (!data.mlx) {
		ft_handle_error("MLX library failed to initialize.");
		exit(EXIT_FAILURE);
	}
	data.window = mlx_new_window(data.mlx, data.size_x, data.size_y, "So Long");
	ft_render_frame(&data);
	mlx_loop(data.mlx);
	ft_handle_error("MLX loop failed.");
	exit(EXIT_FAILURE);
}