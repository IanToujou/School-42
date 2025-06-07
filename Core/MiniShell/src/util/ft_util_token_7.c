/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:13:42 by ibour             #+#    #+#             */
/*   Updated: 2025/05/26 21:47:19 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_util_token_add_back(t_token **list, t_token *new)
{
	t_token	*current;

	if (!list || !new)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
}

void	ft_util_token_delete(void *ptr)
{
	t_token	*token;

	if (!ptr)
		return ;
	token = (t_token *)ptr;
	if (token->str)
		free(token->str);
	free(token);
}
