/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:01:24 by ibour             #+#    #+#             */
/*   Updated: 2024/11/09 21:39:36 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	main(const int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_throw_error(ERROR_SYNTAX);
	if (pipe(fd) < 0)
		ft_throw_error(ERROR_PIPE);
	pid = fork();
	if (pid < 0)
		ft_throw_error(ERROR_FORK);
	if (pid == 0)
		ft_process_child(argv, envp, fd);
	waitpid(pid, NULL, 0);
	ft_process_parent(argv, envp, fd);
	return (0);
}
