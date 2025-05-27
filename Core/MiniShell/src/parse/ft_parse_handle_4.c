/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:37:09 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 20:39:01 by ibour            ###   ########.fr       */
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

void	ft_parse_handle_spawn_pipe(t_shell *shell, char **cmds,
	t_env_list *env_list, int pipes[][2], int pipe_count, int cmd_count)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < cmd_count)
	{
		pid = fork();
		if (pid == -1)
			ft_error_throw(ERROR_FORK);
		if (pid == 0)
		{
			ft_parse_handle_setup_io(pipes, pipe_count, i, cmd_count);
			ft_parse_handle_execute(shell, cmds[i], env_list);
		}
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
	t_handle_pipe	s;
	int				pipes[10][2];

	s.cmd_count = 0;
	while (cmds[s.cmd_count])
		s.cmd_count++;
	if (!ft_parse_handle_setup_pipes(pipes, pipe_count))
		return (FALSE);
	ft_parse_handle_spawn_pipe(shell, cmds, env_list, pipes,
		pipe_count, s.cmd_count);
	ft_parse_handle_close_pipes(pipes, pipe_count);
	ft_parse_handle_wait_children(s.cmd_count);
	return (TRUE);
}

int	ft_parse_handle_count_segments(const char *input)
{
	t_split_pipe	s;

	s.i = 0;
	s.count = 1;
	s.in_quotes = 0;
	s.quote_char = 0;
	while (input[s.i])
	{
		if (input[s.i] == '\'' || input[s.i] == '"')
		{
			if (!s.in_quotes)
			{
				s.in_quotes = 1;
				s.quote_char = input[s.i];
			}
			else if (input[s.i] == s.quote_char)
				s.in_quotes = 0;
		}
		if (input[s.i] == '|' && !s.in_quotes)
			s.count++;
		s.i++;
	}
	return (s.count);
}
