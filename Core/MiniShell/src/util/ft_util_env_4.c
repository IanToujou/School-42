/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_env_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:13:07 by ibour             #+#    #+#             */
/*   Updated: 2025/05/26 18:32:05 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_util_env_update_existing(t_env_list *env_list, const char *key,
		const char *value)
{
	while (env_list)
	{
		if (ft_strncmp(env_list->current->key, key, ft_strlen(key) + 1) == 0)
		{
			free(env_list->current->value);
			env_list->current->value = ft_strdup(value);
			if (!env_list->current->value)
				ft_error_throw(ERROR_MALLOC);
			return (1);
		}
		env_list = env_list->next;
	}
	return (0);
}

static void	ft_util_env_add_new(t_env_list **env_list, const char *key,
		const char *value)
{
	char	*tmp;
	char	*env_str;

	tmp = ft_strjoin(key, "=");
	if (!tmp)
		ft_error_throw(ERROR_MALLOC);
	env_str = ft_strjoin(tmp, value);
	free(tmp);
	if (!env_str)
		ft_error_throw(ERROR_MALLOC);
	ft_util_env_var_add(env_list, env_str);
	free(env_str);
}

void	ft_util_env_set(t_env_list **env_list, const char *key,
		const char *value)
{
	if (!env_list || !key || !value)
		return ;
	if (!ft_util_env_update_existing(*env_list, key, value))
		ft_util_env_add_new(env_list, key, value);
}
