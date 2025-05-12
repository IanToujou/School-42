/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_redirect2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:15:00 by ibour             #+#    #+#             */
/*   Updated: 2025/05/12 17:47:14 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_util_handle_redirections(t_shell *shell, t_token *token)
{
	char	*trimmed;

	trimmed = ft_strtrim(token->str, " ");
	if (trimmed == NULL)
		ft_error_throw(ERROR_MALLOC);
	if (shell->f_out != -1 && close(shell->f_out) == -1)
		ft_error_throw(ERROR_EXIT_STD);
	if (token->prev->type == TOKEN_TRUNC)
		shell->f_out = open(trimmed, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else
		shell->f_out = open(trimmed, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (shell->f_out == -1)
		ft_error_throw(ERROR_OPEN);
	if (dup2(shell->f_out, STDOUT_FILENO) == -1)
		ft_error_throw(ERROR_DUP2);
	if (close(shell->f_out) == -1)
		ft_error_throw(ERROR_EXIT_STD);
	else
		shell->f_out = -1;
	free(trimmed);
}

void	ft_util_handle_input(t_shell *shell, t_token *token,
		t_env_list *env_list)
{
	char	*trimmed;

	(void)env_list;
	trimmed = ft_strtrim(token->str, " ");
	if (trimmed == NULL)
		ft_error_throw(ERROR_MALLOC);
	if (shell->f_in != -1 && close(shell->f_in) == -1)
		ft_error_throw(ERROR_EXIT_STD);
	shell->f_in = open(trimmed, O_RDONLY, 0777);
	if (shell->f_in == -1)
		ft_error_throw(ERROR_OPEN);
	if (dup2(shell->f_in, STDIN_FILENO) == -1)
		ft_error_throw(ERROR_DUP2);
	if (close(shell->f_in) == -1)
		ft_error_throw(ERROR_EXIT_STD);
	else
		shell->f_in = -1;
	free(trimmed);
}

void	ft_util_handle_dobinp(t_shell *shell, t_token *token,
		t_env_list *env_list)
{
	int		fd;
	pid_t	pid;
	char	*eof;

	if (dup2(shell->std_in, STDIN_FILENO) == -1 || dup2(shell->std_out,
			STDOUT_FILENO) == -1)
		ft_error_throw(ERROR_DUP2);
	fd = open(shell->temp_file, O_TRUNC | O_CREAT | O_WRONLY, 0777);
	if (fd == -1)
		ft_error_throw(ERROR_OPEN);
	eof = ft_strjoin(token->str, "\n");
	if (eof == NULL)
		ft_error_throw(ERROR_MALLOC);
	signal(SIGINT, ft_signal_empty);
	pid = fork();
	if (pid == 0)
		ft_util_handle_child_dobinp(fd, eof);
	else if (pid > 0)
	{
		ft_util_handle_parent_dobinp(shell, fd, pid, env_list);
		free(eof);
	}
	else
		ft_error_throw(ERROR_FORK);
}

void	ft_util_handle_child_dobinp(int fd, char *eof)
{
	char	*line;

	errno = 0;
	signal(SIGINT, ft_signal_heredoc);
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, eof, ft_strlen(eof) + 1) == 0)
			break ;
		write(fd, line, ft_strlen(line));
		ft_putstr_fd("> ", STDOUT_FILENO);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}

void	ft_util_handle_parent_dobinp(t_shell *shell, int fd, pid_t pid,
		t_env_list *env_list)
{
	int		status;
	t_token	new_token;

	waitpid(pid, &status, 0);
	shell->exit_status = WEXITSTATUS(status);
	if (close(fd) == -1)
		ft_error_throw(ERROR_CLOSE);
	new_token.str = shell->temp_file;
	ft_util_handle_input(shell, &new_token, env_list);
}
