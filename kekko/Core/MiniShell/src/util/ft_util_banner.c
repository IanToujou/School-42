/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_banner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:35:16 by ibour             #+#    #+#             */
/*   Updated: 2025/04/10 10:31:21 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_util_banner(void)
{
	const char	*banner[] = {
		BANNER_LINE1,
		BANNER_LINE2,
		BANNER_LINE3,
		BANNER_LINE4,
		BANNER_LINE5,
		BANNER_LINE6,
		BANNER_LINE7,
		BANNER_LINE8,
		BANNER_LINE9,
		NULL
	};
	int			i;

	i = 0;
	while (banner[i])
	{
		printf("%s\n", banner[i]);
		i++;
	}
}

const char	*get_prompt(void)
{
	return (
		O "🐱" RESET G "S" RESET Y "u" RESET B "p" RESET M "e" RESET \
		C "r" RESET Y "~" RESET P "N" RESET P "y" RESET P "a" RESET Y "~" RESET \
		G "S" RESET Y "h" RESET B "e" RESET Y "l" RESET B "l" RESET M "🐱" RESET \
		O ">" RESET P "$" RESET Y
	);
}
