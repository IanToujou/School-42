/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:17:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/04/23 15:17:58 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static t_token	*ft_cmd_echo_handle_n_flags(t_token *token, t_bool *newline)
{
	int	i;

	*newline = TRUE;
	while (token && token->type == TOKEN_ARG && token->str[0] == '-')
	{
		i = 1;
		while (token->str[i] == 'n')
			i++;
		if (i > 1 && token->str[i] == '\0')
		{
			*newline = FALSE;
			token = token->next;
		}
		else
			break ;
	}
	return (token);
}

static void	ft_cmd_echo_print_args(t_shell *shell, t_token *token)
{
	t_parse	parse;
	char	*expanded_str;

	while (token && token->type == TOKEN_ARG)
	{
		parse = ft_init_parse_data();
		if (ft_parse_dollar_search(token->str))
		{
			expanded_str = ft_parse_dollar(shell->env_list, &parse,
					token->str, shell);
			if (expanded_str)
			{
				ft_putstr_fd(expanded_str, STDOUT_FILENO);
				free(expanded_str);
			}
		}
		else
			ft_putstr_fd(token->str, STDOUT_FILENO);
		if (token->next && token->next->type == TOKEN_ARG)
			ft_putchar_fd(' ', STDOUT_FILENO);
		token = token->next;
	}
}

void	ft_cmd_echo(t_shell *shell, t_token *token)
{
	t_bool	newline;

	token = ft_cmd_echo_handle_n_flags(token, &newline);
	ft_cmd_echo_print_args(shell, token);
	if (newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
	shell->exit_status = STATUS_OK;
}
