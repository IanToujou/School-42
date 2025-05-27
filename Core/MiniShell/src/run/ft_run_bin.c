/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:40:14 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 11:45:42 by ibour            ###   ########.fr       */
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

static void ft_run_bin_handle_piped(t_shell *shell, const t_token *token,
		t_env_list *env_list)
{
	int     size;
	int     i;
	char    **args;

	if (token->type == TOKEN_CMD)
		ft_util_env_update_shlvl(shell, token, &env_list);

	// Check if we already have parsed arguments in shell->current_cmds
	if (shell->current_cmds != NULL) {
		// We're in a pipe, use the already parsed arguments
		args = shell->current_cmds;
		printf("Using pre-parsed arguments in pipe: %s\n", args[0]);
		for (i = 0; args[i]; i++) {
			printf("  Arg[%d]: %s\n", i, args[i]);
		}
		fflush(stdout);
	} else {
		// We're not in a pipe, parse arguments from token list
		size = ft_run_bin_token_length(token->next);
		args = (char **)malloc(sizeof(char *) * (size + 1));
		if (args == NULL)
			ft_error_throw(ERROR_MALLOC);

		i = -1;
		const t_token *current = token;
		while (++i < size) {
			args[i] = ft_strtrim(current->str, " ");
			if (args[i] == NULL)
				ft_error_throw(ERROR_MALLOC);
			current = current->next;
		}
		args[size] = NULL;
	}

	// Launch the command with appropriate arguments
	ft_util_launch_execve(env_list, args);

	// If we allocated the args array, we should free it
	if (shell->current_cmds == NULL) {
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
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
 * @param shell A pointer to the shell structure,
	managing shell state and settings.
 * @param token A constant pointer to the token structure that represents the
 *        command and its arguments to be executed.
 * @param env_list A pointer to the linked list of environment variables used
 *        during the execution of the binary.
 */
void	ft_run_bin(t_shell *shell, const t_token *token, t_env_list *env_list, int pipe_count)
{
	pid_t	pid;
	int		status;

	ft_util_bin_signal(token);
	pid = fork();
	if (pid == 0)
	{
		errno = 0;
		if (pipe_count > 0)
			ft_run_bin_handle_piped(shell, token, env_list);
		else
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
