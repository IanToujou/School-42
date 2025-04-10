/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:55:09 by ibour             #+#    #+#             */
/*   Updated: 2024/11/04 14:40:01 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_response = 0;

void	ft_response(int signum)
{
	g_response = 1;
	(void)signum;
}

void	ft_send_bit(int pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(pid, signal) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		ft_send_bit(pid, (c >> i) & 1);
		usleep(400);
		i--;
	}
	while (!g_response)
		;
	g_response = 0;
}

void	ft_send_str(int pid, char *str)
{
	while (*str)
		ft_send_char(pid, *str++);
	ft_send_char(pid, '\0');
}

int	main(const int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <pid> <string>\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR2, ft_response);
	ft_send_str(pid, argv[2]);
	return (0);
}
