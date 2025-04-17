/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:29:13 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 10:02:15 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * Checks if a token is a redirection type
 * Returns true for >, >>, <, or << tokens
 */
static bool	is_redirect_token(int type)
{
	return (type == TOKEN_TRUNC || type == TOKEN_APPEND || type == TOKEN_INPUT
		|| type == TOKEN_HEREDOC);
}

/*
 * Checks if a token is a word type (command or argument)
 * Used to validate redirection targets
 */
static bool	is_word_token(int type)
{
	return (type == TOKEN_CMD || type == TOKEN_ARG);
}

/*
 * Validates redirection syntax in the token list
 * Ensures redirection tokens are followed by valid words
 * Prints an error if syntax is incorrect
 * Returns false on error, true if valid
 */
static bool	validate_redirects(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		if (is_redirect_token(current->type))
		{
			if (!current->next || !is_word_token(current->next->type))
			{
				ft_putstr_fd("minishell: syntax error near unexpected token `",
					2);
				if (current->next)
					ft_putstr_fd(current->next->value, 2);
				else
					ft_putstr_fd("newline", 2);
				ft_putstr_fd("'\n", 2);
				return (false);
			}
		}
		current = current->next;
	}
	return (true);
}

/*
 * Validates pipe usage in the token list
 * Ensures no leading, trailing, or double pipes
 * Prints appropriate syntax error messages
 * Returns false on error, true if valid
 */
static bool	validate_pipes(t_token *tokens)
{
	t_token	*current;

	current = tokens;
	if (current && current->type == TOKEN_PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (false);
	}
	while (current)
	{
		if (current->type == TOKEN_PIPE)
		{
			if (!current->next || current->next->type == TOKEN_PIPE)
			{
				ft_putstr_fd("minishell: syntax error unexpected token `|'\n",
					2);
				return (false);
			}
		}
		current = current->next;
	}
	return (true);
}

/*
 * Runs overall syntax validation on token list
 * Calls checks for both redirections and pipes
 * Returns false if any validation fails
 */
bool	validate_syntax(t_token *tokens)
{
	if (!tokens)
		return (false);
	return (validate_redirects(tokens) && validate_pipes(tokens));
}
