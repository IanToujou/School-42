/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:11:16 by ibour             #+#    #+#             */
/*   Updated: 2025/05/08 13:46:12 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	new_size_str(const char *str, int count)
{
	int			i;
	t_quotes	quotes;

	i = -1;
	quotes = ft_init_quote();
	while (str[++i])
	{
		if (ft_util_quote_status(&quotes, str[i]) == false)
		{
			if (str[i] == '\\' && quotes.two == true)
			{
				if (str[i + 1] == '\"' || str[i + 1] == '$' || str[i + 1] == '`'
					|| str[i + 1] == '\\')
				{
					count++;
					i++;
				}
				else
					count++;
			}
			else
				count++;
		}
	}
	return (count);
}

static char	*bye_quotes(const char *str, t_quotes *quotes, int i, int j)
{
	char	*new_str;
	int		new_size;

	new_size = new_size_str(str, 0);
	new_str = (char *)ft_calloc(new_size + 1, sizeof(char));
	if (new_str == NULL)
		ft_error_throw(ERROR_MALLOC);
	while (str[++i] && j < new_size)
	{
		if (!ft_util_quote_status(quotes, str[i]))
		{
			if (str[i] == '\\' && quotes->two)
			{
				if (str[i + 1] != '"' && str[i + 1] != '`' && str[i + 1] != '$'
					&& str[i + 1] != '\\')
				{
					new_str[j++] = '\\';
				}
				i++;
			}
			new_str[j++] = str[i];
		}
	}
	new_str[j] = '\0';
	return (new_str);
}

void	ft_util_quote_plus(t_token *cmds)
{
	int			i;
	char		*temp;
	t_quotes	quotes;

	while (cmds)
	{
		i = -1;
		while (cmds->str[++i])
		{
			if (ft_util_str_strchr("\"\'", cmds->str[i]) == true)
			{
				temp = cmds->str;
				quotes = ft_init_quote();
				cmds->str = bye_quotes(temp, &quotes, -1, 0);
				free(temp);
				break ;
			}
		}
		cmds = cmds->next;
	}
}

bool	ft_util_quote_set(t_quotes *quotes, char ch)
{
	if (ch == '\'' && quotes->one == true)
		quotes->one = false;
	else if (ch == '\'' && quotes->two == false)
		quotes->one = true;
	else if (ch == '"' && quotes->two == true)
		quotes->two = false;
	else if (ch == '"' && quotes->one == false)
		quotes->two = true;
	else
		return (false);
	return (true);
}

bool	ft_util_quote_is_outside(const t_quotes *quotes)
{
	return (quotes->two == false && quotes->one == false);
}

bool	ft_util_quote_status(t_quotes *quotes, char ch)
{
	if (ch == '\'' && quotes->two == false)
		quotes->one = !quotes->one;
	else if (ch == '"' && quotes->one == false)
		quotes->two = !quotes->two;
	return (quotes->one || quotes->two);
}

bool	ft_check_seps(const char *str, int *i, const char *name)
{
	static const char	*pool_symbols = ";|";

	if (str[*i] == ';' || str[*i] == '|' || str[*i] == '\\')
	{
		if (ft_strchr_bo(pool_symbols, str[*i]) && (ft_strlen(str) == 1
				|| *i == 0))
			return (error_syntax_token(str[*i], name));
		if (str[*i] == '\\')
			return (error_syntax_token(str[*i], name));
		while (ft_is_whitespace(str[*i + 1]))
			(*i)++;
		if (str[*i] == '|' && str[*i + 1] == '\0')
			return (error_syntax_token(str[*i + 1], name));
		if (str[*i + 1] == '|' || str[*i + 1] == ';')
			return (error_syntax_token(str[*i + 1], name));
		if (str[*i] == '\\' && str[*i + 1] == '\0')
			return (error_syntax_token(str[*i], name));
	}
	return (true);
}

bool	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

bool	ft_strchr_bo(const char *s, int c)
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
