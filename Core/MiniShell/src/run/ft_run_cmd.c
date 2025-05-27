/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:39:27 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 11:47:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void ft_run_cmd(t_shell *shell, const t_token *token, t_env_list *env_list, char **args, const int pipe_count)
{
	if (ft_run_defined_is_defined(token))
		ft_run_defined(shell, token, env_list, args);
	else
		ft_run_bin(shell, token, env_list, pipe_count);
}

