/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:37:01 by ibour             #+#    #+#             */
/*   Updated: 2025/06/05 22:26:29 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_parse_handle_clean_word(char *word)
{
	int		j;
	int		k;
	char	*clean;

	j = 0;
	k = 0;
	clean = malloc(ft_strlen(word) + 1);
	if (!clean)
		return (NULL);
	while (word[j])
	{
		if (word[j] != '"' && word[j] != '\'')
			clean[k++] = word[j];
		j++;
	}
	clean[k] = '\0';
	return (clean);
}

char	**ft_parse_handle_clean_words(char **words)
{
	int		i;
	char	*clean;

	i = 0;
	while (words[i])
	{
		clean = ft_parse_handle_clean_word(words[i]);
		if (!clean)
		{
			ft_parse_handle_free_result(words, i);
			return (NULL);
		}
		free(words[i]);
		words[i] = clean;
		i++;
	}
	return (words);
}

char	**ft_parse_handle_extract_words(const char *trimmed, int word_count)
{
	t_split_cmd	s;
	char		**result;
	int			status;

	result = (char **)malloc(sizeof(char *) * (word_count + 1));
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
	if (!result)
		return (NULL);
	result = ft_parse_handle_clean_words(result);
	return (result);
}

t_bool	ft_parse_handle_setup_pipes(int pipes[][2], int pipe_count)
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
