/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:49:27 by ibour             #+#    #+#             */
/*   Updated: 2025/06/07 15:07:28 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_parse_dollar_size(const char *str, int i)
{
	static char	*pool_symbols = "\"\'$/-*#=\t: ";
	int			size;

	size = 0;
	if (str[i] == '$')
		i++;
	while (ft_util_str_strchr(pool_symbols, str[i]) == false && str[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static char	*key_dollar(const char *str, const int size, int i)
{
	char	*name_variable;
	int		j;

	name_variable = (char *)ft_calloc(size + 1, sizeof(char));
	if (name_variable == NULL)
		return (NULL);
	j = 0;
	if (str[i] == '$')
		i++;
	while (str[i] != '\0' && j < size)
		name_variable[j++] = str[i++];
	name_variable[j] = '\0';
	return (name_variable);
}

static char	*ft_parse_dollar_val(t_env_list *env_list, char *key)
{
	char	*value;

	if (ft_util_env_get(&env_list, key) != NULL)
	{
		value = ft_strdup(ft_util_env_get(&env_list, key));
		if (value == NULL)
			ft_error_throw(ERROR_MALLOC);
	}
	else
	{
		value = ft_strdup("");
		if (value == NULL)
			ft_error_throw(ERROR_MALLOC);
	}
	return (value);
}

char	*ft_parse_dollar(t_env_list *env_list, t_parse *parse,
			const char *str, const t_shell *shell)
{
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	if (!ft_isalpha(str[parse->i + 1]) && str[parse->i + 1] != '_')
	{
		parse->i++;
		if (str[parse->i] == '?')
			return (ft_itoa(shell->exit_status));
		return (ft_strdup("$"));
	}
	parse->size = ft_parse_dollar_size(str, parse->i);
	key = key_dollar(str, parse->size, parse->i);
	if (key == NULL)
		return (NULL);
	value = ft_parse_dollar_val(env_list, key);
	if (key)
		free(key);
	if (value == NULL)
		return (NULL);
	parse->i += parse->size;
	return (value);
}

t_bool	ft_parse_dollar_search(const char *str)
{
	int			i;
	t_quotes	quotes;

	i = 0;
	quotes = ft_init_quote();
	while (str[i])
	{
		ft_util_quote_status(&quotes, str[i]);
		if (str[i] == '$' && !quotes.one
			&& !ft_isblank(str[i + 1]) && str[i + 1] != '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}
