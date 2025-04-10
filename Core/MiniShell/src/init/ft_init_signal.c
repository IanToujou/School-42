/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:35:16 by ibour             #+#    #+#             */
/*   Updated: 2025/04/10 10:35:56 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Configures terminal settings to disable echo control characters.
 * Prevents display of control characters like ^C during signal handling.
 * Uses termios structure to modify terminal attributes.
 */
void	ft_echo_off(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

/**
 * Sets up signal handlers for the shell.
 * Configures custom handler for SIGINT (Ctrl+C) and ignores SIGQUIT.
 * Ensures readline library works properly with signal handling.
 * Uses sigaction for more reliable signal management.
 */
void ft_set_sig(void)
{
    struct termios term;
    struct sigaction sa;

    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ECHOCTL;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    sa.sa_handler = ft_sigint;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    if (isatty(STDIN_FILENO)) {
        sa.sa_handler = SIG_IGN;
    } else {
        sa.sa_handler = SIG_DFL;
    }
    sigaction(SIGQUIT, &sa, NULL);
}

/**
 * Custom SIGINT (Ctrl+C) handler for the shell.
 * Updates global signal status and shell exit status.
 * Manages terminal display during interrupt - prints new line.
 * Resets readline interface to clean state after interrupt.
 */
void ft_sigint(int sig)
{
    (void)sig;
    g_signal_status = 130;
    write(STDOUT_FILENO, "\n", 1);
    if (isatty(STDIN_FILENO)) {
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}
