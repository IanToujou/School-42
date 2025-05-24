/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:39:27 by ibour             #+#    #+#             */
/*   Updated: 2025/05/24 23:43:16 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_run_cmd(t_shell *shell, t_token *token, t_env_list *env_list,
		char **cmds)
{
	if (ft_run_defined_is_defined(token))
		ft_run_defined(shell, token, env_list, cmds);
	else
		ft_run_bin(shell, token, env_list);
}
