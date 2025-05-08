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

void	ft_cmd_echo(t_shell *shell, t_token *token)
{
	t_bool	newline;
	int		i;

	newline = TRUE;
	while (token && token->type == TOKEN_ARG && token->str[0] == '-')
	{
		i = 1;
		while (token->str[i] == 'n')
			i++;
		if (i > 1 && token->str[i] == '\0')
			token = token->next;
		else
			break ;
		newline = FALSE;
	}
	while (token && token->type == TOKEN_ARG)
	{
		ft_putstr_fd(token->str, STDOUT_FILENO);
		if (token->next && token->next->type == TOKEN_ARG)
			ft_putchar_fd(' ', STDOUT_FILENO);
		token = token->next;
	}
	if (newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
	shell->exit_status = STATUS_OK;
}
