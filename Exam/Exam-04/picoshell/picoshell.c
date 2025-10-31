/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picoshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 06:33:06 by ibour             #+#    #+#             */
/*   Updated: 2025/10/31 06:35:24 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int picoshell(char **cmds[]) {

	int fd[2];
	int last_fd = -1;
	int i = 0;

	while (cmds[i+1]) {

		if (cmds[i+1] && pipe(fd) < 0)
			return 1;

		const pid_t pid = fork();
		if (pid < 0) {
			if (cmds[i+1]) {
				close(fd[0]);
				close(fd[1]);
			}
			return 1;
		}



		i++;

	}

	while (wait(NULL) > 0) {}
	return 0;

}
