/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_10.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:39:24 by ibour             #+#    #+#             */
/*   Updated: 2025/06/06 09:47:30 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_setup_child_pipes(int pipes[11][2], int i, int cmd_count)
{
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < cmd_count - 1)
		dup2(pipes[i][1], STDOUT_FILENO);
	ft_close_all_pipes(pipes, cmd_count - 1);
}

static void	ft_setup_child(t_pipeline_info *info, int i, int cmd_count)
{
	t_execute_child_info	child_info;

	child_info = (t_execute_child_info){.cmds = info->cmds,
		.pipes = info->pipes, .i = i, .cmd_count = cmd_count,
		.env_list = info->env_list};
	ft_execute_child(&child_info);
}

static t_bool	ft_handle_fork_error(t_pipeline_info *info, int cmd_count)
{
	ft_close_all_pipes(info->pipes, cmd_count - 1);
	free(info->pids);
	return (FALSE);
}

t_bool	ft_execute_pipeline(t_pipeline_info *info)
{
	int	i;
	int	cmd_count;

	cmd_count = ft_count_commands(info->cmds);
	i = 0;
	while (i < cmd_count)
	{
		info->pids[i] = fork();
		if (info->pids[i] == -1)
			return (ft_handle_fork_error(info, cmd_count));
		if (info->pids[i] == 0)
			ft_setup_child(info, i, cmd_count);
		i++;
	}
	ft_close_all_pipes(info->pipes, cmd_count - 1);
	ft_wait_for_children(info->pids, cmd_count, info->shell);
	return (TRUE);
}

t_bool	ft_handle_pipe_execution(t_shell *shell, char **cmds,
		t_env_list *env_list)
{
	t_pipeline_info	pipeline;
	int				cmd_count;

	cmd_count = ft_count_commands(cmds);
	if (!ft_create_pipes(pipeline.pipes, cmd_count))
		return (FALSE);
	pipeline.pids = malloc(sizeof(pid_t) * cmd_count);
	if (!pipeline.pids)
	{
		ft_close_all_pipes(pipeline.pipes, cmd_count - 1);
		return (FALSE);
	}
	pipeline.shell = shell;
	pipeline.cmds = cmds;
	pipeline.env_list = env_list;
	if (!ft_execute_pipeline(&pipeline))
		return (FALSE);
	free(pipeline.pids);
	return (TRUE);
}
