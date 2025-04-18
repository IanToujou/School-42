/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:15:00 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 11:55:30 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_util_redirect_level(t_shell *shell, t_token *token, t_token *prev, t_env_list *env_list)
{
	(void)token;
	(void)prev;
	(void)env_list;
	(void)shell;
	int	level;

	level = PROCESS_LEVEL_DEFAULT;
	/*if (prev && (prev->type == TOKEN_TRUNC || prev->type == TOKEN_APPEND))
		ft_handle_redirections(shell, token);
	else if (prev && (prev->type == TOKEN_INPUT))
		ft_handle_input(shell, token, env_list);
	else if (prev && (prev->type == TOKEN_DOBINP))
		ft_handle_dobinp(shell, token, env_list);
	else if (prev && (prev->type == TOKEN_PIPE))
		level = ft_check_pipe_io(shell, prev);*/
	return (level);
}
