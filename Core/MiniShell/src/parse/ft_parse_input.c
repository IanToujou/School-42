/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:29:13 by ibour             #+#    #+#             */
/*   Updated: 2025/05/22 08:36:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Parses a single character in the input string to handle quotes, escape sequences,
 * and special symbols. It ensures that the parsing state is updated based on the
 * current character and performs necessary checks on valid separators or redirection
 * symbols within the context of the user's shell input.
 *
 * @param str Pointer to the input string being parsed.
 * @param quotes Pointer to the quote tracking structure to maintain the quote context.
 * @param i Pointer to the current index of the string being processed, modified as needed.
 * @param user Pointer to the user identifier string (e.g., username) for contextual handling.
 * @return TRUE if parsing of the current character and associated checks were successful,
 *         FALSE if an error or invalid symbol sequence was encountered.
 */
static t_bool	ft_parse_input_str(const char *str, t_quotes *quotes,
	                                int *i, const char *user)
{
	static char	*pool_symbols = "\\<>|;";

	ft_util_quote_set(quotes, str[*i]);
	if (str[*i] == '\\' && quotes->two == true)
		(*i)++;
	else if (ft_util_str_strchr(pool_symbols, str[*i]) == true
		&& ft_util_quote_is_outside(quotes) == true)
	{
		if (ft_util_check_seps(str, i, user) == false
			|| ft_util_redirect_check(str, i, user) == false)
			return (FALSE);
	}
	return (TRUE);
}


/**
 * Preprocesses the input command string by iterating through the characters
 * and performing necessary checks and adjustments for parsing. It handles
 * escape sequences, quotes, and special symbols while maintaining the parsing state.
 *
 * @param input Pointer to the input command string to preprocess.
 * @param user Pointer to the user identifier string (e.g., username) for contextual handling.
 * @return TRUE if preprocessing of the input was successful, FALSE if an error or invalid state was encountered.
 */
static t_bool	ft_parse_preprocess(const char *input, const char *user)
{
	int			i;
	t_quotes	quotes;

	quotes = ft_init_quote();
	i = 0;
	while (input[i])
	{
		if (!ft_parse_input_str(input, &quotes, &i, user))
			return (FALSE);
		if (input[i] != '\0')
			i++;
	}
	return (TRUE);
}

/**
 * Parses the input command string provided by the user and processes it
 * within the context of the shell.
 *
 * @param shell Pointer to the shell structure containing the current shell state.
 * @param env_list Pointer to the linked list of environment variables.
 * @param input Pointer to the command input string provided by the user.
 * @param user Pointer to the user identifier string (e.g., username).
 * @return TRUE if the parsing and processing were successful, FALSE otherwise.
 */
t_bool	ft_parse_input(t_shell *shell, t_env_list *env_list,
	                     const char *input, const char *user)
{
	char	*result;

	if (ft_util_str_tab_skip(input))
		return (FALSE);
	result = ft_util_str_tab_trim(input);
	if (!result)
		ft_error_throw(ERROR_MALLOC);
	shell->garbage = (t_garbage *) malloc(sizeof(t_garbage));
	shell->garbage->result = result;
	shell->garbage->tokens = ft_lstnew(NULL);
	if (!ft_parse_preprocess(result, user))
	{
		free(result);
		return (FALSE);
	}
	if (!ft_parse_handle(shell, env_list, result))
		ft_error_throw(ERROR_MALLOC);
	free(result);
	free(shell->garbage->tokens);
	free(shell->garbage);
	return (TRUE);
}
