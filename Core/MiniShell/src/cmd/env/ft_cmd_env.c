/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:17:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/04/23 15:17:58 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_cmd_env(t_shell *shell, t_env_list **env_list)
{
	t_env_list	*current;

	(void)shell;
	if (!env_list || !*env_list)
		return ;
	current = *env_list;
	while (current != NULL)
	{
		if (current->current->key && current->current->value)
		{
			ft_putstr_fd(current->current->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd(current->current->value, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		current = current->next;
	}
}
