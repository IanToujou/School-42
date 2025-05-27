/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:47:10 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 15:09:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_parse_handle_exit(char **cmd, t_shell *shell, t_bool status)
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

char	*ft_strndup(const char *s, size_t n)
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

static char	**ft_split_command(const char *cmd_str)
{
	t_split_cmd	s;
	char		**result;
	char		*trimmed;

	s.i = 0;
	s.j = 0;
	s.count = 0;
	s.in_word = 0;
	s.in_quotes = 0;
	if (!cmd_str)
		return (NULL);
	trimmed = ft_strtrim(cmd_str, " \t\n\r");
	if (!trimmed)
		return (NULL);
	while (trimmed[s.i])
	{
		if (trimmed[s.i] == '"' || trimmed[s.i] == '\'')
			s.in_quotes = !s.in_quotes;
		if (!s.in_quotes && trimmed[s.i] == ' ' && s.in_word)
			s.in_word = 0;
		else if (!s.in_quotes && trimmed[s.i] != ' ' && !s.in_word)
		{
			s.in_word = 1;
			s.count++;
		}
		s.i++;
	}
	result = (char **)malloc(sizeof(char *) * (s.count + 1));
	if (!result)
		return (free(trimmed), NULL);
	s.i = 0;
	s.count = 0;
	while (trimmed[s.i])
	{
		while (trimmed[s.i] && (trimmed[i] == ' ' || trimmed[i] == '|'))
			s.i++;
		if (!trimmed[s.i])
			break ;
		s.j = s.i;
		s.in_quotes = 0;
		while (trimmed[s.i] && (s.in_quotes || trimmed[s.i] != ' '))
		{
			if (trimmed[s.i] == '"' || trimmed[s.i] == '\'')
				s.in_quotes = !s.in_quotes;
			s.i++;
		}
		result[s.count] = ft_strndup(trimmed + s.j, s.i - s.j);
		if (!result[s.count])
		{
			while (--s.count >= 0)
				free(result[s.count]);
			free(result);
			free(trimmed);
			return (NULL);
		}
		s.count++;
	}
	result[s.count] = NULL;
	free(trimmed);
	return (result);
}

static t_bool	ft_handle_piped_commands(t_shell *shell, char **cmds,
		t_env_list *env_list, const int pipe_count)
{
	t_handle_pipe	s;
	int				pipes[10][2];
	t_token			*token;
	char			**args;
	int				status;

	s.cmd_count = 0;
	while (cmds[s.cmd_count])
		s.cmd_count++;
	s.i = 0;
	while (s.i < pipe_count)
	{
		if (pipe(pipes[s.i]) == -1)
		{
			perror("pipe creation failed");
			while (--s.i >= 0)
			{
				close(pipes[s.i][0]);
				close(pipes[s.i][1]);
			}
			return (FALSE);
		}
		s.i++;
	}
	s.i = 0;
	while (s.i < s.cmd_count)
	{
		s.pid = fork();
		if (s.pid == -1)
			ft_error_throw(ERROR_FORK);
		if (s.pid == 0)
		{
			if (s.i > 0 && dup2(pipes[s.i - 1][0], STDIN_FILENO) == -1)
				ft_error_throw(ERROR_DUP2);
			if (s.i < s.cmd_count - 1 && dup2(pipes[s.i][1], STDOUT_FILENO) == -1)
				ft_error_throw(ERROR_DUP2);
			s.j = 0;
			while (s.j < pipe_count)
			{
				close(pipes[s.j][0]);
				close(pipes[s.j][1]);
				s.j++;
			}
			args = ft_split_command(cmds[s.i]);
			if (!args || !args[0])
				ft_error_throw(ERROR_PARSE);
			shell->current_cmds = args;
			token = ft_util_token_create(shell, args[0]);
			if (!token)
				ft_error_throw(ERROR_TOKEN);
			token->type = TOKEN_CMD;
			ft_run_cmd(shell, token, env_list, args, pipe_count);
			free(token);
			ft_util_cmd_free(args);
			exit(shell->exit_status);
		}
		s.i++;
	}
	s.i = 0;
	while (s.i < pipe_count)
	{
		close(pipes[s.i][0]);
		close(pipes[s.i][1]);
		s.i++;
	}
	s.i = 0;
	while (s.i < s.cmd_count)
	{
		wait(&status);
		s.i++;
	}
	return (TRUE);
}

static char	**ft_split_by_pipes(const char *input)
{
	t_split_pipe	s;
	char			**result;
	char			*trimmed;

	s.i = 0;
	s.start = 0;
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
	result = (char **)malloc(sizeof(char *) * (s.count + 1));
	if (!result)
		return (NULL);
	s.i = 0;
	s.count = 0;
	s.in_quotes = 0;
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
		{
			result[s.count] = ft_strndup(input + s.start, s.i - s.start);
			if (!result[s.count])
				return (free(result), NULL);
			trimmed = ft_strtrim(result[s.count], " \t\n\r");
			free(result[s.count]);
			result[s.count] = trimmed;
			s.count++;
			s.start = s.i + 1;
		}
		s.i++;
	}
	result[s.count] = ft_strndup(input + s.start, s.i - s.start);
	if (!result[s.count])
		return (free(result), NULL);
	trimmed = ft_strtrim(result[s.count], " \t\n\r");
	free(result[s.count]);
	result[s.count] = trimmed;
	result[s.count + 1] = NULL;
	return (result);
}

static t_bool	ft_parse_handle_process(t_shell *shell, t_parse *parse,
		t_env_list *env_list, const char *str)
{
	char	**cmd;
	int		pipe_count;
	int		i;

	pipe_count = parse->pipe;
	cmd = ft_split_by_pipes(str);
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
		if (!ft_handle_piped_commands(shell, cmd, env_list, pipe_count))
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
