/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:48:58 by ibour             #+#    #+#             */
/*   Updated: 2025/03/26 17:03:55 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Bro this is the main function, what do you expect it to do?
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @param env The environment variables.
 * @return A specified status code related to the program.
 */
int	main(const int argc, char **argv, char **env)
{
	t_shell		shell;
	t_env_list	*env_list;

	(void) argc;
	(void) argv;
	void ft_util_banner(void);
	env_list = NULL;
	if (!ft_init_env(&shell, env_list, env))
		ft_error_throw(ERROR_INIT_ENV);
	if (!ft_init_temp(&shell))
		ft_error_throw(ERROR_INIT_TEMP);
	if (!ft_init_std(&shell))
		ft_error_throw(ERROR_INIT_STD);
	if (!ft_exit_std(&shell))
		ft_error_throw(ERROR_EXIT_STD);
	ft_exit_env(&env_list);
	return (shell.exit_status);
}
