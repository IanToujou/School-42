/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:29:13 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 10:30:10 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * Determines the token type based on operator string
 * Supports basic shell operators like:
 * >> (APPEND)
 * << (HEREDOC)
 * >  (TRUNC)
 * <  (INPUT)
 * |  (PIPE)
 * Returns the corresponding token type or TOKEN_CMD by default
 */
int	get_token_type(char *value)
{
	const char	*operators[] = {">>", "<<", ">", "<", "|", NULL};
	const int	types[] = {TOKEN_APPEND, TOKEN_HEREDOC, TOKEN_TRUNC,
		TOKEN_INPUT, TOKEN_PIPE};
	int			i;

	i = 0;
	while (operators[i])
	{
		if (ft_strcmp(value, operators[i]) == 0)
			return (types[i]);
		i++;
	}
	return (TOKEN_CMD);
}

/*
 * Creates a new token node with given value and type
 * Allocates memory and duplicates the value string
 * Returns the new token or NULL on allocation failure
 */
t_token	*create_token(char *value, int type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = ft_strdup(value);
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	if (!new->value)
	{
		free(new);
		return (NULL);
	}
	return (new);
}

/*
 * Splits input string into tokens and builds a linked list
 * Uses ft_split_shell to separate words and operators
 * Frees memory and returns NULL on any allocation failure
 * Returns a linked list of tokens
 */
t_token	*tokenize(char *input, t_shell *shell)
{
	int		i;
	t_token	*tokens;
	char	**split;
	t_token	*new;

	(void)shell;
	tokens = NULL;
	split = ft_split_shell(input);
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		new = create_token(split[i], get_token_type(split[i]));
		if (!new)
		{
			ft_free_split(split);
			ft_free_tokens(tokens);
			return (NULL);
		}
		ft_token_add_back(&tokens, new);
		i++;
	}
	ft_free_split(split);
	return (tokens);
}
