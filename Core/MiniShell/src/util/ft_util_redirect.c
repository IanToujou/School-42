/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:15:00 by ibour             #+#    #+#             */
/*   Updated: 2025/05/08 13:47:18 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	redirect_type(const char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (REDIRECT_IN_TWO);
	if (str[i] == '<')
		return (REDIRECT_IN);
	if (str[i] == '>' && str[i + 1] == '>')
		return (REDIRECT_OUT_TWO);
	if (str[i] == '>')
		return (REDIRECT_OUT);
	return (REDIRECT_EMPTY);
}

bool	ft_util_redirect_check(const char *str, int *i, const char *name)
{
	int	redirect_first;
	int	redirect_second;
	int	j;

	redirect_first = REDIRECT_EMPTY;
	redirect_second = REDIRECT_EMPTY;
	if (str[*i] == '<' || str[*i] == '>')
	{
		redirect_first = redirect_type(str, *i);
		(*i)++;
		if (redirect_first == REDIRECT_IN_TWO
			|| redirect_first == REDIRECT_IN_TWO)
			(*i)++;
		j = *i;
		while (ft_is_whitespace(str[j]))
			j++;
		if (str[j] == '\0' || str[j] == ';')
			return (error_syntax_token('\n', name));
		redirect_second = redirect_type(str, j);
		if (error_redirect_check(redirect_first, redirect_second,
				name) == false)
			return (false);
	}
	return (true);
}

int	ft_check_redirect_type(t_shell *shell, t_token *token, t_token *prev,
		t_env_list *env)
{
	int	lvl;

	lvl = PROCESS_LEVEL_DEFAULT;
	if (prev && (prev->type == TOKEN_TRUNC || prev->type == TOKEN_APPEND))
		ft_handle_redirections(shell, token);
	else if (prev && (prev->type == TOKEN_INPUT))
		ft_handle_input(shell, token, env);
	else if (prev && (prev->type == TOKEN_DOBINP))
		ft_handle_dobinp(shell, token, env);
	else if (prev && (prev->type == TOKEN_PIPE))
		lvl = ft_check_pipe_io(shell, prev);
	return (lvl);
}

int	ft_util_redirect_level(t_shell *shell, t_token *token, t_token *prev,
		t_env_list *env_list)
{
	int	level;

	level = PROCESS_LEVEL_DEFAULT;
	if (prev && (prev->type == TOKEN_TRUNC || prev->type == TOKEN_APPEND))
		ft_handle_redirections(shell, token);
	else if (prev && (prev->type == TOKEN_INPUT))
		ft_handle_input(shell, token, env_list);
	else if (prev && (prev->type == TOKEN_DOBINP))
		ft_handle_dobinp(shell, token, env_list);
	else if (prev && (prev->type == TOKEN_PIPE))
		level = ft_check_pipe_io(shell, prev);
	return (level);
}

bool	ft_prev_redirect(t_token *token)
{
	while (token && token->type != TOKEN_CMD)
	{
		if (token->type == TOKEN_TRUNC || token->type == TOKEN_APPEND)
			return (true);
		token = token->prev;
	}
	return (false);
}

void	ft_handle_redirections(t_shell *shell, t_token *token)
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

void	ft_handle_input(t_shell *shell, t_token *token, t_env_list *env_list)
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

void	ft_handle_dobinp(t_shell *shell, t_token *token, t_env_list *env_list)
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
		ft_handle_child_dobinp(fd, eof);
	else if (pid > 0)
	{
		ft_handle_parent_dobinp(shell, fd, pid, env_list);
		free(eof);
	}
	else
		ft_error_throw(ERROR_FORK);
}

void	ft_handle_child_dobinp(int fd, char *eof)
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

void	ft_handle_parent_dobinp(t_shell *shell, int fd, pid_t pid,
		t_env_list *env_list)
{
	int		status;
	t_token	new_token;

	waitpid(pid, &status, 0);
	shell->exit_status = WEXITSTATUS(status);
	if (close(fd) == -1)
		ft_error_throw(ERROR_CLOSE);
	new_token.str = shell->temp_file;
	ft_handle_input(shell, &new_token, env_list);
}

int	ft_check_pipe_io(t_shell *shell, t_token *prev)
{
	int		lvl;
	pid_t	pid;

	lvl = PROCESS_LEVEL_DEFAULT;
	if (prev && ft_prev_redirect(prev->prev))
	{
		pid = fork();
		if (pid == 0)
		{
			shell->process_level = PROCESS_LEVEL_CHILD;
			if (dup2(shell->std_out, STDOUT_FILENO) == -1)
				ft_error_throw(ERROR_DUP2);
			lvl = PROCESS_LEVEL_CHILD;
		}
		else if (pid > 0)
		{
			shell->pid = pid;
			lvl = PROCESS_LEVEL_PARENT;
		}
		else
			ft_error_throw(ERROR_FORK);
	}
	else
		lvl = ft_handle_pipe(shell);
	return (lvl);
}

int	ft_handle_pipe(t_shell *shell)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error_throw(ERROR_PIPE);
	pid = fork();
	if (pid == 0)
		return (ft_handle_child_pipe(shell, fd));
	else if (pid > 0)
		return (ft_handle_parent_pipe(shell, fd, pid));
	else
	{
		ft_error_throw(ERROR_FORK);
		return (PROCESS_LEVEL_DEFAULT);
	}
}

int	ft_handle_child_pipe(t_shell *shell, int *fd)
{
	errno = 0;
	if (close(fd[1]) == -1)
		ft_error_throw(ERROR_CLOSE);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error_throw(ERROR_DUP2);
	if (close(fd[0]) == -1)
		ft_error_throw(ERROR_CLOSE);
	shell->process_level = PROCESS_LEVEL_CHILD;
	return (PROCESS_LEVEL_CHILD);
}

int	ft_handle_parent_pipe(t_shell *shell, int *fd, pid_t pid)
{
	shell->pid = pid;
	if (close(fd[0]) == -1)
		ft_error_throw(ERROR_CLOSE);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error_throw(ERROR_DUP2);
	if (close(fd[1]) == -1)
		ft_error_throw(ERROR_CLOSE);
	return (PROCESS_LEVEL_PARENT);
}

bool	error_syntax_token(char ch, const char *name)
{
	write(2, name, ft_strlen(name) + 1);
	if (ch == '\0')
		write(2, ": these commands are not supported\n", 35);
	else if (ch == '\n')
		write(2, ": syntax error near unexpected token `newline'\n", 47);
	else if (ch == ';')
		write(2, ": syntax error near unexpected token `;'\n", 41);
	else if (ch == '\\')
		write(2, ": syntax error near unexpected token `\\'\n", 41);
	else if (ch == '|')
		write(2, ": syntax error near unexpected token `|'\n", 41);
	return (false);
}

bool	error_redirect_check(int redirect_first, int redirect_second,
		const char *name)
{
	(void)name;
	if (redirect_first == REDIRECT_IN && redirect_second == REDIRECT_IN)
		return (error_syntax_token('<', name));
	if (redirect_first == REDIRECT_OUT && redirect_second == REDIRECT_OUT)
		return (error_syntax_token('>', name));
	return (true);
}
