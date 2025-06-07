/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_9.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:39:24 by ibour             #+#    #+#             */
/*   Updated: 2025/06/05 23:30:38 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**ft_parse_handle_redirect(char *cmd_str)
{
	char	**args;
	char	*new_cmd;
	char	*outfile;
	int		fd;

	new_cmd = parse_command_for_redirection(cmd_str, &outfile);
	if (!new_cmd)
	{
		ft_error_throw(ERROR_PARSE);
		exit(EXIT_FAILURE);
	}
	args = ft_parse_handle_split_cmd(new_cmd);
	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1 || dup2(fd, STDOUT_FILENO) == -1)
	{
		free(new_cmd);
		free(outfile);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
	free(outfile);
	free(new_cmd);
	return (args);
}

void	ft_parse_handle_execute(t_shell *shell, char *cmd_str,
		t_env_list *env_list)
{
	char	**args;

	(void)shell;
	if (strchr(cmd_str, '>'))
		args = ft_parse_handle_redirect(cmd_str);
	else
		args = ft_parse_handle_split_cmd(cmd_str);
	if (!args || !args[0])
	{
		ft_error_throw(ERROR_PARSE);
		exit(EXIT_FAILURE);
	}
	ft_util_launch_execve(env_list, args);
	ft_util_cmd_free(args);
	exit(EXIT_FAILURE);
}

void	ft_wait_for_children(pid_t *pids, int cmd_count, t_shell *shell)
{
	int	i;
	int	status;

	i = 0;
	while (i < cmd_count)
	{
		waitpid(pids[i], &status, 0);
		if (i == cmd_count - 1 && WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
		i++;
	}
}

void	ft_close_all_pipes(int pipes[11][2], int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

int	ft_count_commands(char **cmds)
{
	int	count;

	count = 0;
	while (cmds[count])
		count++;
	return (count);
}
