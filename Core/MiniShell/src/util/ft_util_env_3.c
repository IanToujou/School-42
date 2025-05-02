/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_env_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:42:30 by ibour             #+#    #+#             */
/*   Updated: 2025/05/02 15:54:39 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_util_env_fill_array(t_env_list **env_list, char **parsed_envs)
{
	int			i;
	t_env_list	*current;
	char		*key;
	char		*env_line;

	i = -1;
	current = *env_list;
	while (++i > -1 && current != NULL)
	{
		key = ft_strjoin(current->current->key, "=");
		if (key == NULL)
			ft_error_throw(ERROR_MALLOC);
		env_line = ft_strjoin(key, current->current->value);
		if (env_line == NULL)
			ft_error_throw(ERROR_MALLOC);
		parsed_envs[i] = env_line;
		current = current->next;
	}
	parsed_envs[i] = NULL;
}

char	**ft_util_env_to_array(t_env_list **env_list)
{
	int			i;
	t_env_list	*current;
	char		**parsed_envs;

	if (env_list == NULL)
		return (NULL);
	current = *env_list;
	i = -1;
	while (++i > -1 && current != NULL)
		current = current->next;
	parsed_envs = (char **)malloc(sizeof(char *) * (i + 1));
	if (parsed_envs == NULL)
		ft_error_throw(ERROR_MALLOC);
	ft_util_env_fill_array(env_list, parsed_envs);
	return (parsed_envs);
}
