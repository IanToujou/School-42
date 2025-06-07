/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:17:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/06/07 16:03:14 by mwelfrin         ###   ########.fr       */
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

void	ft_handle_escape_sequences(const char *str, int *i)
{
	(*i)++;
	if (str[*i] == '\0')
		return ;
	if (str[*i] == 'n')
		ft_putchar_fd('\n', STDOUT_FILENO);
	else if (str[*i] == 't')
		ft_putchar_fd('\t', STDOUT_FILENO);
	else if (str[*i] == 'r')
		ft_putchar_fd('\r', STDOUT_FILENO);
	else if (str[*i] == '\\')
		ft_putchar_fd('\\', STDOUT_FILENO);
	else
	{
		ft_putchar_fd('\\', STDOUT_FILENO);
		ft_putchar_fd(str[*i], STDOUT_FILENO);
	}
	(*i)++;
}

static t_bool	has_redirection(t_token *token)
{
	while (token)
	{
		if (token->type == REDIRECT_OUT || token->type == REDIRECT_OUT_TWO)
			return (TRUE);
		token = token->next;
	}
	return (FALSE);
}

void	ft_print_quoted_single(t_shell *shell, char *str)
{
	int	i;

	i = 0;
	if (shell->is_redirected)
	{
		while (str[i])
		{
			if (str[i] == '\\')
				ft_handle_escape_sequences(str, &i);
			else
				ft_putchar_fd(str[i++], STDOUT_FILENO);
		}
	}
	else
	{
		while (str[i])
			ft_putchar_fd(str[i++], STDOUT_FILENO);
	}
}

void	ft_cmd_echo(t_shell *shell, t_token *token)
{
	t_bool	newline;

	shell->is_redirected = has_redirection(token);
	token = ft_cmd_echo_handle_n_flags(token, &newline);
	ft_cmd_echo_print_args(shell, token);
	if (newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
	shell->exit_status = STATUS_OK;
}
