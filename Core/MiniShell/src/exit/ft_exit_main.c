/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:39:29 by ibour             #+#    #+#             */
/*   Updated: 2025/04/15 08:47:16 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_bool	ft_exit_std(const t_shell *shell)
{
	return (close(shell->std_in) != -1 && close (shell->std_out) != -1);
}

void	ft_exit_temp(const t_shell *shell)
{
	if (shell && shell->temp_file)
		free(shell->temp_file);
}

void	ft_exit_env(t_env_list **env_list)
{
	t_env_list	*temp;

	while (env_list && *env_list)
	{
		temp = (*env_list)->next;
		ft_util_env_var_remove(env_list, (*env_list)->current->key);
		*env_list = temp;
	}
}
