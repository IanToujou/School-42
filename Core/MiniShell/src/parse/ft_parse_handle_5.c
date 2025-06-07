/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:39:24 by ibour             #+#    #+#             */
/*   Updated: 2025/06/04 14:55:42 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_parse_handle_update_quote(const char c,
	int *in_quotes, char *quote_char)
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

void	execute_with_redirection(t_shell *shell, char *cmd,
	t_env_list *env_list)
{
	int	fd_out;

	fd_out = -1;
	if (!handle_redirection(cmd, &fd_out))
		exit(EXIT_FAILURE);
	if (fd_out != -1)
	{
		if (dup2(fd_out, STDOUT_FILENO) == -1)
		{
			close(fd_out);
			exit(EXIT_FAILURE);
		}
		close(fd_out);
	}
	ft_parse_handle_execute(shell, cmd, env_list);
}

void	ft_parse_handle_free_result(char **result, int count)
{
	while (--count >= 0)
		free(result[count]);
	free(result);
}

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
