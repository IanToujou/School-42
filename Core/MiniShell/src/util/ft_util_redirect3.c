/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_redirect3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:15:00 by ibour             #+#    #+#             */
/*   Updated: 2025/05/08 13:47:18 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_util_handle_pipe(t_shell *shell)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error_throw(ERROR_PIPE);
	pid = fork();
	if (pid == 0)
		return (ft_util_handle_child_pipe(shell, fd));
	else if (pid > 0)
		return (ft_util_handle_parent_pipe(shell, fd, pid));
	else
	{
		ft_error_throw(ERROR_FORK);
		return (PROCESS_LEVEL_DEFAULT);
	}
}

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

int	ft_util_check_pipe_io(t_shell *shell, t_token *prev)
{
	int		lvl;
	pid_t	pid;

	lvl = PROCESS_LEVEL_DEFAULT;
	if (prev && ft_util_prev_redirect(prev->prev))
	{
		pid = fork();
		if (pid == 0)
		{
			shell->process_level = PROCESS_LEVEL_CHILD;
			if (dup2(shell->std_out, STDOUT_FILENO) == -1)
				ft_error_throw(ERROR_DUP2);
			lvl = PROCESS_LEVEL_CHILD;
		}
		else if (pid > 0)
		{
			shell->pid = pid;
			lvl = PROCESS_LEVEL_PARENT;
		}
		else
			ft_error_throw(ERROR_FORK);
	}
	else
		lvl = ft_util_handle_pipe(shell);
	return (lvl);
}
