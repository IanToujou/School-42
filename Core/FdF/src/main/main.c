/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:24:42 by ibour             #+#    #+#             */
/*   Updated: 2024/12/12 14:37:04 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int main(const int argc, char **argv) {
	t_data	*data;

	if (argc != 2)
		ft_throw_error(ERROR_SYNTAX);
	if (ft_init_data(&data))
		ft_throw_error(ERROR_INIT_DATA);
	if (ft_init_map(data, argv[1]))
		ft_throw_error(ERROR_INIT_MAP);
	if (ft_init_mlx(data))
		ft_throw_error(ERROR_INIT_MLX);
	ft_init_hooks(data);
	return (0);
}
