/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:40:14 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 14:57:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_run_bin_token_length(const t_token *token)
{
	int	size;

	size = 1;
	while (token && token->type == TOKEN_ARG)
	{
		size++;
		token = token->next;
	}
	return (size);
}

static void	ft_run_bin_handle(t_shell *shell, const t_token *token,
		t_env_list *env_list)
{
	int		size;
	int		i;
	char	**args;

	if (token->type == TOKEN_CMD)
		ft_util_env_update_shlvl(shell, token, &env_list);
	size = ft_run_bin_token_length(token->next);
	args = (char **)malloc(sizeof(char *) * (size + 1));
	if (args == NULL)
		ft_error_throw(ERROR_MALLOC);
	i = -1;
	while (++i < size)
	{
		args[i] = ft_strtrim(token->str, " ");
		if (args[i] == NULL)
			ft_error_throw(ERROR_MALLOC);
		token = token->next;
	}
	args[size] = NULL;
	ft_util_launch_execve(env_list, args);
}

static void	ft_run_bin_handle_piped(t_shell *shell, const t_token *token,
		t_env_list *env_list)
{
	int				size;
	int				i;
	char			**args;
	const t_token	*current;

	if (token->type == TOKEN_CMD)
		ft_util_env_update_shlvl(shell, token, &env_list);
	if (shell->current_cmds != NULL)
	{
		args = shell->current_cmds;
		i = 0;
		while (args[i])
			i++;
	}
	else
	{
		size = ft_run_bin_token_length(token->next);
		args = (char **) malloc(sizeof(char *) * (size + 1));
		if (args == NULL)
			ft_error_throw(ERROR_MALLOC);
		current = token;
		i = -1;
		while (++i < size)
		{
			args[i] = ft_strtrim(current->str, " ");
			if (args[i] == NULL)
				ft_error_throw(ERROR_MALLOC);
			current = current->next;
		}
		args[size] = NULL;
	}
	ft_util_launch_execve(env_list, args);
	ft_util_cmd_free(shell->current_cmds);
}

void	ft_run_bin(t_shell *shell, const t_token *token, t_env_list *env_list,
		int pipe_count)
{
	pid_t	pid;
	int		status;

	ft_util_bin_signal(token);
	pid = fork();
	if (pid == 0)
	{
		errno = 0;
		if (pipe_count > 0)
			ft_run_bin_handle_piped(shell, token, env_list);
		else
			ft_run_bin_handle(shell, token, env_list);
	}
	else if (pid > 0)
	{
		status = 0;
		shell->pid = pid;
		waitpid(pid, &status, 0);
		shell->exit_status = WEXITSTATUS(status);
	}
	else
		ft_error_throw(ERROR_FORK);
}
