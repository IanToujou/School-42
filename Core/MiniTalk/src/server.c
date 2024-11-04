/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:55:00 by ibour             #+#    #+#             */
/*   Updated: 2024/11/04 14:21:58 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_handle_signal(int signum, siginfo_t *info, void *context)
{
	static int				bits;
	static unsigned char	c;
	static pid_t			pid;

	(void) context;
	if (pid != info->si_pid)
	{
		bits = 0;
		c = 0;
	}
	pid = info->si_pid;
	c = c << 1;
	if (signum == SIGUSR1)
		c = c | 1;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Server PID: %d\n", getpid());
	action.sa_sigaction = &ft_handle_signal;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		;
	return (0);
}
