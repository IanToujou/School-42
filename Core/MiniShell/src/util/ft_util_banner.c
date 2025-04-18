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
