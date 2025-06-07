/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:36:56 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 20:38:37 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

int	find_redirection(char **parts, char **outfile)
{
	int	i;

	i = 0;
	while (parts[i])
	{
		if (ft_strcmp(parts[i], ">") == 0)
		{
			if (parts[i + 1])
				*outfile = ft_strdup(parts[i + 1]);
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*parse_command_for_redirection(char *cmd, char **outfile)
{
	char	**parts;
	char	*result;
	int		redir_pos;

	parts = ft_split(cmd, ' ');
	if (!parts)
		return (NULL);
	redir_pos = find_redirection(parts, outfile);
	if (redir_pos != -1)
	{
		parts[redir_pos] = NULL;
		result = ft_strjoin_array(parts, " ");
	}
	else
		result = ft_strdup(cmd);
	ft_util_cmd_free(parts);
	return (result);
}
