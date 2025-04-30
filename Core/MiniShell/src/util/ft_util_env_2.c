/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_env_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:13:07 by ibour             #+#    #+#             */
/*   Updated: 2025/04/30 19:42:35 by ibour            ###   ########.fr       */
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

void	ft_util_env_update_shlvl(t_shell *shell, const t_token *token, t_env_list **env_list)
{
	char	*line;
	char	*lvl;

	if (ft_strnstr(token->str, "minishell", ft_strlen(token->str)) != NULL)
	{
		shell->shlvl++;
		lvl = ft_itoa(shell->shlvl);
		if (lvl == NULL)
			ft_error_throw(ERROR_MALLOC);
		line = ft_strjoin("SHLVL=", ft_itoa(shell->shlvl));
		if (line == NULL)
			ft_error_throw(ERROR_MALLOC);
		ft_util_env_var_remove(env_list, "SHLVL");
		ft_util_env_var_add(env_list, line);
		free(line);
		free(lvl);
	}
}
