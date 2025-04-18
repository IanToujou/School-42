/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:44:11 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 11:44:37 by ibour            ###   ########.fr       */
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
