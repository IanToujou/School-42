/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:44:11 by ibour             #+#    #+#             */
/*   Updated: 2025/06/07 15:14:12 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*ft_util_token_previous(t_token *token)
{
	if (token && token->type >= TOKEN_TRUNC)
		token = token->prev;
	while (token && token->type < TOKEN_TRUNC)
		token = token->prev;
	return (token);
}

t_token	*ft_util_token_next(t_token *token)
{
	if (token && token->type >= TOKEN_TRUNC)
		token = token->next;
	while (token && token->type < TOKEN_TRUNC)
		token = token->next;
	return (token);
}

static void	set_token_type(t_token *token, const char *content)
{
	if (ft_strcmp(content, "echo") == 0)
		token->type = TOKEN_CMD;
	else
		token->type = TOKEN_ARG;
}

static char	*strip_quotes(const char *content, size_t len, char *quote_type)
{
	char	*stripped;

	if (len >= 2 && content[0] == '\'' && content[len - 1] == '\'')
	{
		*quote_type = 's';
		stripped = (char *)malloc(len - 1);
		if (stripped)
			ft_memcpy(stripped, content + 1, len - 2);
	}
	else if (len >= 2 && content[0] == '"' && content[len - 1] == '"')
	{
		*quote_type = 'd';
		stripped = (char *)malloc(len - 1);
		if (stripped)
			ft_memcpy(stripped, content + 1, len - 2);
	}
	else
		return (ft_strdup(content));
	if (stripped)
		stripped[len - 2] = '\0';
	return (stripped);
}

t_token	*ft_util_token_create(const t_shell *shell, const char *content)
{
	t_token	*new_token;
	size_t	len;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (!new_token)
		return (NULL);
	len = ft_strlen(content);
	new_token->is_quoted = FALSE;
	new_token->quote_type = 'n';
	new_token->prev = NULL;
	new_token->next = NULL;
	set_token_type(new_token, content);
	new_token->str = strip_quotes(content, len, &new_token->quote_type);
	if (new_token->quote_type != 'n')
		new_token->is_quoted = TRUE;
	if (!new_token->str)
		return (free(new_token), NULL);
	if (shell->garbage)
		ft_lstadd_back(&shell->garbage->tokens, ft_lstnew(new_token));
	return (new_token);
}
