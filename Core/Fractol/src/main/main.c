/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:10:59 by ibour             #+#    #+#             */
/*   Updated: 2024/11/29 10:16:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	main(int argc, char **argv)
{
	t_engine	*engine;

	if (argc != 2)
		ft_throw_error(ERROR_SYNTAX);
	ft_init_data(engine, argv[1]);
	ft_init_mlx(engine);
	// init hooks + loop
	// free data
	return (0);
}
