/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_defined.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:40:58 by ibour             #+#    #+#             */
/*   Updated: 2025/04/19 13:33:27 by ibour            ###   ########.fr       */
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
	return (FALSE);
}

void	ft_run_defined(t_shell *shell, t_token *token, t_env_list *env_list)
{
	if (ft_strncmp(token->str, "nya", ft_strlen(token->str) + 1) == 0)
		ft_putstr_fd("Meow\n", STDOUT_FILENO);
	else if (ft_strncmp(token->str, "exit", ft_strlen(token->str) + 1) == 0)
		ft_cmd_exit(shell, &env_list, token->next);
	else if (ft_strncmp(token->str, "env", ft_strlen(token->str) + 1) == 0)
		ft_cmd_env(shell, &env_list);
	else if (ft_strncmp(token->str, "pwd", ft_strlen(token->str) + 1) == 0)
		ft_cmd_pwd(shell);
	/*else if (ft_strncmp(token->str, "echo", ft_strlen(token->str) + 1) == 0)
		ft_cmd_echo(shell, token->next);
	else if (ft_strncmp(token->str, "cd", ft_strlen(token->str) + 1) == 0)
		ft_cmd_cd(shell, &env_list, token->next);
	else if (ft_strncmp(token->str, "export", ft_strlen(token->str) + 1) == 0)
		ft_cmd_export(shell, &env_list, token->next);
	else if (ft_strncmp(token->str, "unset", ft_strlen(token->str) + 1) == 0)
		ft_cmd_unset(shell, &env_list, token->next);*/
}
