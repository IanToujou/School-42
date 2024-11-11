/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:45:15 by ibour             #+#    #+#             */
/*   Updated: 2024/11/11 08:29:56 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static char	*ft_find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	ft_process_execute(char *argv, char **envp)
{
	char	**command;
	int		i;
	char	*path;

	i = -1;
	command = ft_split(argv, ' ');
	path = ft_find_path(command[0], envp);
	if (!path)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		ft_throw_error(ERROR_PATH);
	}
	if (execve(path, command, envp) == -1)
		ft_throw_error(ERROR_EXECUTE);
}
