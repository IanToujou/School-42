/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:46:19 by ibour             #+#    #+#             */
/*   Updated: 2025/09/09 13:53:00 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void close_fd(const int *fd1, const int *fd2) {
	if (*fd1 != -1) close(*fd1);
	if (*fd2 != -1) close(*fd2);
}

int ft_popen(const char *file, char *const argv[], char type) {

	if (!file || !argv)
		return -1;
	if (type != 'r' && type != 'w')
		return -1;

	int fd[2] = {-1, -1};
	if (pipe(fd) < 0)
		return -1;

	if (type == 'r') {

		const pid_t pid = fork();
		if (pid < 0) {
			close_fd(&fd[0], &fd[1]);
			return -1;
		}

		if (pid == 0) {
			if (dup2(fd[1], 1) < 0) {
				close_fd(&fd[0], &fd[1]);
				exit(-1);
			}
			close_fd(&fd[0], &fd[1]);
			execvp(file, argv);
			exit(-1);
		}

		close(fd[1]);
		return fd[0];

	} else {
		const pid_t pid = fork();
		if (pid < 0) {
			close_fd(&fd[0], &fd[1]);
			return -1;
		}

		if (pid == 0) {
			if (dup2(fd[0], 0) < 0) {
				close_fd(&fd[0], &fd[1]);
				exit(-1);
			}
			close_fd(&fd[0], &fd[1]);
			execvp(file, argv);
			exit(-1);
		}

		close(fd[0]);
		return fd[1];

	}

}