/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:10:59 by ibour             #+#    #+#             */
/*   Updated: 2024/12/01 06:51:48 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	main(const int argc, char **argv)
{
	t_engine	engine;

	if (argc != 2)
		ft_throw_error(ERROR_SYNTAX);
	ft_init_engine(&engine, argv[1]);
	ft_init_hooks(&engine);
	return (0);
}
