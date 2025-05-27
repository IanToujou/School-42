/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:39:24 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 20:49:49 by ibour            ###   ########.fr       */
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
