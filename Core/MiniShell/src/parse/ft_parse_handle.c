/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:47:10 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 13:05:42 by mwelfrin         ###   ########.fr       */
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
	char	**result;
	char	*trimmed;
	int		i;
	int		j;
	int		count;
	int		in_word;
	int		in_quotes;

	i = 0;
	j = 0;
	count = 0;
	in_word = 0;
	in_quotes = 0;
	if (!cmd_str)
		return (NULL);
	trimmed = ft_strtrim(cmd_str, " \t\n\r");
	if (!trimmed)
		return (NULL);
	while (trimmed[i])
	{
		if (trimmed[i] == '"' || trimmed[i] == '\'')
			in_quotes = !in_quotes;
		if (!in_quotes && trimmed[i] == ' ' && in_word)
			in_word = 0;
		else if (!in_quotes && trimmed[i] != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (free(trimmed), NULL);
	i = 0;
	count = 0;
	while (trimmed[i])
	{
		while (trimmed[i] && (trimmed[i] == ' ' || trimmed[i] == '|'))
			i++;
		if (!trimmed[i])
			break ;
		j = i;
		in_quotes = 0;
		while (trimmed[i] && (in_quotes || trimmed[i] != ' '))
		{
			if (trimmed[i] == '"' || trimmed[i] == '\'')
				in_quotes = !in_quotes;
			i++;
		}
		result[count] = ft_strndup(trimmed + j, i - j);
		if (!result[count])
		{
			while (--count >= 0)
				free(result[count]);
			free(result);
			free(trimmed);
			return (NULL);
		}
		count++;
	}
	result[count] = NULL;
	free(trimmed);
	return (result);
}

static t_bool	ft_handle_piped_commands(t_shell *shell, char **cmds,
		t_env_list *env_list, const int pipe_count)
{
	int		i;
	int		j;
	int		cmd_count;
	pid_t	pid;
	int		pipes[10][2];
	t_token	*token;
	char	**args;
	int		status;

	cmd_count = 0;
	while (cmds[cmd_count])
		cmd_count++;
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
	i = 0;
	while (i < cmd_count)
	{
		pid = fork();
		if (pid == -1)
			ft_error_throw(ERROR_FORK);
		if (pid == 0)
		{
			if (i > 0 && dup2(pipes[i - 1][0], STDIN_FILENO) == -1)
				ft_error_throw(ERROR_DUP2);
			if (i < cmd_count - 1 && dup2(pipes[i][1], STDOUT_FILENO) == -1)
				ft_error_throw(ERROR_DUP2);
			j = 0;
			while (j < pipe_count)
			{
				close(pipes[j][0]);
				close(pipes[j][1]);
				j++;
			}
			args = ft_split_command(cmds[i]);
			if (!args || !args[0])
			{
				fprintf(stderr, "Command parsing error\n");
				exit(EXIT_FAILURE);
			}
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
		i++;
	}
	i = 0;
	while (i < pipe_count)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	i = 0;
	while (i < cmd_count)
	{
		wait(&status);
		i++;
	}
	return (TRUE);
}

static char	**ft_split_by_pipes(char *input)
{
	int		i;
	int		start;
	int		count;
	int		in_quotes;
	char	quote_char;
	char	**result;
	char	*trimmed;

	i = 0;
	start = 0;
	count = 1;
	in_quotes = 0;
	quote_char = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			if (!in_quotes)
			{
				in_quotes = 1;
				quote_char = input[i];
			}
			else if (input[i] == quote_char)
				in_quotes = 0;
		}
		if (input[i] == '|' && !in_quotes)
			count++;
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	count = 0;
	in_quotes = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			if (!in_quotes)
			{
				in_quotes = 1;
				quote_char = input[i];
			}
			else if (input[i] == quote_char)
				in_quotes = 0;
		}
		if (input[i] == '|' && !in_quotes)
		{
			result[count] = ft_strndup(input + start, i - start);
			if (!result[count])
				return (free(result), NULL);
			trimmed = ft_strtrim(result[count], " \t\n\r");
			free(result[count]);
			result[count] = trimmed;
			count++;
			start = i + 1;
		}
		i++;
	}
	result[count] = ft_strndup(input + start, i - start);
	if (!result[count])
		return (free(result), NULL);
	trimmed = ft_strtrim(result[count], " \t\n\r");
	free(result[count]);
	result[count] = trimmed;
	result[count + 1] = NULL;
	return (result);
}

static t_bool	ft_parse_handle_process(t_shell *shell, t_parse *parse,
		t_env_list *env_list, char *str)
{
	char	**cmd;
	int		pipe_count;
	int		i;

	fflush(stdout);
	pipe_count = parse->pipe;
	cmd = ft_split_by_pipes(str);
	if (!cmd)
		return (FALSE);
	i = 0;
	while (cmd[i])
	{
		printf("  cmd[%d]: '%s'\n", i, cmd[i]);
		i++;
	}
	fflush(stdout);
	parse->begin_str = parse->i + 1;
	if (parse->flag == TRUE)
		return (ft_parse_handle_exit(cmd, shell, TRUE));
	if (pipe_count > 0)
	{
		fflush(stdout);
		if (!ft_handle_piped_commands(shell, cmd, env_list, pipe_count))
			return (ft_parse_handle_exit(cmd, shell, FALSE));
	}
	else
	{
		if (!ft_util_token_process(shell, cmd, env_list))
			return (ft_parse_handle_exit(cmd, shell, FALSE));
	}
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
