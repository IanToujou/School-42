/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:39:27 by ibour             #+#    #+#             */
/*   Updated: 2025/05/15 11:30:27 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_run_cmd(t_shell *shell, t_token *token, t_env_list *env_list, char **cmds)
{
	if (ft_run_defined_is_defined(token))
		ft_run_defined(shell, token, env_list, cmds);
	else
		ft_run_bin(shell, token, env_list);
}
