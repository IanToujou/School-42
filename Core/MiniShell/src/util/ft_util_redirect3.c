/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_redirect3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:15:00 by ibour             #+#    #+#             */
/*   Updated: 2025/06/03 17:34:21 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_util_handle_child_pipe(t_shell *shell, int *fd)
{
	errno = 0;
	if (close(fd[1]) == -1)
		ft_error_throw(ERROR_CLOSE);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error_throw(ERROR_DUP2);
	if (close(fd[0]) == -1)
		ft_error_throw(ERROR_CLOSE);
	shell->process_level = PROCESS_LEVEL_CHILD;
	return (PROCESS_LEVEL_CHILD);
}

int	ft_util_handle_parent_pipe(t_shell *shell, int *fd, pid_t pid)
{
	shell->pid = pid;
	if (close(fd[0]) == -1)
		ft_error_throw(ERROR_CLOSE);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error_throw(ERROR_DUP2);
	if (close(fd[1]) == -1)
		ft_error_throw(ERROR_CLOSE);
	return (PROCESS_LEVEL_PARENT);
}

int	ft_util_create_pipe_and_fork(int fd[2], pid_t *pid)
{
	if (pipe(fd) == -1)
	{
		ft_error_throw(ERROR_PIPE);
		return (PROCESS_LEVEL_ERROR);
	}
	*pid = fork();
	if (*pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		ft_error_throw(ERROR_FORK);
		return (PROCESS_LEVEL_ERROR);
	}
	return (0);
}

int	ft_util_handle_pipe(t_shell *shell)
{
	int		fd[2];
	pid_t	pid;

	if (ft_util_create_pipe_and_fork(fd, &pid) != 0)
		return (PROCESS_LEVEL_ERROR);
	if (pid == 0)
	{
		if (close(fd[1]) == -1 || dup2(fd[0], STDIN_FILENO) == -1)
		{
			close(fd[0]);
			ft_error_throw(ERROR_DUP2);
			exit(EXIT_FAILURE);
		}
		close(fd[0]);
		shell->process_level = PROCESS_LEVEL_CHILD;
		return (PROCESS_LEVEL_CHILD);
	}
	shell->pid = pid;
	if (close(fd[0]) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(fd[1]);
		return (ft_error_throw(ERROR_DUP2), PROCESS_LEVEL_ERROR);
	}
	close(fd[1]);
	return (PROCESS_LEVEL_PARENT);
}

int	ft_util_check_pipe_io(t_shell *shell, t_token *prev)
{
	pid_t	pid;

	if (!prev || !ft_util_prev_redirect(prev->prev))
		return (ft_util_handle_pipe(shell));
	pid = fork();
	if (pid == -1)
	{
		ft_error_throw(ERROR_FORK);
		return (PROCESS_LEVEL_ERROR);
	}
	if (pid == 0)
	{
		shell->process_level = PROCESS_LEVEL_CHILD;
		if (dup2(shell->std_out, STDOUT_FILENO) == -1)
		{
			ft_error_throw(ERROR_DUP2);
			exit(EXIT_FAILURE);
		}
		return (PROCESS_LEVEL_CHILD);
	}
	shell->pid = pid;
	return (PROCESS_LEVEL_PARENT);
}
