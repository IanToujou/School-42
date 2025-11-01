/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:59:58 by ibour             #+#    #+#             */
/*   Updated: 2025/11/01 20:41:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type) {

	if (!file || !argv || !(type == 'r' || type == 'w'))
		return (-1);

	int fd[2];
	if (pipe(fd) == -1)
		return (-1);

	const pid_t pid = fork();
	if (pid == -1) {
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}

	if (type == 'r') {

		if (pid == 0) {

			if (dup2(fd[1], 1) == -1)
				exit(1);

			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			exit(1);

		}

		close(fd[1]);
		return fd[0];

	} else {

		if (pid == 0) {

			if (dup2(fd[0], 0) == -1)
				exit(1);

			close(fd[0]);
			close(fd[1]);
			execvp(file, argv);
			exit(1);

		}

		close(fd[0]);
		return fd[1];

	}

}