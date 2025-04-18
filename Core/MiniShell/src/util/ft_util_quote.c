/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:11:16 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 12:51:14 by ibour            ###   ########.fr       */
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
				if (str[i + 1] == '\"' || str[i + 1] == '$'
					|| str[i + 1] == '`' || str[i + 1] == '\\')
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
	char		*new_str;
	int			new_size;

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
				if (str[i + 1] != '"' && str[i + 1] != '`'
					&& str[i + 1] != '$' && str[i + 1] != '\\')
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

t_bool	ft_util_quote_status(t_quotes *quotes, const char c)
{
	if (c == '\'' && quotes->one == TRUE)
		quotes->one = FALSE;
	else if (c == '\'' && quotes->two == FALSE)
		quotes->one = TRUE;
	else if (c == '"' && quotes->two == TRUE)
		quotes->two = FALSE;
	else if (c == '"' && quotes->one == FALSE)
		quotes->two = TRUE;
	else
		return (FALSE);
	return (TRUE);
}

t_bool	ft_util_quote_is_outside(const t_quotes *quotes)
{
	return (quotes->two == FALSE && quotes->one == FALSE);
}
