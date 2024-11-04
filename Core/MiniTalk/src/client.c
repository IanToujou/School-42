/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:55:09 by ibour             #+#    #+#             */
/*   Updated: 2024/11/04 11:05:25 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	send_character(const pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGNAL_ONE) == -1)
				return (-1);
		}
		if (kill(pid, SIGNAL_ZERO) == -1)
			return (-1);
		usleep(400);
		i++;
	}
	return (0);
}

int main(const int argc, char **argv)
{
	pid_t	pid;
	char	*msg;
	int		i;

	if(argc != 3) {
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	i = 0;
	while (msg[i]) {
		if (send_character(pid, msg[i]) == -1) {
			printf("Error sending signal\n");
			return (1);
		}
		i++;
	}
	if (send_character(pid, '\0') == -1) {
		printf("Error sending signal\n");
		return (1);
	}
	return (0);
}