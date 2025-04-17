/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:55:09 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 13:19:07 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_signal_add_ignore(const int signal)
{
	(void) signal;
}

void	ft_signal_heredoc(const int signal)
{
	(void) signal;
	exit(STATUS_MAIN);
}

void	ft_signal_empty(const int signal)
{
	(void) signal;
	write(1, "\n", 1);
}
