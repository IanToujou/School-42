/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:37:01 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 20:38:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
