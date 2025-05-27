/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:20:33 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 19:53:22 by ibour            ###   ########.fr       */
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

static void	ft_run_token_execute(t_shell *shell, const t_token *next)
{
	(void)next;
	if (shell->current_token)
		ft_run_cmd(shell, shell->current_token, shell->env_list,
			shell->current_cmds);
	if (next && next->type == TOKEN_DOBINP)
		ft_run_token_delete_temp(shell);
}

static void	ft_run_token_process(t_shell *shell, t_token *token)
{
	t_token	*prev;
	t_token	*next;
	int		process_level;

	if (!token)
	{
		printf("%s: syntax error near unexpected token `newline'\n",
			ft_util_env_get(&shell->env_list, "USER"));
		return ;
	}
	prev = ft_util_token_previous(token);
	next = ft_util_token_next(token);
	if (!prev && token && token->type != TOKEN_CMD)
		ft_run_token_process(shell, token->next);
	process_level = ft_util_redirect_level(shell, token, prev, shell->env_list);
	if (next && process_level != PROCESS_LEVEL_PARENT)
		ft_run_token_process(shell, next->next);
	if (process_level != PROCESS_LEVEL_PARENT && !shell->executed && (!prev
			|| prev->type == TOKEN_PIPE) && token->type == TOKEN_CMD && !errno)
	{
		if (process_level == PROCESS_LEVEL_CHILD)
			shell->executed = true;
		shell->current_token = token;
		ft_run_token_execute(shell, next);
	}
}

t_bool	ft_run_token(t_shell *shell, t_token *token, t_env_list *env_list,
		char **cmds)
{
	errno = 0;
	shell->process_level = PROCESS_LEVEL_PARENT;
	shell->executed = false;
	shell->env_list = env_list;
	shell->current_cmds = cmds;
	if (token)
		ft_run_token_process(shell, token);
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
