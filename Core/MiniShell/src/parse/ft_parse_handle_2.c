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
