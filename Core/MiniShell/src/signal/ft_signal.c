/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:43:29 by ibour             #+#    #+#             */
/*   Updated: 2025/05/24 23:34:19 by mwelfrin         ###   ########.fr       */
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

void	ft_signal_start(t_shell *shell)
{
	if (shell->is_interactive)
	{
		signal(SIGINT, ft_signal_c);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, ft_signal_c_fork);
		signal(SIGQUIT, ft_signal_c_fork_slash);
	}
}

void	ft_signal_mask(t_shell *shell)
{
	struct termios	term;

	if (!shell->is_interactive)
		return ;
	tcgetattr(0, &term);
	term.c_cflag &= ~ECHOCTL;
	tcsetattr(0, 0, &term);
}
