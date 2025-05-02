/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:17:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/02 15:41:47 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*get_path(t_shell *shell, t_env_list **env, t_token *args)
{
	char	*path;

	if (!args || !args->str || (args->str[0] == '~' && !args->str[1]))
		path = ft_util_env_get(env, "HOME");
	else if (args->next)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		shell->exit_status = STATUS_MAIN;
		return (NULL);
	}
	else if (strcmp(args->str, "-") == 0)
	{
		path = ft_util_env_get(env, "OLDPWD");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			shell->exit_status = STATUS_MAIN;
			return (NULL);
		}
		ft_putstr_fd(path, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		path = args->str;
	return (path);
}

static void	update_vars(t_shell *shell, t_env_list **env, char *path,
		char *prev)
{
	if (!path || chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		shell->exit_status = STATUS_MAIN;
		free(prev);
		return ;
	}
	ft_util_env_set(env, "OLDPWD", prev);
	ft_util_env_set(env, "PWD", getcwd(NULL, 0));
	shell->exit_status = STATUS_OK;
	free(prev);
}

void	ft_cmd_cd(t_shell *shell, t_env_list **env, t_token *args)
{
	char	*path;
	char	*prev;

	prev = getcwd(NULL, 0);
	path = get_path(shell, env, args);
	if (!path)
	{
		free(prev);
		return ;
	}
	update_vars(shell, env, path, prev);
}
