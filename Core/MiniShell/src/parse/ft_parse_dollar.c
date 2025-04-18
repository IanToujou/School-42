/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:49:27 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 13:50:57 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_parse_dollar_size(char *str, int i)
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

static char	*key_dollar(char *str, int size, int i)
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

static char	*ft_parse_dollar_val(t_envs_lst *env, char *key)
{
	char	*tmp;
	char	*value;

	if (ft_util_env_get(&env, key) != NULL)
	{
		tmp = ft_util_env_get(&env, key);
		value = ft_strdup(tmp);
		if (value == NULL)
			ft_malloc_error();
		tmp = value;
		value = ft_strtrim(value, "\'\"");
		if (value == NULL)
			ft_malloc_error();
		free(tmp);
	}
	else
	{
		value = ft_strdup("");
		if (value == NULL)
			ft_malloc_error();
	}
	return (value);
}

char	*ft_parse_dollar(t_envs_lst *env, t_parse *parse, char *str,
						t_shell *shell)
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
	value = ft_parse_dollar_val(env, key);
	if (key)
		free(key);
	if (value == NULL)
		return (NULL);
	parse->i += parse->size;
	return (value);
}

bool	ft_parse_dollar_search(char *str)
{
	int			i;
	t_bool		root;
	t_quotes	quotes;

	quotes = ft_init_quote();
	i = -1;
	root = false;
	while (str[++i])
	{
		ft_util_quote_status(&quotes, str[i]);
		if (str[i] == '$' && ft_isblank(str[i + 1]) == false
			&& quotes.one == false)
		{
			root = true;
			break ;
		}
	}
	while (root && ft_util_str_strchr("\'\"", str[--i]))
		;
	while (root && ft_isblank(str[--i]))
		;
	if (root && str[i] && i > 0 && str[i] == '<' && str[i - 1] == '<')
		root = false;
	return (root);
}