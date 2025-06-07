/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:13:42 by ibour             #+#    #+#             */
/*   Updated: 2025/05/26 21:47:19 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*ft_create_cmd_token(char *cmd, int *i)
{
	t_token	*cmd_token;

	cmd_token = malloc(sizeof(t_token));
	if (!cmd_token)
		return (NULL);
	while (cmd[*i] && !ft_isspace(cmd[*i]))
		(*i)++;
	cmd_token->str = ft_parse_handle_strndup(cmd, *i);
	cmd_token->type = TOKEN_CMD;
	cmd_token->next = NULL;
	return (cmd_token);
}

t_bool	ft_process_defined(t_shell *shell, t_token *cmd_token,
					char **commands, t_env_list *env_list)
{
	t_token	*arg_token;
	int		i;

	i = 0;
	while (commands[0][i] && !ft_isspace(commands[0][i]))
		i++;
	while (commands[0][i] && ft_isspace(commands[0][i]))
		i++;
	arg_token = NULL;
	if (commands[0][i])
	{
		arg_token = ft_create_arg_token(commands[0] + i);
		if (!arg_token)
			return (FALSE);
		cmd_token->next = arg_token;
		ft_util_quote_plus(cmd_token);
	}
	ft_run_defined(shell, cmd_token, env_list, commands);
	if (arg_token)
	{
		free(arg_token->str);
		free(arg_token);
	}
	return (TRUE);
}

t_bool	ft_process_execve(t_shell *shell,
					char **commands, t_env_list *env_list)
{
	pid_t	pid;
	int		status;
	char	**args;

	pid = fork();
	if (pid == -1)
		return (FALSE);
	if (pid == 0)
	{
		args = ft_parse_handle_split_cmd(commands[0]);
		if (!args)
			exit(EXIT_FAILURE);
		ft_util_launch_execve(env_list, args);
		ft_util_cmd_free(args);
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	return (TRUE);
}

t_bool	ft_util_token_process_pipe_internal(t_shell *shell,
					char **commands, t_env_list *env_list, t_token *cmd_token)
{
	if (ft_run_defined_is_defined(cmd_token))
	{
		if (!ft_process_defined(shell, cmd_token, commands, env_list))
			return (FALSE);
	}
	else if (!ft_process_execve(shell, commands, env_list))
		return (FALSE);
	return (TRUE);
}

t_bool	ft_util_token_process_pipe(t_shell *shell,
			char **commands, t_env_list *env_list)
{
	t_token	*cmd_token;
	int		i;
	t_bool	result;

	if (shell->pipe_count > 0)
		return (ft_handle_pipe_execution(shell, commands, env_list));
	i = 0;
	cmd_token = ft_create_cmd_token(commands[0], &i);
	if (!cmd_token)
		return (FALSE);
	result = ft_util_token_process_pipe_internal(shell,
			commands, env_list, cmd_token);
	if (!result)
	{
		free(cmd_token->str);
		free(cmd_token);
		return (FALSE);
	}
	free(cmd_token->str);
	free(cmd_token);
	return (TRUE);
}
