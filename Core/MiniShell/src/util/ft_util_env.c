/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:35:16 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 17:13:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Creates a new environment variable key-value pair by
 * splitting it.
 *
 * @param var The key-value pair in "key=value" format.
 * @return A new key-value pair.
 * @throws ERROR_MALLOC In case allocating memory fails.
 */
static t_env	*ft_util_env_var_create(const char *var)
{
	int		i;
	int		j;
	t_env	*new;

	new = (t_env *) malloc(sizeof(t_env));
	if (!new)
		ft_error_throw(ERROR_MALLOC);
	i = 0;
	while (var[i] != '=')
		i++;
	new->key = ft_substr(var, 0, i);
	if (!new->key)
		ft_error_throw(ERROR_MALLOC);
	j = i + 1;
	while (var[j] != '\0' && var[j] != '\n')
		j++;
	new->value = ft_substr(var, i + 1, j - i);
	if (!new->value)
		ft_error_throw(ERROR_MALLOC);
	return (new);
}

/**
 * Creates a new environment variable list if none is
 * present, and assigns the given key-value pair to it.
 *
 * @param var The first key-value pair.
 * @return A new environment variable struct.
 */
static t_env_list	*ft_util_env_list(const char *var)
{
	t_env_list	*new;

	new = (t_env_list *) malloc(sizeof(t_env_list));
	if (new == NULL)
		ft_error_throw(ERROR_MALLOC);
	new->current = ft_util_env_var_create(var);
	new->next = NULL;
	return (new);
}

/**
 * Adds a new key value pair to the environment variables.
 *
 * @param env_list The environment variables struct.
 * @param var The variable to add in "key=value" format.
 */
void	ft_util_env_var_add(t_env_list **env_list, char *var)
{
	t_env_list	*current;

	if (!var)
		return ;
	if (!*env_list)
		*env_list = ft_util_env_list(var);
	else
	{
		current = *env_list;
		while (current->next)
			current = current->next;
		current->next = ft_util_env_list(var);
	}
}

/**
 * Searches and returns a given value by key inside the environment
 * variables.
 *
 * @param env_list The environment variables struct.
 * @param key The key to look for.
 * @return The value of the key-value pair. If the specified key is
 * not present, NULL will be returned.
 */
char	*ft_util_env_get(t_env_list **env_list, const char *key)
{
	t_env_list	*current;

	if (env_list == NULL || key == NULL || *env_list == NULL)
		return (NULL);
	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->current->key, key, ft_strlen(key) + 1) == 0)
			return (current->current->value);
		current = current->next;
	}
	return (NULL);
}

void	ft_util_env_var_remove(t_env_list **env_list, const char *key)
{
	t_env_list	*current;
	t_env_list	*temp;

	if (env_list == NULL || *env_list == NULL || key == NULL)
		return ;
	current = *env_list;
	if (ft_strncmp(current->current->key, key, ft_strlen(key) + 1) == 0)
	{
		temp = current->next;
		ft_util_env_free(current);
		*env_list = temp;
	}
}
