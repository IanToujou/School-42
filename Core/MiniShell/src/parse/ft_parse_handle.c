/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:47:10 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 20:39:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
