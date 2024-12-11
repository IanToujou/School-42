/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:24:42 by ibour             #+#    #+#             */
/*   Updated: 2024/12/11 17:39:53 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

int main(const int argc, char **argv) {
	t_data	*data;

	if (argc != 2)
		ft_throw_error(ERROR_SYNTAX);
	ft_init_data(&data);
	ft_init_map();
	ft_init_mlx();
	ft_init_hooks();
	return (0);
}
