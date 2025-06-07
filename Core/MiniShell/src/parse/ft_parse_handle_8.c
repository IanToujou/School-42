/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:39:24 by ibour             #+#    #+#             */
/*   Updated: 2025/06/06 09:33:14 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_setup_pipe_cmd(t_shell *shell, char **cmds,
		t_handle_pipe_cmd *pipe_info)
{
	(void)shell;
	pipe_info->cmd_count = 0;
	while (cmds[pipe_info->cmd_count])
		pipe_info->cmd_count++;
	if (!ft_parse_handle_setup_pipes(pipe_info->pipes, pipe_info->pipe_count))
		return (FALSE);
	return (TRUE);
}

static t_bool	ft_execute_pipe_cmds(t_pipe_exec_info *info)
{
	int						i;
	t_child_process_info	child_info;

	i = 0;
	while (i < info->pipe_info->cmd_count)
	{
		info->pids[i] = fork();
		if (info->pids[i] == -1)
		{
			free(info->pids);
			ft_parse_handle_close_pipes(info->pipe_info->pipes,
				info->pipe_info->pipe_count);
			return (FALSE);
		}
		if (info->pids[i] == 0)
		{
			child_info = (t_child_process_info){.i = i,
				.pipe_count = info->pipe_info->pipe_count,
				.pipe_info = info->pipe_info, .shell = info->shell,
				.cmds = info->cmds, .env_list = info->env_list};
			ft_child_process(&child_info);
		}
		i++;
	}
	return (TRUE);
}

static void	ft_cleanup_and_wait(t_shell *shell, t_handle_pipe_cmd *pipe_info,
		pid_t *pids)
{
	int	i;
	int	status;

	i = 0;
	while (i < pipe_info->pipe_count)
	{
		close(pipe_info->pipes[i][0]);
		close(pipe_info->pipes[i][1]);
		i++;
	}
	i = 0;
	while (i < pipe_info->cmd_count)
	{
		waitpid(pids[i], &status, 0);
		if (i == pipe_info->cmd_count - 1 && WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
		i++;
	}
	free(pids);
}

t_bool	ft_parse_handle_pipe_cmd(t_shell *shell, char **cmds,
		t_env_list *env_list, const int pipe_count)
{
	t_handle_pipe_cmd	pipe_info;
	t_pipe_exec_info	exec_info;
	pid_t				*pids;

	pipe_info.pipe_count = pipe_count;
	if (!ft_setup_pipe_cmd(shell, cmds, &pipe_info))
		return (FALSE);
	pids = malloc(sizeof(pid_t) * pipe_info.cmd_count);
	if (!pids)
	{
		ft_parse_handle_close_pipes(pipe_info.pipes, pipe_count);
		return (FALSE);
	}
	exec_info = (t_pipe_exec_info){.shell = shell, .cmds = cmds,
		.env_list = env_list, .pipe_info = &pipe_info, .pids = pids};
	if (!ft_execute_pipe_cmds(&exec_info))
		return (FALSE);
	ft_cleanup_and_wait(shell, &pipe_info, pids);
	return (TRUE);
}

t_bool	ft_create_pipes(int pipes[11][2], int cmd_count)
{
	int	i;

	i = 0;
	while (i < cmd_count - 1)
	{
		if (pipe(pipes[i]) == -1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
