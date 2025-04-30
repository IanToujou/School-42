/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:17:40 by ibour             #+#    #+#             */
/*   Updated: 2025/04/30 19:56:50 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_util_bin_check_path(const char *command, t_env_list *env_list)
{
	char	**paths;
	char	*path;
	char	*cmd_with_slash;
	int		i;

	paths = ft_split(ft_util_env_get(&env_list, "PATH"), ':');
	cmd_with_slash = ft_strjoin("/", command);
	if ((paths == NULL && errno) || cmd_with_slash == NULL)
		ft_error_throw(ERROR_MALLOC);
	i = -1;
	while (paths && paths[++i])
	{
		path = ft_strjoin(paths[i], cmd_with_slash);
		if (path == NULL)
			ft_error_throw(ERROR_MALLOC);
		if (access(path, S_IXUSR) >= 0)
		{
			ft_util_bin_free_paths(paths, cmd_with_slash);
			return (path);
		}
		free(path);
	}
	ft_util_bin_free_paths(paths, cmd_with_slash);
	return (NULL);
}

static char	*ft_util_bin_full_path(char *command, t_env_list *env_list)
{
	char	*path;

	if (ft_strlen(command) == 0)
		return (NULL);
	path = ft_util_bin_check_path(command, env_list);
	if (path != NULL)
		return (path);
	else if (access(command, S_IXUSR) >= 0)
		return (command);
	else
		return (NULL);
}

static char	*parse_cmd(char *buffer, t_env_list *env_list)
{
	char	*full_path;

	full_path = ft_util_bin_full_path(buffer, env_list);
	if (ft_strlen(buffer) == 0
		|| (full_path == NULL && ft_util_env_get(&env_list, "PATH") != NULL))
	{
		ft_putstr_fd(ft_util_env_get(&env_list, "USER"), STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(buffer, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	}
	else if (full_path == NULL)
	{
		ft_putstr_fd(ft_util_env_get(&env_list, "USER"), STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(buffer, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	return (full_path);
}

void	ft_util_launch_execve(t_env_list *env_list, char **args)
{
	char	*full_path;
	char	**envs;

	full_path = parse_cmd(args[0], env_list);
	envs = ft_util_env_to_array(&env_list);
	if (full_path != NULL)
	{
		if (execve(full_path, args, envs) == -1)
			ft_error_throw(ERROR_EXECVE);
	}
	else
		exit(STATUS_WRONG_COMMAND);
}

void	ft_util_bin_signal(const t_token *token)
{
	if (token->type == TOKEN_CMD && ft_strnstr(token->str, "minishell",
			ft_strlen(token->str)))
	{
		signal(SIGQUIT, ft_signal_add_ignore);
		signal(SIGINT, ft_signal_add_ignore);
	}
	if (token->type == TOKEN_CMD && ft_strnstr(token->str, "cat",
			ft_strlen(token->str)))
	{
		signal(SIGINT, ft_signal_c_fork);
		signal(SIGQUIT, ft_signal_c_fork_slash);
	}
}
