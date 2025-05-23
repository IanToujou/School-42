/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:40:14 by ibour             #+#    #+#             */
/*   Updated: 2025/05/23 14:28:13 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_run_bin_token_length(const t_token *token)
{
	int	size;

	size = 1;
	while (token && token->type == TOKEN_ARG)
	{
		size++;
		token = token->next;
	}
	return (size);
}

static void	ft_run_bin_handle(t_shell *shell, const t_token *token,
		t_env_list *env_list)
{
	int		size;
	int		i;
	char	**args;

	if (token->type == TOKEN_CMD)
		ft_util_env_update_shlvl(shell, token, &env_list);
	size = ft_run_bin_token_length(token->next);
	args = (char **)malloc(sizeof(char *) * (size + 1));
	if (args == NULL)
		ft_error_throw(ERROR_MALLOC);
	i = -1;
	while (++i < size)
	{
		args[i] = ft_strtrim(token->str, " ");
		if (args[i] == NULL)
			ft_error_throw(ERROR_MALLOC);
		token = token->next;
	}
	args[size] = NULL;
	ft_util_launch_execve(env_list, args);
}

/**
 * @brief Executes a binary command in a new process.
 *
 * This function is responsible for executing binary commands. It creates a new
 * process using `fork` and then attempts to execute the binary specified by
 * the provided token structure in the child process. Signal handling and the
 * shell's process lifecycle are managed in this function.
 *
 * In the parent process, the function waits for the child process to complete
 * and retrieves the exit status. If the `fork` operation fails, an error is
 * thrown.
 *
 * @param shell A pointer to the shell structure, managing shell state and settings.
 * @param token A constant pointer to the token structure that represents the
 *        command and its arguments to be executed.
 * @param env_list A pointer to the linked list of environment variables used
 *        during the execution of the binary.
 */
void	ft_run_bin(t_shell *shell, const t_token *token, t_env_list *env_list)
{
	pid_t	pid;
	int		status;

	ft_util_bin_signal(token);
	pid = fork();
	if (pid == 0)
	{
		errno = 0;
		ft_run_bin_handle(shell, token, env_list);
	}
	else if (pid > 0)
	{
		status = 0;
		shell->pid = pid;
		waitpid(pid, &status, 0);
		shell->exit_status = WEXITSTATUS(status);
	}
	else
		ft_error_throw(ERROR_FORK);
}
