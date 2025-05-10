/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:20:33 by ibour             #+#    #+#             */
/*   Updated: 2025/05/10 05:30:09 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_run_token_delete_temp(const t_shell *shell)
{
	pid_t	pid;
	char	**argv;

	argv = malloc(sizeof(char *) * 3);
	if (argv == NULL)
		ft_error_throw(ERROR_MALLOC);
	argv[0] = "/bin/rm";
	argv[1] = shell->temp_file;
	argv[2] = NULL;
	pid = fork();
	if (pid == 0)
	{
		errno = 0;
		execve("/bin/rm", argv, NULL);
	}
	else if (pid > 0)
		free(argv);
	else
		ft_error_throw(ERROR_FORK);
}

static void	ft_run_token_execute(t_shell *shell, t_token *token,
		const t_token *next, t_env_list *env_list)
{
	(void)next;
	if (token)
		ft_run_cmd(shell, token, env_list);
	if (next && next->type == TOKEN_DOBINP)
		ft_run_token_delete_temp(shell);
}

static void	ft_run_token_process(t_shell *shell, t_token *token,
		t_env_list *env_list)
{
	t_token	*prev;
	t_token	*next;
	int		process_level;

	printf("TOKEN IS: %p\n", token);
	prev = ft_util_token_previous(token);
	next = ft_util_token_next(token);
	if (!prev && token && token->type != TOKEN_CMD)
		ft_run_token_process(shell, token->next, env_list);
	process_level = ft_util_redirect_level(shell, token, prev, env_list);
	if (next && process_level != PROCESS_LEVEL_PARENT)
		ft_run_token_process(shell, next->next, env_list);
	printf("Before\n"); fflush(stdout);
	printf("process level is: %d\n", process_level); fflush(stdout);
	printf("shell->executed is: %d\n", shell->executed); fflush(stdout);
	printf("token is %p\n", token); fflush(stdout);
	printf("token->type is %d\n", token->type); fflush(stdout);
	printf("prev is: %p\n", prev); fflush(stdout);
	if (process_level != PROCESS_LEVEL_PARENT && !shell->executed // todo fix
		&& (!prev || prev->type == TOKEN_PIPE)
		&& token->type == TOKEN_CMD && !errno)
	{
		if (process_level == PROCESS_LEVEL_CHILD)
			shell->executed = true;
		ft_run_token_execute(shell, token, next, env_list);
	}
}

t_bool	ft_run_token(t_shell *shell, t_token *token, t_env_list *env_list)
{
	errno = 0;
	shell->process_level = PROCESS_LEVEL_PARENT;
	shell->executed = false;
	if (token)
		ft_run_token_process(shell, token, env_list);
	if (shell->f_in != -1 && close(shell->f_in) == -1)
		ft_error_throw(ERROR_EXIT_STD);
	if (shell->f_out != -1 && close(shell->f_out) == -1)
		ft_error_throw(ERROR_EXIT_STD);
	if (dup2(shell->std_in, STDIN_FILENO) == -1)
		ft_error_throw(ERROR_INIT_STD);
	if (dup2(shell->std_out, STDOUT_FILENO) == -1)
		ft_error_throw(ERROR_INIT_STD);
	while (wait(NULL) > 0)
		;
	if (shell->process_level == PROCESS_LEVEL_CHILD)
		exit(shell->exit_status);
	return (TRUE);
}
