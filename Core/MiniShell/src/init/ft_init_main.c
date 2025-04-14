/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:36:37 by ibour             #+#    #+#             */
/*   Updated: 2025/04/14 13:35:17 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Initializes the file descriptors by calling the dup() function
 * and assigning it to the shell struct.
 *
 * @param shell The main shell struct.
 * @return A boolean whether the action was performed or not.
 */
t_bool	ft_init_std(t_shell *shell)
{
	shell->std_in = dup(0);
	shell->std_out = dup(1);
	return (shell->std_in != -1 && shell->std_out != -1);
}

/**
 * Initializes all the environment variables passed from
 * the main function by parsing them.
 *
 * @param shell The main shell struct.
 * @param env_list The environment variables list.
 * @param env The environment variables passed from the environment.
 * @return A boolean whether the action was performed or not.
 */
t_bool	ft_init_env(t_shell *shell, t_env_list *env_list, char **env)
{
	printf("init env\n"); fflush(stdout);
	ft_parse_env(&env_list, env);
	if (ft_util_env_get(&env_list, "SHLVL"))
		shell->shlvl = ft_atoi(ft_util_env_get(&env_list, "SHLVL"));
	else
		shell->shlvl = SHLVL_DEFAULT;
	return (TRUE);
}

/**
 * Initializes the temporary file string.
 *
 * @param shell The main shell struct.
 * @return A boolean whether the action was performed or not.
 */
t_bool	ft_init_temp(t_shell *shell)
{
	shell->temp_file = ft_strjoin(TEMP_PATH, TEMP_FILE);
	return (shell->temp_file != NULL);
}
