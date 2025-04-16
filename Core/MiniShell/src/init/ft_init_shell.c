/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:28:30 by ibour             #+#    #+#             */
/*   Updated: 2025/04/16 21:57:56 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_run_shell(t_shell *shell, t_env_list *env_list)
{
	char	*buffer;

	buffer = readline(get_prompt());
	if (!buffer)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		shell->is_running = FALSE;
		return ;
	}
	if (ft_strncmp(buffer, "exit", 4) == 0)
	{
		ft_handle_exit(shell, buffer);
		shell->is_running = FALSE;
		return ;
	}
	if (buffer[0] != '\0')
		add_history(buffer);
	(void)shell;
	(void)env_list;
	// ft_parse(shell, env_list, buffer);
	free(buffer);
}

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
