/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:28:30 by ibour             #+#    #+#             */
/*   Updated: 2025/04/17 13:33:48 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
 * Reads and processes user input in shell
 * Handles exit conditions and empty input
 * Maintains history and parses into tokens
 * TODO execute
 */
static void	ft_process_input(t_shell *shell, t_env_list *env_list, char *buffer)
{
	t_token	*tokens;

	if (buffer[0] != '\0')
	{
		add_history(buffer);
		tokens = ft_parse(shell, env_list, buffer);
		if (tokens)
		{
			// ft_execute(shell, env_list, tokens);
			ft_free_tokens(tokens);
		}
	}
}

/*
 * Runs the main shell loop
 * Reads input, checks for exit condition, and processes non-empty input
 * Calls `ft_process_input` to handle parsing and tokenization
 */
static void	ft_run_shell(t_shell *shell, t_env_list *env_list)
{
	char	*prompt;
	char	*buffer;

	prompt = (char *) ft_util_banner_prompt();
	buffer = readline(prompt);
	if (!buffer)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		shell->is_running = FALSE;
		return ;
	}
	if (ft_strncmp(buffer, "exit", 4) == 0)
	{
		ft_handle_exit(shell, env_list, buffer);
		shell->is_running = FALSE;
		free(buffer);
		return ;
	}
	ft_process_input(shell, env_list, buffer);
	free(buffer);
}

/**
 * Initializes the shell by setting the default values and
 * running it.
 *
 * @param env_list The environment variable list.
 * @param shell The main shell struct.
 */
void	ft_init_shell(t_env_list *env_list, t_shell *shell)
{
	shell->is_running = TRUE;
	shell->exit_status = STATUS_OK;
	while (shell->is_running)
	{
		ft_signal_mask();
		ft_signal_start();
		shell->pid = 0;
		shell->f_in = -1;
		shell->f_out = -1;
		shell->process_level = PROCESS_LEVEL_DEFAULT;
		ft_run_shell(shell, env_list);
		ft_signal_start();
	}
}
