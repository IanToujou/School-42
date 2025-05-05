/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:18:23 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/04/25 09:18:24 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	is_valid_env_var(char *str)
{
	int	i;

	if (!str || str[0] == '=' || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	unset_var(t_shell *shell, t_env_list **env_list, char *var)
{
	if (is_valid_env_var(var))
		ft_util_env_var_remove(env_list, var);
	else
	{
		ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
		ft_putstr_fd(var, STDERR_FILENO);
		ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
		shell->exit_status = STATUS_WRONG_COMMAND;
	}
}

void	ft_cmd_unset(t_shell *shell, t_env_list **env_list, t_token *args)
{
	if (!args)
	{
		ft_putstr_fd("minishell: unset: not enough arguments\n", STDERR_FILENO);
		shell->exit_status = STATUS_WRONG_COMMAND;
		return ;
	}
	shell->exit_status = STATUS_OK;
	while (args)
	{
		unset_var(shell, env_list, args->str);
		args = args->next;
	}
}
