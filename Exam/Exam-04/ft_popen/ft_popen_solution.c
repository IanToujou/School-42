/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:59:58 by ibour             #+#    #+#             */
/*   Updated: 2025/10/19 05:53:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_close(const int *fd1, const int *fd2) {
	if (*fd1 != -1) close(*fd1);
	if (*fd2 != -1) close(*fd2);
}

int ft_popen(const char *file, char *const argv[], char type) {

	if (!file || !argv)
		return -1;
	if (type != 'r' && type != 'w')
		return -1;

	int fd[2] = {-1, -1};

	if (pipe(fd) < 0) {
		ft_close(&fd[0], &fd[1]);
		return -1;
	}

	pid_t pid = fork();
	if (pid < 0)
		return -1;

	if (type == 'r') {

		if (pid == 0) {
			if (dup2(fd[1], 1) != -1) {
				ft_close(&fd[0], &fd[1]);
				exit(-1);
			}
			execvp(file, argv);
			ft_close(&fd[0], &fd[1]);
			exit(-1);
		}

		close(fd[1]);
		return fd[0];

	} else {

		if (pid == 0) {
			if (dup2(fd[0], 0) != 0) {
				ft_close(&fd[0], &fd[1]);
				exit(-1);
			}
			execvp(file, argv);
			ft_close(&fd[0], &fd[1]);
			exit(-1);
		}

		close(fd[0]);
		return fd[1];

	}

}