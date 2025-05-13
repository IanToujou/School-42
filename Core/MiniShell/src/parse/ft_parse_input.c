/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:29:13 by ibour             #+#    #+#             */
/*   Updated: 2025/04/19 13:29:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_parse_input_str(const char *str,
		t_quotes *quotes, int *i, const char *user)
{
	static char	*pool_symbols = "\\<>|;";

	ft_util_quote_set(quotes, str[*i]);
	if (str[*i] == '\\' && quotes->two == true)
		(*i)++;
	else if (ft_util_str_strchr(pool_symbols, str[*i]) == true
		&& ft_util_quote_is_outside(quotes) == true)
		if (ft_util_check_seps(str, i, user) == false
			|| ft_util_redirect_check(str, i, user) == false)
			return (FALSE);
	return (TRUE);
}

static t_bool	ft_parse_exit(t_shell *shell,
		char *result, int status) {
	free(result);
	if (status == STATUS_OK)
		;
	else if (status == STATUS_MALLOC)
		shell->exit_status = STATUS_MALLOC;
	return (FALSE);
}

static t_bool	ft_parse_preprocess(char *input, char *user)
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

t_bool	ft_parse_input(t_shell *shell, t_env_list *env_list,
		const char *input, char *user)
{
	char	*result;

	if (ft_util_str_tab_skip(input))
		return (FALSE);
	result = ft_util_str_tab_trim(input);
	if (!result)
		ft_error_throw(ERROR_MALLOC);
	if (!ft_parse_preprocess(result, user))
		return (ft_parse_exit(shell, result, STATUS_OK));
	if (!ft_parse_handle(shell, env_list, result))
		ft_error_throw(ERROR_MALLOC);
	free(result);
	return (TRUE);
}