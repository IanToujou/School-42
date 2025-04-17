/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:28:30 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 01:14:25 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_run_shell(t_shell *shell, t_env_list *env_list)
{
	char	*prompt;
	char	*buffer;
	char	*user;

	prompt = "kek";
	buffer = readline(prompt);
	if (!buffer) {
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		shell->is_running = FALSE;
		return ;
	}
	add_history(buffer);
	ft_parse_input(shell, env_list, buffer, "nya");
	free(buffer);
	free(prompt);
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
