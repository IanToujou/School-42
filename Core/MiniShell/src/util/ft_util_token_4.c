/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:13:42 by ibour             #+#    #+#             */
/*   Updated: 2025/05/26 21:47:19 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_util_token_expand_additional(char *str, const int quotes[2])
{
	char	*new;
	int		j;
	int		i;

	j = 0;
	i = -1;
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - quotes[0] - quotes[1]
				+ 1));
	if (new == NULL)
		return (FALSE);
	while (str[++i])
		if (str[i] != '\'' && str[i] != '\"')
			new[j++] = str[i];
	new[j] = '\0';
	free(str);
	str = ft_strdup(new);
	if (str == NULL)
	{
		free(new);
		return (FALSE);
	}
	free(new);
	return (TRUE);
}

static t_bool	ft_util_token_expand_cmd(char *str)
{
	int	i;
	int	quotes[2];

	i = -1;
	ft_memset(quotes, 0, sizeof(int) * 2);
	while (str[++i])
	{
		if (str[i] == '\'')
			quotes[0]++;
		else if (str[i] == '\"')
			quotes[1]++;
	}
	if ((quotes[0] > 0 && quotes[0] % 2 == 0 && quotes[1] == 0)
		|| (quotes[1] > 0 && quotes[1] % 2 == 0 && quotes[0] == 0))
	{
		if (ft_util_token_expand_additional(str, quotes) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

void	ft_util_token_addon(const t_token *token)
{
	while (token)
	{
		if (token->type == TOKEN_CMD
			&& ft_util_token_expand_cmd(token->str) == false)
			ft_error_throw(ERROR_MALLOC);
		if (token->type == TOKEN_INPUT && (!token->prev
				|| token->prev->type == TOKEN_PIPE))
		{
			if (token->next && token->next->type != TOKEN_PIPE
				&& token->next->next && token->next->next->type != TOKEN_PIPE)
			{
				token->next->type = TOKEN_ARG;
				token->next->next->type = TOKEN_CMD;
			}
		}
		token = token->next;
	}
}

void	ft_util_token_cleanup(t_shell *shell, t_token *list)
{
	t_token	*current;
	t_token	*next;
	t_list	*garbage_current;
	t_list	*garbage_next;

	current = list;
	while (current)
	{
		next = current->next;
		if (current->str)
			free(current->str);
		free(current);
		current = next;
	}
	garbage_current = shell->garbage->tokens;
	while (garbage_current)
	{
		garbage_next = garbage_current->next;
		free(garbage_current);
		garbage_current = garbage_next;
	}
	shell->garbage->tokens = NULL;
}

void	ft_util_token_free(t_token *list)
{
	t_token		*tmp;
	t_token		*current;

	current = list;
	while (current)
	{
		tmp = current->next;
		if (current->str)
			free(current->str);
		free(current);
		current = tmp;
	}
}
