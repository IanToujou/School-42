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

static void	ft_export_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

void	ft_cmd_export_handle_env(t_env_list **env_list, char *str)
{
	char	*equal;
	char	*key;

	equal = ft_strchr(str, '=');
	if (!equal)
	{
		if (!ft_util_env_get(env_list, str))
			ft_util_env_var_add(env_list, str);
	}
	else
	{
		key = ft_substr(str, 0, equal - str);
		if (!key)
			ft_error_throw(ERROR_MALLOC);
		ft_util_env_var_remove(env_list, key);
		ft_util_env_var_add(env_list, str);
		free(key);
	}
}

static int	ft_handle_export_arg(t_env_list **env, t_token *arg)
{
	if (!ft_is_valid_env_name(arg->str))
	{
		ft_export_error(arg->str);
		return (1);
	}
	ft_cmd_export_handle_env(env, arg->str);
	return (0);
}

static void	ft_process_export_args(t_shell *shell, t_env_list **env, t_token *args)
{
	int	has_error;

	has_error = 0;
	while (args)
	{
		has_error += ft_handle_export_arg(env, args);
		args = args->next;
	}
	if (has_error)
		shell->exit_status = EXIT_FAILURE;
	else
		shell->exit_status = EXIT_SUCCESS;
}

void	ft_cmd_export(t_shell *shell, t_env_list **env_list, t_token *args)
{
	if (!args)
	{
		ft_util_env_print_exported(*env_list);
		shell->exit_status = EXIT_SUCCESS;
		return ;
	}
	ft_process_export_args(shell, env_list, args);
}
