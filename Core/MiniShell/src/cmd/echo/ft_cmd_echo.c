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

	newline = TRUE;
	if (token && token ->str
		&& ft_strncmp(token->str, "-n", ft_strlen("-n") + 1) == 0)
	{
		newline = FALSE;
		token = token->next;
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
