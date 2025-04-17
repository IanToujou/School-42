/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:29:13 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 10:02:09 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * Trims whitespace and validates input
 * Returns false for empty or allocation failure
 */
static bool	preprocess_input(char **buffer)
{
	char	*trimmed;

	trimmed = ft_strtrim(*buffer, " \t");
	if (!trimmed)
		return (false);
	if (ft_strlen(trimmed) == 0)
	{
		free(trimmed);
		return (false);
	}
	free(*buffer);
	*buffer = trimmed;
	return (true);
}

/*
 * Main parsing function for shell input
 * Handles expansion, tokenization and validation
 * Returns NULL on error with proper exit status
 */
t_token	*ft_parse(t_shell *shell, t_env_list *env_list, char *buffer)
{
	char	*processed;
	char	*expanded;
	t_token	*tokens;

	processed = ft_strdup(buffer);
	if (!processed)
		return (NULL);
	if (!preprocess_input(&processed))
	{
		free(processed);
		return (NULL);
	}
	expanded = expand_variables(processed, env_list);
	free(processed);
	if (!expanded)
		return (NULL);
	tokens = tokenize(expanded, shell);
	free(expanded);
	if (!tokens || !validate_syntax(tokens))
	{
		ft_free_tokens(tokens);
		shell->exit_status = 258;
		return (NULL);
	}
	return (tokens);
}
