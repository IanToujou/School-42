/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:37:09 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 20:52:50 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_spawn_single_child(t_shell *shell, char *cmd,
				t_env_list *env_list, t_handle_pipe_cmd *pipe_info)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_error_throw(ERROR_FORK);
		return ;
	}
	if (pid == 0)
	{
		ft_parse_handle_setup_io(pipe_info->pipes, pipe_info->pipe_count,
			pipe_info->i, pipe_info->cmd_count);
		ft_parse_handle_execute(shell, cmd, env_list);
		exit(EXIT_FAILURE);
	}
	shell->pid = pid;
}

void	ft_parse_handle_spawn_pipe(t_shell *shell, char **cmds,
			t_env_list *env_list, t_handle_pipe_cmd pipe_info)
{
	int	i;

	i = 0;
	while (i < pipe_info.cmd_count)
	{
		pipe_info.i = i;
		ft_spawn_single_child(shell, cmds[i], env_list, &pipe_info);
		i++;
	}
}

void	ft_parse_handle_wait_children(const int cmd_count)
{
	int	i;
	int	status;

	i = 0;
	while (i < cmd_count)
	{
		wait(&status);
		i++;
	}
}

void	ft_parse_handle_close_pipes(int pipes[][2], const int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	ft_parse_handle_setup_io(int pipes[][2], int pipe_count, int cmd_index,
		int cmd_count)
{
	int	i;

	if (cmd_index > 0)
	{
		if (dup2(pipes[cmd_index - 1][0], STDIN_FILENO) == -1)
			ft_error_throw(ERROR_DUP2);
	}
	if (cmd_index < cmd_count - 1)
	{
		if (dup2(pipes[cmd_index][1], STDOUT_FILENO) == -1)
			ft_error_throw(ERROR_DUP2);
	}
	i = 0;
	while (i < pipe_count)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}
