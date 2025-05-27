/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:28:30 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 19:52:26 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_run_shell(t_shell *shell, t_env_list *env_list)
{
	char	*prompt;
	char	*buffer;
	char	*user;

	user = ft_util_env_get(&env_list, "USER");
	prompt = ft_util_prompt(env_list);
	buffer = readline(prompt);
	free(prompt);
	if (!buffer)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		shell->is_running = FALSE;
		return ;
	}
	add_history(buffer);
	ft_parse_input(shell, env_list, buffer, user);
	free(buffer);
}

/**
 * Initializes the shell by setting the default values and
 * running it.
 *
 * @param env_list The environment variable list.
 * @param shell The main shell struct.
 */
void	ft_run_interactive_shell(t_env_list *env_list, t_shell *shell)
{
	shell->is_running = TRUE;
	shell->is_interactive = TRUE;
	shell->exit_status = STATUS_OK;
	ft_util_banner_intro();
	while (shell->is_running)
	{
		ft_signal_mask(shell);
		ft_signal_start(shell);
		shell->pid = 0;
		shell->f_in = -1;
		shell->f_out = -1;
		shell->pipe_count = 0;
		shell->process_level = PROCESS_LEVEL_DEFAULT;
		ft_run_shell(shell, env_list);
		ft_signal_start(shell);
	}
}

void	ft_run_non_interactive_shell(t_env_list *env_list, t_shell *shell)
{
	char	*input;
	char	*user;

	shell->is_running = TRUE;
	shell->is_interactive = FALSE;
	ft_signal_start(shell);
	ft_signal_mask(shell);
	if (!ft_init_std(shell))
	{
		shell->exit_status = 1;
		shell->is_running = FALSE;
		return ;
	}
	user = ft_util_env_get(&env_list, "USER");
	input = ft_read_all_stdin();
	if (!input)
	{
		shell->is_running = FALSE;
		shell->exit_status = 0;
		return ;
	}
	if (!ft_parse_input(shell, env_list, input, user))
		shell->exit_status = 1;
	free(input);
	shell->is_running = FALSE;
}

char	*ft_read_all_stdin(void)
{
	char	buffer[1024];
	char	*result;
	char	*tmp;
	ssize_t	bytes;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	bytes = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		tmp = ft_strjoin(result, buffer);
		free(result);
		if (!tmp)
			return (NULL);
		result = tmp;
	}
	if (bytes < 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
