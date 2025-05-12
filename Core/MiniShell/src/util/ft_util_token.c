/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:44:11 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 15:56:06 by ibour            ###   ########.fr       */
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
	t_token	*element;

	element = (t_token *)ft_calloc(1, sizeof(t_token));
	if (element == NULL)
		return (element);
	element->str = ft_strdup(content);
	if (element->str == NULL)
	{
		free(element);
		element = NULL;
		return (NULL);
	}
	return (element);
}

void	ft_util_token_add_back(t_token **list, t_token *new)
{
	t_token	*current;
	t_token	*temp;

	current = *list;
	if (current == NULL)
		*list = new;
	else
	{
		while (current->next)
			current = current->next;
		temp = current;
		current->next = new;
		temp = current->next;
		temp->prev = current;
	}
}

void	ft_util_token_free(t_token *list)
{
	t_token	*temp;

	while (list != NULL)
	{
		temp = list->next;
		if (list->str != NULL)
			free(list->str);
		if (list != NULL)
			free(list);
		list = temp;
	}
}
