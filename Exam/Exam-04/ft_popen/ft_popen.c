/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:59:58 by ibour             #+#    #+#             */
/*   Updated: 2025/09/09 17:33:32 by ibour            ###   ########.fr       */
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

int	ft_popen(const char *file, char *const argv[], char type) {

	// Input checks
	if (!file || !argv)
		return -1;
	if (type != 'r' && type != 'w')
		return -1;

	int fd[2] = {-1, -1};

	// Pipe and fork
	if (pipe(fd) < 0) {
		close_fd(&fd[0], &fd[1]);
		return -1;
	}

	pid_t pid = fork();

	if (pid < 0)
		return -1;

	if (type == 'r') {

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

int main() {
	char *const av[] = {"ls", "-la", NULL};
	int fd = ft_popen("ls", av, 'r');

	if (fd == -1) {
		printf("ft_popen failed\n");
		return 1;
	}

	// Read the output from the command
	char buffer[1024];
	ssize_t bytes_read;

	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
		buffer[bytes_read] = '\0';
		printf("%s", buffer);
	}

	close(fd);  // Close the file descriptor
	wait(NULL); // Wait for child process to prevent zombie

	return 0;
}
