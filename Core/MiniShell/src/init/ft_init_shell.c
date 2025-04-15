/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:28:30 by ibour             #+#    #+#             */
/*   Updated: 2025/04/15 10:32:48 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_run_shell(t_shell *shell, t_env_list *env_list)
{
	char	*buffer;

	buffer = readline(get_prompt());
	/*if (!buffer)
	{
		if (shell->is_interactive)
			ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit(shell->exit_status);
	}
	*/
	if (ft_strncmp(buffer, "exit", 4) == 0)
		ft_handle_exit(shell, buffer);
	//if (shell->is_interactive && buffer[0] != '\0')
	add_history(buffer);
	(void)shell; // Temporary placeholder until parsing implemented
	(void)env_list;
	// ft_parse(shell, env_list, buffer);
	free(buffer);
}

void	ft_init_shell(t_env_list *env_list, t_shell *shell)
{
	(void)env_list;
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
