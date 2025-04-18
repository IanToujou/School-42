/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_banner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:35:16 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 17:15:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

const char	*ft_util_banner_prompt_pre(void)
{
	return (
		COLOR_RESET "┌──(" COLOR_PINK "≽^•w•^≼" COLOR_RESET " | " COLOR_PINK
	);
}

const char	*ft_util_banner_prompt_post(void)
{
	return (
		COLOR_RESET ")──[" COLOR_CYAN "~/Projects" COLOR_RESET "]\n"
		"└─$ " COLOR_RESET
	);
}

void	ft_util_banner_intro(void)
{
	int			i;
	const char	*banner[] = {
		COLOR_MAGENTA BANNER_LINE1 COLOR_RESET,
		COLOR_YELLOW BANNER_LINE2 COLOR_RESET,
		COLOR_PINK BANNER_LINE3 COLOR_RESET,
		COLOR_RED BANNER_LINE4_P1 BANNER_LINE4_P2 COLOR_RESET,
		COLOR_YELLOW BANNER_LINE5_P1 BANNER_LINE5_P2 COLOR_RESET,
		COLOR_CYAN BANNER_LINE6_P1 BANNER_LINE6_P2 COLOR_RESET,
		COLOR_MAGENTA BANNER_LINE7_P1 BANNER_LINE7_P2 COLOR_RESET,
		COLOR_RED BANNER_LINE8 COLOR_RESET,
		COLOR_YELLOW BANNER_LINE9 COLOR_RESET,
		NULL
	};

	i = 0;
	while (banner[i])
	{
		printf("%s\n", banner[i]);
		i++;
	}
}
