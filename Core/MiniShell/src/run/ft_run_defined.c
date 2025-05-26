/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_defined.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:40:58 by ibour             #+#    #+#             */
/*   Updated: 2025/05/24 23:42:35 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_bool	ft_run_defined_is_defined(const t_token *token)
{
	if (ft_strlen(token->str) == 0)
		return (FALSE);
	if (ft_strncmp(token->str, "exit", ft_strlen(token->str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(token->str, "nya", ft_strlen(token->str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(token->str, "env", ft_strlen(token->str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(token->str, "echo", ft_strlen(token->str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(token->str, "pwd", ft_strlen(token->str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(token->str, "cd", ft_strlen(token->str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(token->str, "export", ft_strlen(token->str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(token->str, "unset", ft_strlen(token->str) + 1) == 0)
		return (TRUE);
	if (ft_strncmp(token->str, ":", ft_strlen(token->str) + 1) == 0)
		return (TRUE);
	return (FALSE);
}

void	ft_run_defined(t_shell *shell, const t_token *token,
		t_env_list *env_list, char **cmds)
{
	if (ft_strncmp(token->str, "nya", ft_strlen(token->str) + 1) == 0)
		ft_cmd_nya();
	else if (ft_strncmp(token->str, "exit", ft_strlen(token->str) + 1) == 0)
		ft_cmd_exit(shell, &env_list, token->next, cmds);
	else if (ft_strncmp(token->str, "env", ft_strlen(token->str) + 1) == 0)
		ft_cmd_env(shell, &env_list);
	else if (ft_strncmp(token->str, "pwd", ft_strlen(token->str) + 1) == 0)
		ft_cmd_pwd(shell);
	else if (ft_strncmp(token->str, "echo", ft_strlen(token->str) + 1) == 0)
		ft_cmd_echo(shell, token->next);
	else if (ft_strncmp(token->str, "cd", ft_strlen(token->str) + 1) == 0)
		ft_cmd_cd(shell, &env_list, token->next);
	else if (ft_strncmp(token->str, "export", ft_strlen(token->str) + 1) == 0)
		ft_cmd_export(shell, &env_list, token->next);
	else if (ft_strncmp(token->str, "unset", ft_strlen(token->str) + 1) == 0)
		ft_cmd_unset(shell, &env_list, token->next);
	else if (ft_strncmp(token->str, ":", ft_strlen(token->str) + 1) == 0)
		return ;
}
