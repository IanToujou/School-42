/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:17:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/05/26 18:23:03 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*get_current_dir(t_env_list **env)
{
	char	buffer[PATH_MAX];
	char	*dir;

	dir = getcwd(buffer, PATH_MAX);
	if (!dir)
		dir = ft_strdup(ft_util_env_get(env, "PWD"));
	else
		dir = ft_strdup(dir);
	if (!dir)
	{
		ft_putstr_fd("minishell: cd: getcwd failed: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	return (dir);
}

static char	*get_target_path(t_shell *s, t_env_list **env, t_token *args)
{
	char	*oldpwd;

	if (!args || !args->str || (args->str[0] == '~' && !args->str[1]))
		return (ft_util_env_get(env, "HOME"));
	if (args->next)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		s->exit_status = STATUS_MAIN;
		return (NULL);
	}
	if (!strcmp(args->str, "-"))
	{
		oldpwd = ft_util_env_get(env, "OLDPWD");
		if (!oldpwd)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			s->exit_status = STATUS_MAIN;
			return (NULL);
		}
		ft_putstr_fd(oldpwd, 1);
		ft_putstr_fd("\n", 1);
		return (oldpwd);
	}
	return (args->str);
}

static int	handle_chdir(t_shell *s, char *path)
{
	if (!path || chdir(path))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		s->exit_status = STATUS_MAIN;
		return (0);
	}
	return (1);
}

static void	update_pwd_and_oldpwd(t_env_list **env, char *prev)
{
	char	*cur;

	cur = getcwd(NULL, 0);
	if (cur)
	{
		ft_util_env_set(env, "OLDPWD", prev);
		ft_util_env_set(env, "PWD", cur);
		free(cur);
	}
}

void	ft_cmd_cd(t_shell *s, t_env_list **env, t_token *args)
{
	char	*prev;
	char	*path;

	prev = get_current_dir(env);
	if (!prev)
	{
		s->exit_status = STATUS_MAIN;
		return ;
	}
	path = get_target_path(s, env, args);
	if (!path || !handle_chdir(s, path))
	{
		free(prev);
		return ;
	}
	update_pwd_and_oldpwd(env, prev);
	free(prev);
	s->exit_status = STATUS_OK;
}
