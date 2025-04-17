/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_banner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:35:16 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 14:03:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_util_banner_intro(void)
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

const char	*ft_util_banner_prompt(void)
{
	return (
		COLOR_RESET "┌──(" COLOR_PINK "≽^•⩊•^≼" COLOR_RESET ")──[" COLOR_CYAN "~" COLOR_RESET "]\n"
		"└─$ " COLOR_RESET
	);
}
