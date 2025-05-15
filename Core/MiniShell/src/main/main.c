/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:48:58 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 11:56:39 by ibour            ###   ########.fr       */
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

	(void)argc;
	(void)argv;
	env_list = NULL;
	if (!ft_init_env(&shell, &env_list, env))
		ft_error_throw(ERROR_INIT_ENV);
	if (!ft_init_temp(&shell))
		ft_error_throw(ERROR_INIT_TEMP);
	if (!ft_init_std(&shell))
		ft_error_throw(ERROR_INIT_STD);
	shell.is_interactive = (isatty(fileno(stdin)) && argc == 1);
	if (shell.is_interactive)
		ft_run_interactive_shell(env_list, &shell);
	else
		ft_run_non_interactive_shell(env_list, &shell);
	if (!ft_exit_std(&shell))
		ft_error_throw(ERROR_EXIT_STD);
	ft_exit_env(&env_list);
	ft_exit_temp(&shell);
	return (shell.exit_status);
}
