/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:24:42 by ibour             #+#    #+#             */
/*   Updated: 2024/12/18 11:37:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int main(const int argc, char **argv) {
	t_data	*data;

	if (argc != 2)
		ft_error_throw(ERROR_SYNTAX);
	if (ft_init_data(&data))
		ft_error_throw(ERROR_INIT_DATA);
	if (ft_init_map(data, argv[1]))
		ft_error_throw(ERROR_INIT_MAP);
	if (ft_init_mlx(data))
		ft_error_throw(ERROR_INIT_MLX);
	// todo draw image
	// todo put image to window
	ft_init_hooks(data);
	(void)argv;
	ft_util_free_map(data->map);
	ft_util_free(data);
	return (0);
}
