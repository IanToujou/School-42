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

void	ft_cmd_echo(t_shell *shell, t_token *args)
{
	t_token	*current;
	t_bool	newline;

	current = args;
	newline = TRUE;
	if (current && ft_strncmp(current->str, "-n", 3) == 0)
	{
		newline = FALSE;
		current = current->next;
	}
	while (current)
	{
		ft_putstr_fd(current->str, shell->std_out);
		if (current->next)
			ft_putchar_fd(' ', shell->std_out);
		current = current->next;
	}
	if (newline)
		ft_putchar_fd('\n', shell->std_out);
	shell->exit_status = STATUS_OK;
}
