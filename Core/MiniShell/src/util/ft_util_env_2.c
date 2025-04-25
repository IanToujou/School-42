/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_env_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:13:07 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 17:13:21 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_util_env_free(t_env_list	*env_list)
{
	if (!env_list)
		return ;
	if (env_list->current)
	{
		free(env_list->current->key);
		free(env_list->current->value);
		free(env_list->current);
	}
	free(env_list);
}

void	ft_util_env_print_exported(t_env_list *env_list)
{
	while (env_list)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env_list->current->key, STDOUT_FILENO);
		if (env_list->current->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(env_list->current->value, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		env_list = env_list->next;
	}
}

int ft_is_valid_env_name(const char *str)
{
    int i;

    if (!str || !*str || *str == '=' || ft_isdigit(*str))
        return (0);
    
    i = 0;
    while (str[i] && str[i] != '=')
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
            return (0);
        i++;
    }
    return (1);
}
