/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:17:42 by mwelfrin          #+#    #+#             */
/*   Updated: 2025/04/23 15:17:58 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_cmd_cd(t_shell *shell, t_env_list **env_list, t_token *args)
{
	char	*path;

	if (!args || !args->str
		|| (args->str[0] == '~' && args->str[1] == '\0'))
		path = ft_util_env_get(env_list, "HOME");
	else if (args->next)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		shell->exit_status = STATUS_MAIN;
		return ;
	}
	else
		path = args->str;
	if (!path || chdir(path) != 0)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		shell->exit_status = STATUS_MAIN;
		return ;
	}
	shell->exit_status = STATUS_OK;
}
