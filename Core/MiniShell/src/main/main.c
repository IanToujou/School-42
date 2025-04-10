/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:48:58 by ibour             #+#    #+#             */
/*   Updated: 2025/04/09 17:30:38 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

volatile sig_atomic_t g_signal_status = 0;

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
	ft_memset(&shell, 0, sizeof(t_shell));
	ft_util_banner();
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
	ft_init_shell(&shell, env_list);
	
	return (shell.exit_status);
}

/**
 * Main shell execution loop to be improved.
 */
void ft_init_shell(t_shell *shell, t_env_list *env_list)
{
    while (1)
    {
        ft_echo_off();
        ft_set_sig();
        ft_init_shell_loop(shell, env_list);
    }
}

 
/**
 * Handles one complete cycle of shell operation.
 * Manages signal interrupts and updates shell status accordingly.
 * Reads user input, adds it to history, and prepares for execution.
 * Handles EOF (Ctrl+D) condition by exiting gracefully.
 * Parsing to be added (when)
 */
void ft_init_shell_loop(t_shell *shell, t_env_list *env_list)
{
	char		*buffer;

	if (g_signal_status == 130)
	{
		shell->exit_status = 130;
		g_signal_status = 0;
		rl_reset_line_state();
		return;
	}
	buffer = readline(PROMPT);
	if (!buffer)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit(shell->exit_status);
	}
	if(ft_strncmp(buffer, "exit", 4)==0)
		ft_handle_exit(shell, buffer);
	add_history(buffer);
	(void)shell; // Temporary placeholder until parsing implemented
	(void)env_list;
	//ft_parse(shell, env_list, buffer, PROMPT);
	free(buffer);
}
