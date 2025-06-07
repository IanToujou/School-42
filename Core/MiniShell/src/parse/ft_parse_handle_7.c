/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:39:24 by ibour             #+#    #+#             */
/*   Updated: 2025/06/06 09:46:28 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_extract_redirection(char *cmd, char **input_file)
{
	char	*cmd_part;
	char	*redirect_part;
	char	*end;

	cmd_part = strdup(cmd);
	redirect_part = strchr(cmd_part, '<');
	*redirect_part = '\0';
	redirect_part++;
	while (*redirect_part == ' ')
		redirect_part++;
	end = redirect_part;
	while (*end && *end != ' ')
		end++;
	*end = '\0';
	*input_file = strdup(redirect_part);
	return (cmd_part);
}

t_bool	ft_setup_input_redirection(char **cmd)
{
	char	*cmd_part;
	char	*input_file;
	int		fd_in;

	if (!strchr(*cmd, '<'))
		return (TRUE);
	cmd_part = ft_extract_redirection(*cmd, &input_file);
	*cmd = strdup(cmd_part);
	free(cmd_part);
	fd_in = open(input_file, O_RDONLY);
	free(input_file);
	if (fd_in == -1)
		return (FALSE);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	return (TRUE);
}

char	*rebuild_command(char **parts)
{
	char	*joined;

	joined = ft_strjoin_array(parts, " ");
	return (joined);
}

int	handle_redirection(char *cmd, int *fd_out)
{
	char	**parts;
	char	*joined;
	int		status;

	parts = ft_split(cmd, ' ');
	if (!parts)
		return (0);
	status = open_redirection_file(parts, fd_out);
	if (!status)
	{
		ft_util_cmd_free(parts);
		return (0);
	}
	joined = rebuild_command(parts);
	ft_util_cmd_free(parts);
	if (!joined)
		return (0);
	free(cmd);
	cmd = joined;
	return (1);
}

void	ft_execute_child(t_execute_child_info *info)
{
	char	**args;

	ft_setup_child_pipes(info->pipes, info->i, info->cmd_count);
	if (info->i == 0 && !ft_setup_input_redirection(&info->cmds[info->i]))
		exit(EXIT_FAILURE);
	args = ft_parse_handle_split_cmd(info->cmds[info->i]);
	if (!args)
		exit(EXIT_FAILURE);
	ft_util_launch_execve(info->env_list, args);
	ft_util_cmd_free(args);
	exit(EXIT_FAILURE);
}
