/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picoshell_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 05:42:17 by ibour             #+#    #+#             */
/*   Updated: 2025/10/31 06:36:31 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int    picoshell(char **cmds[]) {

    int fd[2]; // fd, last fd, i
    int last_fd = -1;
    int i = 0;

    while(cmds[i]) { // while cmds

        if(cmds[i+1] && pipe(fd) == -1) // if not last command and pipe
            return 1;

        const pid_t pid = fork();
        if(pid == -1) {
            if(cmds[i+1]) {
                close(fd[0]);
                close(fd[1]);
            }
            return 1;
        }

        if (pid == 0) {

            if(last_fd != -1) {
                if(dup2(last_fd, 0) == -1)
                    exit(1);
                close(last_fd);
            }

            if(cmds[i + 1]) {
                close(fd[0]);
                if(dup2(fd[1], 1) == -1)
                    exit(1);
                close(fd[1]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }

        if(last_fd != -1)
            close(last_fd);

        if(cmds[i + 1]) {
            close(fd[1]);
            last_fd = fd[0];
        }

        i++;

    }

    while(wait(NULL) > 0) {} // while wait
    return(0);

}