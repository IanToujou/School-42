/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:47:10 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 20:35:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_bool	ft_parse_handle_exit(char **cmd, t_shell *shell, t_bool status)
{
	int	i;

	i = -1;
	if (cmd)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
	}
	if (status)
		return (TRUE);
	shell->exit_status = STATUS_MALLOC;
	return (FALSE);
}

char	*ft_parse_handle_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = 0;
	while (len < n && s[len])
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

int	ft_parse_handle_count_words(const char *str)
{
	t_split_cmd	s;

	s.i = 0;
	s.count = 0;
	s.in_word = 0;
	s.in_quotes = 0;
	while (str[s.i])
	{
		if (str[s.i] == '"' || str[s.i] == '\'')
			s.in_quotes = !s.in_quotes;
		if (!s.in_quotes && str[s.i] == ' ' && s.in_word)
			s.in_word = 0;
		else if (!s.in_quotes && str[s.i] != ' ' && !s.in_word)
		{
			s.in_word = 1;
			s.count++;
		}
		s.i++;
	}
	return (s.count);
}

void	ft_parse_handle_free_result(char **result, int count)
{
	while (--count >= 0)
		free(result[count]);
	free(result);
}

int	ft_parse_handle_extract_word(const char *str, char **result,
	int *i, const int count)
{
	int	j;
	int	in_quotes;

	while (str[*i] && (str[*i] == ' ' || str[*i] == '|'))
		(*i)++;
	if (!str[*i])
		return (0);
	j = *i;
	in_quotes = 0;
	while (str[*i] && (in_quotes || str[*i] != ' '))
	{
		if (str[*i] == '"' || str[*i] == '\'')
			in_quotes = !in_quotes;
		(*i)++;
	}
	result[count] = ft_parse_handle_strndup(str + j, *i - j);
	if (!result[count])
		return (-1);
	return (1);
}

char	**ft_parse_handle_extract_words(const char *trimmed,
	const int word_count)
{
	t_split_cmd	s;
	char		**result;
	int			status;

	result = (char **) malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	s.i = 0;
	s.count = 0;
	while (trimmed[s.i])
	{
		status = ft_parse_handle_extract_word(trimmed, result, &s.i, s.count);
		if (status == 0)
			break ;
		if (status == -1)
		{
			ft_parse_handle_free_result(result, s.count);
			return (NULL);
		}
		s.count++;
	}
	result[s.count] = NULL;
	return (result);
}

char	**ft_parse_handle_split_cmd(const char *cmd_str)
{
	char	*trimmed;
	char	**result;
	int		word_count;

	if (!cmd_str)
		return (NULL);
	trimmed = ft_strtrim(cmd_str, " \t\n\r");
	if (!trimmed)
		return (NULL);
	word_count = ft_parse_handle_count_words(trimmed);
	result = ft_parse_handle_extract_words(trimmed, word_count);
	free(trimmed);
	return (result);
}

t_bool	ft_parse_handle_setup_pipes(int pipes[][2],
	const int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count)
	{
		if (pipe(pipes[i]) == -1)
		{
			perror("pipe creation failed");
			while (--i >= 0)
			{
				close(pipes[i][0]);
				close(pipes[i][1]);
			}
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	ft_parse_handle_close_pipes(int pipes[][2], const int pipe_count)
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

void	ft_parse_handle_setup_io(int pipes[][2], int pipe_count,
		int cmd_index, int cmd_count)
{
	int	j;

	if (cmd_index > 0 && dup2(pipes[cmd_index - 1][0], STDIN_FILENO) == -1)
		ft_error_throw(ERROR_DUP2);
	if (cmd_index < cmd_count - 1
		&& dup2(pipes[cmd_index][1], STDOUT_FILENO) == -1)
		ft_error_throw(ERROR_DUP2);
	j = 0;
	while (j < pipe_count)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
}

void	ft_parse_handle_execute(t_shell *shell, char *cmd_str,
		t_env_list *env_list)
{
	char	**args;
	t_token	*token;

	args = ft_parse_handle_split_cmd(cmd_str);
	if (!args || !args[0])
		ft_error_throw(ERROR_PARSE);
	shell->current_cmds = args;
	token = ft_util_token_create(shell, args[0]);
	if (!token)
		ft_error_throw(ERROR_TOKEN);
	token->type = TOKEN_CMD;
	ft_run_cmd(shell, token, env_list, args);
	free(token);
	ft_util_cmd_free(args);
	exit(shell->exit_status);
}

void	ft_parse_handle_spawn_pipe(t_shell *shell, char **cmds,
	t_env_list *env_list, int pipes[][2], int pipe_count, int cmd_count)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < cmd_count)
	{
		pid = fork();
		if (pid == -1)
			ft_error_throw(ERROR_FORK);
		if (pid == 0)
		{
			ft_parse_handle_setup_io(pipes, pipe_count, i, cmd_count);
			ft_parse_handle_execute(shell, cmds[i], env_list);
		}
		i++;
	}
}

void	ft_parse_handle_wait_children(const int cmd_count)
{
	int	i;
	int	status;

	i = 0;
	while (i < cmd_count)
	{
		wait(&status);
		i++;
	}
}

t_bool	ft_parse_handle_pipe_cmd(t_shell *shell, char **cmds,
		t_env_list *env_list, const int pipe_count)
{
	t_handle_pipe	s;
	int				pipes[10][2];

	s.cmd_count = 0;
	while (cmds[s.cmd_count])
		s.cmd_count++;
	if (!ft_parse_handle_setup_pipes(pipes, pipe_count))
		return (FALSE);
	ft_parse_handle_spawn_pipe(shell, cmds, env_list, pipes,
		pipe_count, s.cmd_count);
	ft_parse_handle_close_pipes(pipes, pipe_count);
	ft_parse_handle_wait_children(s.cmd_count);
	return (TRUE);
}

int	ft_parse_handle_count_segments(const char *input)
{
	t_split_pipe	s;

	s.i = 0;
	s.count = 1;
	s.in_quotes = 0;
	s.quote_char = 0;
	while (input[s.i])
	{
		if (input[s.i] == '\'' || input[s.i] == '"')
		{
			if (!s.in_quotes)
			{
				s.in_quotes = 1;
				s.quote_char = input[s.i];
			}
			else if (input[s.i] == s.quote_char)
				s.in_quotes = 0;
		}
		if (input[s.i] == '|' && !s.in_quotes)
			s.count++;
		s.i++;
	}
	return (s.count);
}

void	ft_parse_handle_update_quote(char c, int *in_quotes,
	char *quote_char)
{
	if (c == '\'' || c == '"')
	{
		if (!(*in_quotes))
		{
			*in_quotes = 1;
			*quote_char = c;
		}
		else if (c == *quote_char)
			*in_quotes = 0;
	}
}

char	*ft_parse_handle_extract_trim(const char *input,
	const int start, const int end)
{
	char	*segment;
	char	*trimmed;

	segment = ft_parse_handle_strndup(input + start, end - start);
	if (!segment)
		return (NULL);
	trimmed = ft_strtrim(segment, " \t\n\r");
	free(segment);
	return (trimmed);
}

int	ft_parse_handle_extract(const char *input,
	char **result)
{
	t_split_pipe	s;

	s.i = 0;
	s.start = 0;
	s.count = 0;
	s.in_quotes = 0;
	while (input[s.i])
	{
		ft_parse_handle_update_quote(input[s.i], &s.in_quotes, &s.quote_char);
		if (input[s.i] == '|' && !s.in_quotes)
		{
			result[s.count] = ft_parse_handle_extract_trim(input, s.start, s.i);
			if (!result[s.count])
				return (0);
			s.count++;
			s.start = s.i + 1;
		}
		s.i++;
	}
	result[s.count] = ft_parse_handle_extract_trim(input, s.start, s.i);
	if (!result[s.count])
		return (0);
	return (1);
}

char	**ft_parse_handle_split_pipes(const char *input)
{
	int		i;
	int		count;
	char	**result;

	if (!input)
		return (NULL);
	count = ft_parse_handle_count_segments(input);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	if (!ft_parse_handle_extract(input, result))
	{
		i = 0;
		while (result[i])
			free(result[i++]);
		free(result);
		return (NULL);
	}
	result[count] = NULL;
	return (result);
}

t_bool	ft_parse_handle_process(t_shell *shell, t_parse *parse,
		t_env_list *env_list, const char *str)
{
	char	**cmd;
	int		pipe_count;
	int		i;

	pipe_count = parse->pipe;
	cmd = ft_parse_handle_split_pipes(str);
	if (!cmd)
		return (FALSE);
	i = 0;
	while (cmd[i])
		i++;
	parse->begin_str = parse->i + 1;
	if (parse->flag == TRUE)
		return (ft_parse_handle_exit(cmd, shell, TRUE));
	if (pipe_count > 0)
	{
		shell->pipe_count = pipe_count;
		if (!ft_parse_handle_pipe_cmd(shell, cmd, env_list, pipe_count))
			return (ft_parse_handle_exit(cmd, shell, FALSE));
	}
	else if (!ft_util_token_process(shell, cmd, env_list))
		return (ft_parse_handle_exit(cmd, shell, FALSE));
	parse->pipe = 0;
	return (ft_parse_handle_exit(cmd, shell, TRUE));
}

t_bool	ft_parse_handle(t_shell *shell, t_env_list *env_list, char *str)
{
	t_parse	data;

	data = ft_init_parse_data();
	while (str[data.i])
	{
		ft_util_quote_status(&data.quotes, str[data.i]);
		if (str[data.i] == '\0' || (str[data.i] == ';'
				&& ft_util_quote_is_outside(&data.quotes) == TRUE)
			|| str[data.i + 1] == '\0')
		{
			data.flag = FALSE;
			if (!ft_parse_handle_process(shell, &data, env_list, str))
				return (FALSE);
		}
		if (str[data.i] == '|'
			&& ft_util_quote_is_outside(&data.quotes) == TRUE)
			data.pipe++;
		if (str[data.i] == '\\' && data.quotes.two == TRUE)
			data.i += 2;
		else if (str[data.i] != '\0')
			data.i++;
	}
	return (TRUE);
}
