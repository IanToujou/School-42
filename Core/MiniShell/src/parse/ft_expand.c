/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:29:13 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 10:28:31 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * Extracts a variable name from the input string after '$'
 * Stops at non-alphanumeric and non-underscore characters
 * If it starts with a digit, only one character is extracted
 * Returns a newly allocated string or NULL on failure
 */
char	*extract_var_name(const char *str)
{
	int	len;

	len = 0;
	if (str[len] && ft_isdigit(str[len]))
		return (ft_substr(str, 0, 1));
	while (str[len] && (ft_isalnum(str[len]) || str[len] == '_'))
		len++;
	return (ft_substr(str, 0, len));
}

/*
 * Expands a variable starting at a given index in input
 * Extracts variable name and retrieves its value from env
 * Joins the value to result and updates the index
 * Returns the updated result string
 */
static char	*expand_var_index(char *input, int *i, t_env_list *env_list,
		char *result)
{
	char	*var_name;
	char	*var_value;
	char	*temp;

	var_name = extract_var_name(input + *i + 1);
	var_value = NULL;
	if (var_name)
		var_value = ft_util_env_get(&env_list, var_name);
	if (var_value)
		temp = ft_strjoin(result, var_value);
	else
		temp = ft_strjoin(result, "");
	free(result);
	result = temp;
	if (var_name)
		*i += 1 + ft_strlen(var_name);
	else
		*i += 1;
	free(var_name);
	return (result);
}

/*
 * Expands all variables in the input string
 * Skips variables inside quotes
 * Replaces each variable with its value from env_list
 * Returns a newly allocated expanded string or NULL on failure
 */
char	*expand_variables(char *input, t_env_list *env_list)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && !is_quoted(input, i))
			result = expand_var_index(input, &i, env_list, result);
		else
		{
			temp = ft_strjoin_char(result, input[i++]);
			free(result);
			result = temp;
		}
		if (!result)
			return (NULL);
	}
	return (result);
}
