/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:44:11 by ibour             #+#    #+#             */
/*   Updated: 2025/05/15 09:42:55 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*ft_util_token_previous(t_token	*token)
{
	if (token && token->type >= TOKEN_TRUNC)
		token = token->prev;
	while (token && token->type < TOKEN_TRUNC)
		token = token->prev;
	return (token);
}

t_token	*ft_util_token_next(t_token	*token)
{
	if (token && token->type >= TOKEN_TRUNC)
		token = token->next;
	while (token && token->type < TOKEN_TRUNC)
		token = token->next;
	return (token);
}

t_token	*ft_util_token_create(const char *content)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		return NULL;
	token->str = ft_strdup(content);
	if (token->str == NULL)
	{
		free(token);
		return NULL;
	}
	return token;
}

void	ft_util_token_add_back(t_token **list, t_token *new)
{
	t_token	*current;

	if (!list || !new)
		return;
	if (*list == NULL)
	{
		*list = new;
		return;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
}

void	ft_util_token_free(t_token *list)
{
	t_token	*tmp;

	while (list)
	{
		tmp = list->next;
		if (list->str)
			free(list->str);
		free(list);
		list = tmp;
	}
}