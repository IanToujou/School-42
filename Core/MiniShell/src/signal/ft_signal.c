/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:43:29 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 12:55:18 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_signal_c(const int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();

}

void	ft_signal_c_fork_slash(const int signal)
{
	(void)signal;
	write(1, "Quit: 3\n", 8);
}

void	ft_signal_c_fork(const int signal)
{
	(void)signal;
	write(1, "\n", 1);
}

void	ft_signal_start(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_signal_c);
}

void	ft_signal_mask(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_cflag &= ~ECHOCTL;
	tcsetattr(0, 0, &term);
}
