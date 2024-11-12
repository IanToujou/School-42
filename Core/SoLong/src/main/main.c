/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:26:10 by ibour             #+#    #+#             */
/*   Updated: 2024/11/12 09:39:50 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/**
 * Dawg this is the main function what do you expect it to do?
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return The status code in case this fragile baby fucks up.
 */
int	main(const int argc, char **argv)
{
	t_gamedata	*gamedata;

	(void)argv;

	if (argc != 2)
		ft_throw_error(ERROR_SYNTAX);
	if (ft_init_mlx(&gamedata) < 0)
		ft_throw_error(ERROR_INIT_MLX);
	if (ft_init_hooks(gamedata) < 0)
		ft_throw_error(ERROR_INIT_HOOKS);
	mlx_loop(gamedata->mlx);
	free(gamedata->mlx);
}