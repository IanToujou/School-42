/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:47:10 by ibour             #+#    #+#             */
/*   Updated: 2025/05/27 11:06:33 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	ft_parse_handle_exit(char **cmd, t_shell *shell, t_bool status)
{
	int		i;

	i = -1;
	if (cmd)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
	}
	if (status)
		return (true);
	shell->exit_status = STATUS_MALLOC;
	return (false);
}

static char **ft_split_command(const char *cmd)
{
	char **args;
	char *trimmed;

	// Trim whitespace from the command
	trimmed = ft_strtrim(cmd, " \t\n\r");
	if (!trimmed)
		return NULL;

	// Split the trimmed command into arguments
	args = ft_split(trimmed, ' ');
	free(trimmed);

	return args;
}

static t_bool ft_handle_piped_commands(t_shell *shell, char **cmds, t_env_list *env_list, int pipe_count)
{
    int i = 0;
    int cmd_count = pipe_count + 1; // Number of commands is 1 more than number of pipes
    pid_t pid;
    int fd[2][2]; // We need two pipes for alternating
    int current_pipe = 0;
    char **args;

    // Create the first pipe
    if (pipe(fd[0]) == -1)
        return (false);

    // Loop through all commands in the pipeline
    for (i = 0; i < cmd_count; i++) {
        // If not the last command, create a new pipe for the next command
        if (i < cmd_count - 1) {
            if (pipe(fd[1 - current_pipe]) == -1) {
                // Clean up pipes and return error
                close(fd[current_pipe][0]);
                close(fd[current_pipe][1]);
                return (false);
            }
        }

        // Fork a process for this command
        pid = fork();
        if (pid == -1) {
            // Handle fork error
            return (false);
        }

        if (pid == 0) {
            // Child process

            // If not the first command, read from the previous pipe
            if (i > 0) {
                dup2(fd[current_pipe][0], STDIN_FILENO);
                close(fd[current_pipe][0]);
                close(fd[current_pipe][1]);
            }

            // If not the last command, write to the next pipe
            if (i < cmd_count - 1) {
                dup2(fd[1 - current_pipe][1], STDOUT_FILENO);
                close(fd[1 - current_pipe][0]);
                close(fd[1 - current_pipe][1]);
            }

            // Split the command into arguments
            args = ft_split_command(cmds[i]);
            if (!args || !args[0]) {
                exit(EXIT_FAILURE);
            }

            // Create token for this command (just the first word, not the whole command)
            t_token *token = ft_util_token_create(shell, args[0]);
            if (token == NULL) {
                ft_util_cmd_free(args);
                exit(EXIT_FAILURE);
            }

            // Set token type
            token->type = TOKEN_CMD;

            // Execute the command
            shell->current_cmds = args; // Set the arguments for the command
            ft_run_cmd(shell, token, env_list, args);

            // Free token and exit
            free(token);
            ft_util_cmd_free(args);
            exit(shell->exit_status);
        }

        // Parent process

        // Close the previous pipe after child has duplicated it
        if (i > 0) {
            close(fd[current_pipe][0]);
            close(fd[current_pipe][1]);
        }
        current_pipe = 1 - current_pipe;
    }

    // Close the last pipe
    close(fd[current_pipe][0]);
    close(fd[current_pipe][1]);

    for (i = 0; i < cmd_count; i++) {
        wait(NULL);
    }

    return (true);
}

static t_bool	ft_parse_handle_process(t_shell *shell, t_parse *parse,
		t_env_list *env_list, char *str)
{
	char **cmd;
	int pipe_count;

	// Save the pipe count for later use
	pipe_count = parse->pipe;

	// Get the command array (splitting at pipes if needed)
	cmd = ft_util_cmd_split(env_list, str, parse, shell);
	if (cmd == NULL && parse->flag == false)
		return (false);

	// Only update begin_str (starting position for next command)
	parse->begin_str = parse->i + 1;

	if (parse->flag == true)
		return (true);

	// If we have pipes, handle them specially
	if (pipe_count > 0) {
		if (ft_handle_piped_commands(shell, cmd, env_list, pipe_count) == false)
			return (ft_parse_handle_exit(cmd, shell, false));
	} else {
		// Normal command (no pipes)
		if (ft_util_token_process(shell, cmd, env_list) == false)
			return (ft_parse_handle_exit(cmd, shell, false));
	}
	parse->pipe = 0;

	return (ft_parse_handle_exit(cmd, shell, true));
}

t_bool	ft_parse_handle(t_shell *shell, t_env_list *env_list, char *str)
{
	t_parse	data;

	data = ft_init_parse_data();
	while (str[data.i])
	{
		ft_util_quote_status(&data.quotes, str[data.i]);
		if (str[data.i] == '\0' || (str[data.i] == ';'
				&& ft_util_quote_is_outside(&data.quotes) == TRUE)
			|| str[data.i + 1] == '\0')
		{
			data.flag = FALSE;
			if (ft_parse_handle_process(shell, &data, env_list, str) == FALSE)
				return (FALSE);
		}
		if (str[data.i] == '|'
			&& ft_util_quote_is_outside(&data.quotes) == TRUE)
			data.pipe++;
		if (str[data.i] == '\\' && data.quotes.two == TRUE)
			data.i += 2;
		else if (str[data.i] != '\0')
			data.i++;
	}
	return (TRUE);
}
