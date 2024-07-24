/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:39:17 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 18:39:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	main(int argc, char **argv)
{
    int i;

    if (argc < 2) {
		without_args(argv);
	} else {
		i = 0;
		while (i++ < argc)
		{
			if (ft_file_read(argv[i]) == 0)
			{
				ft_putstr(basename(argv[0]), 2);
				ft_putstr(": ", 2);
				ft_putstr(argv[i], 2);
				ft_putstr(": ", 2);
				ft_putstr(strerror(errno), 2);
				ft_putchar('\n', 2);
			}

		}
	}
}
