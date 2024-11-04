/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:55:00 by ibour             #+#    #+#             */
/*   Updated: 2024/11/04 11:23:46 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handle_signal(const int signal)
{
	static int	bits;
	static char	c;

	bits = 0;
	c = 0;
	if (signal == SIGNAL_ZERO)
		c |= (0 << bits);
	else if (signal == SIGNAL_ONE)
		c |= (1 << bits);
	bits++;
	if (bits >= 8) {
		ft_putchar_fd(c, 1);
		bits = 0;
		c = 0;
	}
}

int main()
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
}