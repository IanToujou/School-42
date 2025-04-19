/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:28:30 by ibour             #+#    #+#             */
/*   Updated: 2025/04/19 13:33:53 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_run_shell(t_shell *shell, t_env_list *env_list)
{
	char	*prompt_pre;
	char	*prompt_full;
	char	*buffer;
	char	*user;

	user = ft_util_env_get(&env_list, "USER");
	if (user)
		prompt_pre = ft_strjoin(ft_util_banner_prompt_pre(), user);
	else
		prompt_pre = ft_strjoin(ft_util_banner_prompt_pre(), "nya");
	if (prompt_pre == NULL)
		ft_error_throw(ERROR_MALLOC);
	prompt_full = ft_strjoin(prompt_pre, ft_util_banner_prompt_post());
	buffer = readline(prompt_full);
	if (!buffer)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		shell->is_running = FALSE;
		return ;
	}
	add_history(buffer);
	ft_parse_input(shell, env_list, buffer, user);
	free(buffer);
	free(prompt_full);
	free(prompt_pre);
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
	ft_util_banner_intro();
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
