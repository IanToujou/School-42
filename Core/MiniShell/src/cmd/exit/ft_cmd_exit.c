/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:09:13 by ibour             #+#    #+#             */
/*   Updated: 2025/05/15 11:06:16 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_cmd_exit_handle(const int status, t_shell *shell)
{
	ft_exit_env(&shell->env_list);
	ft_exit_temp(shell);
	ft_util_cmd_free(shell->current_cmds);
	ft_lstclear(&shell->garbage->tokens, free);
	free(shell->garbage->tokens);
	free(shell->garbage->result);
	free(shell->garbage);
	exit(status);
}

static int	ft_cmd_argument_count(const t_token *token)
{
	int	size;

	size = 0;
	while (token && token->type == TOKEN_ARG)
	{
		size++;
		token = token->next;
	}
	return (size);
}

void	ft_cmd_exit(t_shell *shell, t_env_list **env_list, t_token *token,
		char **cmds)
{
	shell->env_list = *env_list;
	shell->current_token = token;
	shell->current_cmds = cmds;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (token && token->str && !ft_util_num_isnumber(token->str))
	{
		ft_putstr_fd(ft_util_env_get(env_list, "USER"), STDERR_FILENO);
		ft_putstr_fd(": exit: ", STDERR_FILENO);
		ft_putstr_fd(token->str, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		ft_cmd_exit_handle(STATUS_EXIT, shell);
	}
	if (ft_cmd_argument_count(token) > 1)
	{
		ft_putstr_fd(ft_util_env_get(env_list, "USER"), STDERR_FILENO);
		ft_putstr_fd(": exit: too many arguments\n", STDERR_FILENO);
		shell->exit_status = STATUS_OK;
	}
	else if (!token)
		ft_cmd_exit_handle(STATUS_OK, shell);
	else
		ft_cmd_exit_handle(ft_atoi(token->str) % 256, shell);
}
