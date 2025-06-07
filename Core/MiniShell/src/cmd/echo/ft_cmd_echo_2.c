/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_echo_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:17:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/06/07 16:03:04 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	ft_print_quoted_double_expanded(t_shell *shell, char *expanded_str)
{
	int	i;

	i = 0;
	if (shell->is_redirected)
	{
		while (expanded_str[i])
		{
			if (expanded_str[i] == '\\')
				ft_handle_escape_sequences(expanded_str, &i);
			else
				ft_putchar_fd(expanded_str[i++], STDOUT_FILENO);
		}
	}
	else
	{
		while (expanded_str[i])
			ft_putchar_fd(expanded_str[i++], STDOUT_FILENO);
	}
}

static void	ft_print_quoted_double(t_shell *shell, char *str)
{
	t_parse	parse;
	char	*expanded_str;

	parse = ft_init_parse_data();
	if (ft_parse_dollar_search(str))
	{
		expanded_str = ft_parse_dollar(shell->env_list, &parse, str, shell);
		if (expanded_str)
		{
			ft_print_quoted_double_expanded(shell, expanded_str);
			free(expanded_str);
		}
	}
	else
		ft_print_quoted_single(shell, str);
}

static void	ft_print_unquoted_expanded(t_shell *shell, char *expanded_str)
{
	int	i;

	i = 0;
	if (shell->is_redirected)
	{
		while (expanded_str[i])
		{
			if (expanded_str[i] == '\\')
				ft_handle_escape_sequences(expanded_str, &i);
			else
				ft_putchar_fd(expanded_str[i++], STDOUT_FILENO);
		}
	}
	else
	{
		while (expanded_str[i])
			ft_putchar_fd(expanded_str[i++], STDOUT_FILENO);
	}
}

static void	ft_print_unquoted(t_shell *shell, char *str)
{
	t_parse	parse;
	char	*expanded_str;

	parse = ft_init_parse_data();
	if (ft_parse_dollar_search(str))
	{
		expanded_str = ft_parse_dollar(shell->env_list, &parse, str, shell);
		if (expanded_str)
		{
			ft_print_unquoted_expanded(shell, expanded_str);
			free(expanded_str);
		}
	}
	else
		ft_print_quoted_single(shell, str);
}

void	ft_cmd_echo_print_args(t_shell *shell, t_token *token)
{
	char	*tmp;

	while (token && token->type == TOKEN_ARG)
	{
		if (token->is_quoted && token->quote_type == 's')
		{
			tmp = ft_strdup(token->str);
			if (tmp)
				ft_print_quoted_single(shell, tmp);
			free(tmp);
		}
		else if (token->is_quoted && token->quote_type == 'd')
		{
			tmp = ft_strdup(token->str);
			if (tmp)
				ft_print_quoted_double(shell, tmp);
			free(tmp);
		}
		else
			ft_print_unquoted(shell, token->str);
		if (token->next && token->next->type == TOKEN_ARG)
			ft_putchar_fd(' ', STDOUT_FILENO);
		token = token->next;
	}
}
