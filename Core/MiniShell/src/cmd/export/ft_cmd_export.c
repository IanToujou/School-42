/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:18:07 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/04/25 09:18:09 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_cmd_args(t_env_list **env_list, t_token *args, int *all_valid)
{
	while (args)
	{
		if (!ft_is_valid_env_name(args->str))
		{
			ft_putstr_fd("minishell: export: `", STDERR_FILENO);
			ft_putstr_fd(args->str, STDERR_FILENO);
			ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
			*all_valid = 0;
		}
		else
			ft_cmd_export_handle_env(env_list, args->str);
		args = args->next;
	}
}

void	ft_cmd_export(t_shell *shell, t_env_list **env_list, t_token *args)
{
	int	all_valid;

	if (!args)
	{
		ft_util_env_print_exported(*env_list);
		shell->exit_status = STATUS_OK;
		return ;
	}
	all_valid = 1;
	ft_cmd_args(env_list, args, &all_valid);
	if (all_valid)
		shell->exit_status = STATUS_OK;
	else
		shell->exit_status = STATUS_MAIN;
}

void	ft_cmd_export_handle_env(t_env_list **env_list, char *str)
{
	char	*equal_sign;
	char	*key;

	equal_sign = ft_strchr(str, '=');
	if (!equal_sign)
	{
		if (!ft_util_env_get(env_list, str))
			ft_util_env_var_add(env_list, str);
		return ;
	}
	key = ft_substr(str, 0, equal_sign - str);
	if (!key)
		ft_error_throw(STATUS_MALLOC);
	ft_util_env_var_remove(env_list, key);
	ft_util_env_var_add(env_list, str);
	free(key);
}
