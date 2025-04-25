/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:18:23 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/04/25 09:18:24 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_cmd_unset(t_shell *shell, t_env_list **env_list, t_token *args)
{
	if (!args)
	{
		shell->exit_status = EXIT_SUCCESS;
		return ;
	}
	while (args)
	{
		ft_util_env_var_remove(env_list, args->str);
		args = args->next;
	}
	shell->exit_status = EXIT_SUCCESS;
}
