/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:15:00 by ibour             #+#    #+#             */
/*   Updated: 2025/05/26 14:18:24 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool ft_error_syntax_token(char ch, const char *name)
{
    write(2, name, ft_strlen(name));
    if (ch == '\0')
        write(2, ": syntax error near unexpected token `newline'\n", 47);
    else if (ch == '\n')
        write(2, ": syntax error near unexpected token `newline'\n", 47);
    else if (ch == ';')
        write(2, ": syntax error near unexpected token `;'\n", 41);
    else if (ch == '\\')
        write(2, ": syntax error near unexpected token `\\'\n", 41);
    else if (ch == '|')
        write(2, ": syntax error near unexpected token `|'\n", 41);
    else if (ch == '&')
        write(2, ": syntax error near unexpected token `&'\n", 41);
    return (false);
}

bool	ft_error_redirect_check(int redirect_first, int redirect_second,
		const char *name)
{
	if (redirect_first != REDIRECT_EMPTY && redirect_second != REDIRECT_EMPTY)
	{
		write(2, name, ft_strlen(name) - 1);
		if (redirect_second == REDIRECT_OUT_TWO)
			write(2, ": syntax error near unexpected token `>>'\n", 42);
		else if (redirect_second == REDIRECT_OUT)
			write(2, ": syntax error near unexpected token `>'\n", 41);
		else if (redirect_second == REDIRECT_IN)
			write(2, ": syntax error near unexpected token `<'\n", 41);
		else
			write(2, ": syntax error near unexpected token `newline'\n", 47);
		return (FALSE);
	}
	return (TRUE);
}
