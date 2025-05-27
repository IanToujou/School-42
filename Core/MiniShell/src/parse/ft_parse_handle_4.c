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

void	ft_parse_handle_execute(t_shell *shell, char *cmd_str,
		t_env_list *env_list)
{
	char	**args;
	t_token	*token;

	args = ft_parse_handle_split_cmd(cmd_str);
	if (!args || !args[0])
		ft_error_throw(ERROR_PARSE);
	shell->current_cmds = args;
	token = ft_util_token_create(shell, args[0]);
	if (!token)
		ft_error_throw(ERROR_TOKEN);
	token->type = TOKEN_CMD;
	ft_run_cmd(shell, token, env_list, args);
	free(token);
	ft_util_cmd_free(args);
	exit(shell->exit_status);
}

static void	ft_spawn_single_child(t_shell *shell, char *cmd,
	t_env_list *env_list, t_handle_pipe_cmd *pipe_info)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error_throw(ERROR_FORK);
	if (pid == 0)
	{
		ft_parse_handle_setup_io(pipe_info->pipes, pipe_info->pipe_count,
			pipe_info->i, pipe_info->cmd_count);
		ft_parse_handle_execute(shell, cmd, env_list);
	}
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

t_bool	ft_parse_handle_pipe_cmd(t_shell *shell, char **cmds,
	t_env_list *env_list, const int pipe_count)
{
	t_handle_pipe_cmd	pipe_info;

	pipe_info.pipe_count = pipe_count;
	pipe_info.cmd_count = 0;
	while (cmds[pipe_info.cmd_count])
		pipe_info.cmd_count++;
	if (!ft_parse_handle_setup_pipes(pipe_info.pipes, pipe_count))
		return (FALSE);
	ft_parse_handle_spawn_pipe(shell, cmds, env_list, pipe_info);
	ft_parse_handle_close_pipes(pipe_info.pipes, pipe_count);
	ft_parse_handle_wait_children(pipe_info.cmd_count);
	return (TRUE);
}
