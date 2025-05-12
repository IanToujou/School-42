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

static int	ft_util_size_str(const char *str, int count)
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

static char	*ft_util_bye_quotes(const char *str, t_quotes *quotes, int i, int j)
{
	char	*new_str;
	int		new_size;

	new_size = ft_util_size_str(str, 0);
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
				cmds->str = ft_util_bye_quotes(temp, &quotes, -1, 0);
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
