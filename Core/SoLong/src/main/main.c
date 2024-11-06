/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:48:45 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 13:23:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_hook_destroy(const t_mlx_data *mlx_data)
{
	mlx_destroy_window(mlx_data->data, mlx_data->window);
	mlx_destroy_display(mlx_data->data);
	free(mlx_data->data);
	exit(0);
	return (0);
}

int	ft_hook_keypress(const int keycode, const t_mlx_data *mlx_data)
{
	(void) mlx_data;
	ft_printf("Pressed key: %d\n", keycode);
	return (0);
}

int	main(void)
{
	t_mlx_data	mlx_data;

	mlx_data.data = mlx_init();
	if (!mlx_data.data)
		return (1);
	mlx_data.window = mlx_new_window(mlx_data.data, 600, 500, "So Long");
	if (!mlx_data.window)
		return (free(mlx_data.data), 1);
	mlx_hook(mlx_data.window, KeyRelease, KeyReleaseMask, ft_hook_keypress, &mlx_data);
	mlx_hook(mlx_data.window, DestroyNotify, StructureNotifyMask, ft_hook_destroy, &mlx_data);
	mlx_loop(mlx_data.data);
}