/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_quote2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:11:16 by ibour             #+#    #+#             */
/*   Updated: 2025/05/26 16:14:57 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	ft_util_quote_status(t_quotes *quotes, char ch)
{
	if (ch == '\'' && !quotes->two)
		quotes->one = !quotes->one;
	else if (ch == '"' && !quotes->one)
		quotes->two = !quotes->two;
	quotes->none = !(quotes->one || quotes->two);
	return (quotes->one || quotes->two);
}

bool	ft_util_check_seps(const char *str, int *i, const char *name)
{
	static const char	*pool_symbols = ";|&";

	if (str[*i] == ';' || str[*i] == '|' || str[*i] == '\\' || str[*i] == '&')
	{
		if (ft_util_strchr(pool_symbols, str[*i]) && (ft_strlen(str) == 1
				|| *i == 0))
			return (ft_error_syntax_token(str[*i], name));
		if (str[*i] == '\\')
			return (ft_error_syntax_token(str[*i], name));
		while (ft_util_is_whitespace(str[*i + 1]))
			(*i)++;
		if (str[*i] == '|' && str[*i + 1] == '\0')
			return (ft_error_syntax_token(str[*i + 1], name));
		if (str[*i + 1] == '|' || str[*i + 1] == ';' || str[*i + 1] == '&')
			return (ft_error_syntax_token(str[*i + 1], name));
		if (str[*i] == '\\' && str[*i + 1] == '\0')
			return (ft_error_syntax_token(str[*i], name));
		if (str[*i] == '&' && str[*i + 1] == '&')
			return (ft_error_syntax_token('&', name));
		if (str[*i] == '&' && (str[*i + 1] == '\0'
				|| !ft_util_is_whitespace(str[*i + 1])))
			return (ft_error_syntax_token('&', name));
	}
	return (true);
}

bool	ft_util_is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

bool	ft_util_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (true);
		i++;
	}
	if (c == '\0')
		return (true);
	return (false);
}
