/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:15:00 by ibour             #+#    #+#             */
/*   Updated: 2025/05/08 13:47:18 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_util_redirect_type(const char *str, int i)
{
	if (str[i] == '<' && str[i + 1] == '<')
		return (REDIRECT_IN_TWO);
	if (str[i] == '<')
		return (REDIRECT_IN);
	if (str[i] == '>' && str[i + 1] == '>')
		return (REDIRECT_OUT_TWO);
	if (str[i] == '>')
		return (REDIRECT_OUT);
	return (REDIRECT_EMPTY);
}

bool	ft_util_redirect_check(const char *str, int *i, const char *name)
{
	int	redirect_first;
	int	redirect_second;
	int	j;

	redirect_first = REDIRECT_EMPTY;
	redirect_second = REDIRECT_EMPTY;
	if (str[*i] == '<' || str[*i] == '>')
	{
		redirect_first = ft_util_redirect_type(str, *i);
		(*i)++;
		if (redirect_first == REDIRECT_IN_TWO
			|| redirect_first == REDIRECT_IN_TWO)
			(*i)++;
		j = *i;
		while (ft_util_is_whitespace(str[j]))
			j++;
		if (str[j] == '\0' || str[j] == ';')
			return (ft_error_syntax_token('\n', name));
		redirect_second = ft_util_redirect_type(str, j);
		if (ft_error_redirect_check(redirect_first, redirect_second,
				name) == false)
			return (false);
	}
	return (true);
}

int	ft_util_redirect_level(t_shell *shell, t_token *token, t_token *prev,
		t_env_list *env_list)
{
	int	level;

	level = PROCESS_LEVEL_DEFAULT;
	if (prev && (prev->type == TOKEN_TRUNC || prev->type == TOKEN_APPEND))
		ft_util_handle_redirections(shell, token);
	else if (prev && (prev->type == TOKEN_INPUT))
		ft_util_handle_input(shell, token, env_list);
	else if (prev && (prev->type == TOKEN_DOBINP))
		ft_util_handle_dobinp(shell, token, env_list);
	else if (prev && (prev->type == TOKEN_PIPE))
		level = ft_util_check_pipe_io(shell, prev);
	return (level);
}

bool	ft_util_prev_redirect(t_token *token)
{
	while (token && token->type != TOKEN_CMD)
	{
		if (token->type == TOKEN_TRUNC || token->type == TOKEN_APPEND)
			return (true);
		token = token->prev;
	}
	return (false);
}
